from gpiozero import LED
import tkinter as gui

# Setup LED
led = LED(17)

def LED_Toggle():
    led.toggle()
    print("pressed")

# Main window
main_window = gui.Tk()
main_window.title("Control Led")
main_window.geometry("400x200+230+130")
main_window.resizable(False, False)
main_window.configure(background="white")

# Widgets
buttontoggle = gui.Button(main_window, text="LED ON/OFF",
                          command=LED_Toggle, bg="pink", fg="black")

# Places
buttontoggle.place(x=50, y=50)

main_window.mainloop()
