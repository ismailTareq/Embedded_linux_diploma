#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#define SPI_DEVICE "/dev/spidev0.0"

void pabort(const char *s)
{
    perror(s);
    abort();
}

int main(void)
{
    int fd;
    uint8_t mode = SPI_MODE_0;
    uint8_t bits = 8;
    uint32_t speed = 50000;

    // Open SPI device
    if ((fd = open(SPI_DEVICE, O_RDWR)) < 0)
        pabort("can't open SPI device");

    // Set SPI mode
    if (ioctl(fd, SPI_IOC_WR_MODE, &mode) == -1)
        pabort("can't set SPI mode");

    // Set bits per word
    if (ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits) == -1)
        pabort("can't set bits per word");

    // Set max speed
    if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) == -1)
        pabort("can't set max speed hz");

    // Data to be sent
    char data_to_send[] = "ismail is here bitchs";
    int length = strlen(data_to_send);

    // Prepare SPI transfer structure
    struct spi_ioc_transfer transfer = {
        .tx_buf = (unsigned long)data_to_send,
        .len = length,
        .speed_hz = speed,
        .bits_per_word = bits,
    };

    // Perform SPI transfer
    if (ioctl(fd, SPI_IOC_MESSAGE(1), &transfer) < 0)
        pabort("can't send spi message");


    // Close SPI device
    close(fd);

    return 0;
}


