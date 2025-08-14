#include <gpiod.hpp>
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    const std::string chipname = "gpiochip0";  // Default GPIO chip
    const unsigned int line_num = 17;          // GPIO17

    try {
        // Initialize GPIO
        auto chip = gpiod::chip(chipname);
        auto line = chip.get_line(line_num);
        line.request({ "led-gpio17", gpiod::line_request::DIRECTION_OUTPUT, 0 });

        // Turn ON (set high)
        line.set_value(1);
        std::cout << "GPIO17 ON" << std::endl;

        // Wait 5 seconds
        std::this_thread::sleep_for(std::chrono::seconds(5));

        // Turn OFF (set low)
        line.set_value(0);
        std::cout << "GPIO17 OFF" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "GPIO error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
