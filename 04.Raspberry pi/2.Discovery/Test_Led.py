from gpiozero import LED
from time import sleep

led = LED(17)

try:
    while True:
        x=input("enter on | off")
        if x == "on":
            led.on()
        elif x == "off":
            led.off()
except KeyboardInterrupt:
    print("Program exited cleanly")
