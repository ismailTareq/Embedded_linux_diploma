import Adafruit_DHT
import time

# Define the sensor type and GPIO pin
sensor = Adafruit_DHT.DHT11
pin = 17  # GPIO pin number (BCM numbering)

def read_sensor():
    humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)
    if humidity is not None and temperature is not None:
        print(f"Temperature: {temperature:.1f}°C")
        print(f"Humidity: {humidity:.1f}%")
    else:
        print("Failed to read from DHT11 sensor. Try again.")

if __name__ == "__main__":
    while True:
        read_sensor()
        time.sleep(2)  # Wait for 2 seconds before reading again
