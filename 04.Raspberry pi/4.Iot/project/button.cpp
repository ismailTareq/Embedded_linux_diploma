#include <iostream>
#include <wiringPi.h>

#define BUTTON_PIN 0  // GPIO pin number (BCM) connected to the button

int main() {
    // Initialize WiringPi
    if (wiringPiSetup() == -1) {
        std::cerr << "Failed to initialize WiringPi" << std::endl;
        return 1;
    }

    // Set the button pin as an input
    pinMode(BUTTON_PIN, INPUT);

    // Enable the internal pull-up resistor
    pullUpDnControl(BUTTON_PIN, PUD_UP);

    std::cout << "Button checker started. Press Ctrl+C to exit." << std::endl;

    while (true) {
        // Read the button state
        int buttonState = digitalRead(BUTTON_PIN);

        if (buttonState == LOW) {
            std::cout << "Button is pressed!" << std::endl;
        } else {
            std::cout << "Button is not pressed." << std::endl;
        }

        // Delay for a short period to avoid flooding the console
        delay(500);
    }

    return 0;
}
