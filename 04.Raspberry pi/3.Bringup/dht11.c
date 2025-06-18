#include <wiringPi.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define DHT11_PIN 0 // GPIO pin where DHT11 is connected

int readDHT11(int *data) {
    int lastState = HIGH;
    int counter = 0;
    int j = 0;

    // Send start signal
    pinMode(DHT11_PIN, OUTPUT);
    digitalWrite(DHT11_PIN, LOW);
    delay(18);
    digitalWrite(DHT11_PIN, HIGH);
    delayMicroseconds(40);
    pinMode(DHT11_PIN, INPUT);

    // Read data
    for (int i = 0; i < 85; i++) {
        counter = 0;
        while (digitalRead(DHT11_PIN) == lastState) {
            counter++;
            delayMicroseconds(1);
            if (counter == 255) break;
        }
        lastState = digitalRead(DHT11_PIN);

        if (counter == 255) break;

        // Skip the first 3 transitions
        if ((i >= 4) && (i % 2 == 0)) {
            data[j / 8] <<= 1;
            if (counter > 16) data[j / 8] |= 1;
            j++;
        }
    }

    // Verify checksum
    if (j >= 40 && (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF))) {
        return 1; // Success
    } else {
        return 0; // Failure
    }
}

int main(void) {
    int data[5] = {0};

    if (wiringPiSetup() == -1) {
        fprintf(stderr, "WiringPi initialization failed!\n");
        return 1;
    }

    printf("Reading DHT11 sensor...\n");

    if (readDHT11(data)) {
        printf("Humidity: %d.%d%%\n", data[0], data[1]);
        printf("Temperature: %d.%d°C\n", data[2], data[3]);
    } else {
        fprintf(stderr, "Failed to read from DHT11 sensor.\n");
    }

    return 0;
}
