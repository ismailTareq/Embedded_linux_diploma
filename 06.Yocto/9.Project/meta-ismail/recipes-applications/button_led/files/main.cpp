/*
 * button-led.c  — GPIO toggle, C + libgpiod
 * LED = GPIO17, Button = GPIO27 (pull-up, active-low)
 */

#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

static void msleep(int ms)
{
    struct timespec ts = { .tv_sec = 0, .tv_nsec = ms * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

static void update_status(bool on)
{
    FILE *fp = fopen("/www/pages/status.txt", "w");
    if (fp) {
        fprintf(fp, "LED %s\n", on ? "ON" : "OFF");
        fclose(fp);
    }
}

int main(void)
{
    const unsigned int LED    = 17;
    const unsigned int BUTTON = 27;

    struct gpiod_chip *chip = gpiod_chip_open("/dev/gpiochip0");
    if (!chip) {
        perror("gpiod_chip_open");
        return 1;
    }

    struct gpiod_line *led_line = gpiod_chip_get_line(chip, LED);
    struct gpiod_line *btn_line = gpiod_chip_get_line(chip, BUTTON);

    if (gpiod_line_request_output(led_line, "button-led", 0) < 0) {
        perror("request LED");
        gpiod_chip_close(chip);
        return 1;
    }
    if (gpiod_line_request_input_flags(btn_line, "button-led",
                                       GPIOD_LINE_REQUEST_FLAG_BIAS_PULL_UP) < 0) {
        perror("request BUTTON");
        gpiod_chip_close(chip);
        return 1;
    }

    bool last  = gpiod_line_get_value(btn_line);
    bool state = false;

    puts("Press button on GPIO27 to toggle LED on GPIO17");

    while (1) {
        bool now = gpiod_line_get_value(btn_line);
        if (!now && last) {          // pressed (active-low)
            state = !state;
            gpiod_line_set_value(led_line, state);
            update_status(state);
            printf("LED %s\n", state ? "ON" : "OFF");
            msleep(200);             // crude debounce
        }
        last = now;
        msleep(30);
    }

    /* never reached */
    gpiod_chip_close(chip);
}
