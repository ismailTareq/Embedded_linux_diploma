from tkinter import *
from tkinter import messagebox

root = Tk()
root.geometry("300x300+300+450")
root.title("factorial")

var = IntVar()

def Factorial():
    num = var.get()
    fact = 1
    for i in range(1,num+1):
        fact *= i
    messagebox.showinfo("Factorial Result", f"The factorial of {num} is {fact}")


Label(root,text="Enter the number ").grid(row=0)

Entry(root,bg="white",textvariable=var).grid(row=0,column=1)

Button(root,text="Click here",command=Factorial).grid(row=1,column=1)

root.mainloop()
