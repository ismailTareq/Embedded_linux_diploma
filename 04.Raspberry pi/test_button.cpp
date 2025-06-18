#include <wiringPi.h>
#include <iostream>

using namespace std;

#define BUTTON_PIN 29  // WiringPi pin 4 corresponds to GPIO 23
#define LED_PIN 0     // WiringPi pin 0 corresponds to GPIO 17

void setup() {
    // Initialize WiringPi
    if (wiringPiSetup() == -1) {
        cerr << "Error initializing WiringPi" << endl;
        exit(1);
    }

    // Set up the button pin as input with a pull-up resistor
    pinMode(BUTTON_PIN, INPUT);
    pullUpDnControl(BUTTON_PIN, PUD_UP);

    // Set up the LED pin as output
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // Read the button state
    int buttonState = digitalRead(BUTTON_PIN);

    // Check if the button is pressed (LOW)
    if (buttonState == LOW) {
        // Turn on the LED
        digitalWrite(LED_PIN, HIGH);
        cout << "Button pressed. LED turned ON." << endl;
    } else {
        // Turn off the LED
        digitalWrite(LED_PIN, LOW);
        cout << "Button not pressed. LED turned OFF." << endl;
    }

    // Small delay to debounce the button
    delay(200);
}

int main() {
    setup();
    while (true) {
        loop();
    }
    return 0;
}
