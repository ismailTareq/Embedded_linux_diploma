#include <fcntl.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main() {
    const char *device_path = "/dev/input/event1"; // Replace X with the correct number
    int fd = open(device_path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening input device");
        return EXIT_FAILURE;
    }

    struct input_event ev;
    ssize_t bytesRead;
    while ((bytesRead = read(fd, &ev, sizeof(struct input_event))) > 0) {
        if (ev.type == EV_KEY) {
            printf("Key event: code=%d, value=%d, time=%ld\n", ev.code, ev.value, (long)ev.time.tv_sec);
        }
    }
    if (bytesRead == -1) {
        perror("Error reading input event");
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);

    return EXIT_SUCCESS;
}
