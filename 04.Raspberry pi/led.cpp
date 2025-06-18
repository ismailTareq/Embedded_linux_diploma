#include <wiringPi.h>
#include <iostream>

#define LED_PIN 0 // GPIO17 (WiringPi pin 0)

int main() {
    // Initialize WiringPi
    if (wiringPiSetup() == -1) {
        std::cerr << "Failed to initialize WiringPi" << std::endl;
        return 1;
    }

    // Set LED_PIN as output
    pinMode(LED_PIN, OUTPUT);

    std::cout << "Blinking LED. Press Ctrl+C to stop." << std::endl;

    while (true) {
        digitalWrite(LED_PIN, HIGH); // Turn LED on
        delay(500);                 // Wait 500ms
        digitalWrite(LED_PIN, LOW); // Turn LED off
        delay(500);                 // Wait 500ms
    }

    return 0;
}
