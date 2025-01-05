from tkinter import *

root = Tk()
root.title("Led")

def Send_Signal(sig):
    if sig == 'on':
        root.configure(bg='red')
    elif sig == 'off':
        root.configure(bg='white')

button_on = Button(root, text="on", bg="green", fg="white", padx=20, pady=10,command=lambda: Send_Signal('on'))
button_off = Button(root, text="off", bg="red", padx=20, pady=10,command=lambda: Send_Signal('off'))

button_on.pack(padx=20, pady=10)
button_off.pack(padx=20, pady=10)

root.mainloop()



