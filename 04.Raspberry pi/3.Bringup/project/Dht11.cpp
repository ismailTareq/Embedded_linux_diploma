#include <wiringPi.h>
#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>

#define DHT11_PIN 0 // GPIO pin where DHT11 is connected
#define LEDPIN 1   // GPIO pin for LED

using namespace std;

vector<int> readDHT11() {
    vector<int> data(5, 0);
    uint8_t lastState = HIGH;
    uint8_t counter = 0;
    uint8_t j = 0;

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
        return data;
    } else {
        return vector<int>(); // Return empty vector on failure
    }
}

void blinkLed() {
    digitalWrite(LEDPIN, HIGH);
    this_thread::sleep_for(chrono::milliseconds(300));
    digitalWrite(LEDPIN, LOW);
}

int main() {
    if (wiringPiSetup() == -1) {
        cerr << "WiringPi initialization failed!" << endl;
        return 1;
    }

    pinMode(LEDPIN, OUTPUT);

    ofstream csvfile;
    csvfile.open("sensor_data.csv", ios::out);
    csvfile << "Timestamp,Temperature,Humidity\n";
    csvfile.close();

    while (true) {
        vector<int> data = readDHT11();
        if (!data.empty()) {
            float humidity = data[0] + data[1] / 10.0;
            float temperature = data[2] + data[3] / 10.0;

            time_t now = time(nullptr);
            char* dt = ctime(&now);

            // Append to CSV
            csvfile.open("sensor_data.csv", ios::app);
            csvfile << dt << "," << temperature << "," << humidity << "\n";
            csvfile.close();

            blinkLed();
        } else {
            cerr << "Failed to read from DHT11 sensor." << endl;
        }

        this_thread::sleep_for(chrono::seconds(10));
    }

    return 0;
}
