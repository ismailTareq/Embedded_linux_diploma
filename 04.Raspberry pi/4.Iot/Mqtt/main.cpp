#include "publisher.hpp"
#include <iostream>
#include "wiringPi.h"
#include <thread>

#define BTN_PIN 0 // GPIO pin for the button


int main()
{
    mqtt::publisher Publisher;
    bool ledState = true;
    if(wiringPiSetup() == -1) {
        std::cerr << "Failed to initialize wiringPi" << std::endl;
        return 1;
    }
    pinMode(BTN_PIN, INPUT);
    pullUpDnControl(BTN_PIN, PUD_UP); // Enable pull-up resistor

    while(true) 
    {
        int buttonState = digitalRead(BTN_PIN);
        if(buttonState == LOW) 
        {
            std::cout << "Button pressed, toggling LED state." << std::endl;
            ledState = !ledState; // Toggle the LED state
            Publisher.TriggerLed(ledState); // Publish the new state
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Debounce delay
        } 
        else if(buttonState == HIGH) 
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Polling delay
        }

    }
    return 0;
}
