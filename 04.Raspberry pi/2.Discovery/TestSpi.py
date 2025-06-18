import spidev
import time

# Set SPI bus and device
spi_bus = 0
spi_device = 0

# Open SPI connection with mode 0
spi = spidev.SpiDev()
spi.open(spi_bus, spi_device)
spi.max_speed_hz = 50000  # You may need to adjust the speed based on your setup
spi.mode = 0  # Set SPI mode to 0 (CPOL=0, CPHA=0)

# Define the data to be sent
data_to_send = "niggas"

# Convert string to list of ASCII values
ascii_values = [ord(char) for char in data_to_send]

try:
    # Send data
    spi.xfer2(ascii_values)
    print("Data sent successfully")

finally:
    # Close SPI connection
    spi.close()

