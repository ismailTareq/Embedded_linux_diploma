#include <gpiod.h>
#include <iostream>
#include <chrono>
#include <thread>

#define GPIO_PIN 4       // GPIO17 (Pin 11)
#define RETRIES 5         // Number of read attempts
#define TIMEOUT_US 200    // Timeout in microseconds

int main() {
    // Initialize GPIO
    auto* chip = gpiod_chip_open_by_name("gpiochip0");
    if (!chip) {
        std::cerr << "Failed to open GPIO chip" << std::endl;
        return 1;
    }

    auto* line = gpiod_chip_get_line(chip, GPIO_PIN);
    if (!line) {
        std::cerr << "Failed to get GPIO line" << std::endl;
        gpiod_chip_close(chip);
        return 1;
    }

    uint8_t data[5] = {0};
    bool success = false;

    for (int attempt = 0; attempt < RETRIES && !success; attempt++) {
        // Send start signal
        gpiod_line_request_output(line, "dht11", 0);
        gpiod_line_set_value(line, 0);
        std::this_thread::sleep_for(std::chrono::milliseconds(18));
        gpiod_line_set_value(line, 1);
        std::this_thread::sleep_for(std::chrono::microseconds(40));

        // Switch to input with pull-up
        gpiod_line_request_input_flags(line, "dht11", GPIOD_LINE_REQUEST_FLAG_BIAS_PULL_UP);

        // Wait for sensor response
        auto start = std::chrono::steady_clock::now();
        while (!gpiod_line_get_value(line)) {
            if (std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::steady_clock::now() - start).count() > TIMEOUT_US) {
                break;
            }
        }

        // Read 40 bits
        for (int i = 0; i < 40; i++) {
            start = std::chrono::steady_clock::now();
            while (gpiod_line_get_value(line)) {
                if (std::chrono::duration_cast<std::chrono::microseconds>(
                    std::chrono::steady_clock::now() - start).count() > TIMEOUT_US) {
                    break;
                }
            }

            start = std::chrono::steady_clock::now();
            while (!gpiod_line_get_value(line)) {
                if (std::chrono::duration_cast<std::chrono::microseconds>(
                    std::chrono::steady_clock::now() - start).count() > TIMEOUT_US) {
                    break;
                }
            }

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::steady_clock::now() - start).count();

            data[i/8] |= (duration > 40 ? 1 : 0) << (7 - (i % 8));
        }

        // Verify checksum (fixed parentheses)
        if (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) {
            std::cout << "Temperature: " << static_cast<int>(data[2]) << "°C | "
                      << "Humidity: " << static_cast<int>(data[0]) << "%" << std::endl;
            success = true;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    if (!success) {
        std::cerr << "Failed to read valid data after " << RETRIES << " attempts" << std::endl;
    }

    gpiod_line_release(line);
    gpiod_chip_close(chip);
    return 0;
}
