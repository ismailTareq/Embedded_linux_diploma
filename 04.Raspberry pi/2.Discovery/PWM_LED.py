from gpiozero import PWMLED
from signal import pause
from time import sleep

led = PWMLED(12)

try:
    while True:
        for brightness in range(0, 101):
            led.value = brightness / 100.0
            sleep(0.01)
        
        for brightness in range(100, -1, -1):
            led.value = brightness / 100.0
            sleep(0.01)

except KeyboardInterrupt:
    # When Ctrl+C is pressed, exit the loop and clean up
    print("Exiting program.")

finally:
    # Ensure the LED is off when the program exits
    led.off()
