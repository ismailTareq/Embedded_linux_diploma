from tkinter import *
import threading
import timer


'''
root = tkinter.Tk()
root.title("ismail's GUI")
root.geometry("300x300+300+450")
#root.configure(background="red")
'''
'''
tkinter.Label(root,text="ismail",bg="black",fg="red").pack(pady=10)
tkinter.Label(root,text="safia",bg="black",fg="red").pack(pady=10)
tkinter.Label(root,text="jomana",bg="black",fg="red").pack(pady=10)
tkinter.Label(root,text="tarek",bg="black",fg="red").pack(pady=10)
'''
'''
tkinter.Label(root,text="ismail",bg="black",fg="red").place(x=10)
tkinter.Label(root,text="safia",bg="black",fg="red").place(x=30)
tkinter.Label(root,text="jomana",bg="black",fg="red").place(x=50)
tkinter.Label(root,text="tarek",bg="black",fg="red").place(x=70)
'''
'''
tkinter.Label(root,text="ismail",bg="black",fg="red").grid(row=0)
tkinter.Label(root,text="safia",bg="black",fg="red").grid(row=1)
tkinter.Label(root,text="jomana",bg="black",fg="red").grid(row=2)
'''
'''
tkinter.Label(root,text="ismail",bg="black",fg="red").pack(pady=10)
tkinter.Button(root,command=root.destroy,text="close").pack(pady=50)


root.mainloop()
'''
'''
root = Tk()
root.title("ismail's GUI")
root.geometry("300x300+300+450")
frame = Frame(root)
frame.pack()

BTNframe = Frame(root)
Red_button = Button(frame,text="red",fg='red')
Red_button.pack(side= LEFT)

Green_button = Button(frame,text="green",fg='red')
Green_button.pack(side= LEFT)

Blue_button = Button(frame,text="blue",fg='red')
Blue_button.pack(side= LEFT)

BTNframe = Frame(root)
BTNframe.pack(side=BOTTOM)

Yellow_button = Button(BTNframe,text="yellow",fg='red')
Yellow_button.pack(side= BOTTOM)


root.mainloop()
'''
'''
def BTN_Handler():
    print(f"you sent {var.get()}")
    var.set("")

root = Tk()
root.title("ismail's GUI")
root.geometry("300x300+300+450")
var = StringVar()
frame = Frame(root,bg="brown",border=5,relief=SOLID)
frame.pack(expand=True,fill="both",side="left")


entry = Entry(frame,font=("arial",10,"bold"),bd = 5,textvariable= var)
button = Button(frame,text="send",fg='red',command=BTN_Handler)
button.pack()
entry.pack()
root.mainloop()
'''
'''
def items_selected(event):
    index = lb.curselection()
    print(index)
    print(lb.get(index))

root = Tk()
root.title("ismail's GUI")
root.geometry("300x300+300+450")

lb = Listbox()
lb.insert(1,"python")
lb.insert(2,"c")
lb.insert(3,"c++")

lb.pack()
lb.bind('<<ListboxSelect>>',items_selected)
root.mainloop()
'''
'''
root = Tk()
root.title("ismail's GUI")
root.geometry("300x300+300+450")
var = IntVar()

Radiobutton(root,text="c",value=1,variable=var).pack()
Radiobutton(root,text="c++",value=2,variable=var).pack()
button = Button(root,text="send",fg='red',command=lambda:print(var.get()))
button.pack()
root.mainloop()
'''
'''
root = Tk()
root.title("ismail's GUI")
root.geometry("300x300+300+450")

var = IntVar()

Radiobutton(root,text="c",value=1,variable=var).pack()
Radiobutton(root,text="c++",value=2,variable=var).pack()

def show():
    global t
    print(var.get())
    if var.get() == 1:
        print("c")
    elif var.get() == 2:
        print("c++")
    
    t = threading.Timer(1,show)
    t.start()

threading.Timer(1,show).start()

try:
    root.mainloop()
    t.cancel()
except:
    exit()
'''
'''
root = Tk()
root.title("ismail's GUI")
root.geometry("300x300+300+450")

var = IntVar()

def show():
    global t
    print(var.get())
    t = threading.Timer(1,show)
    t.start()

threading.Timer(1,show).start()
Scale(root,from_=0,to=100,variable=var).pack()
try:
    root.mainloop()
    t.cancel()
except:
    exit()
'''
'''
root = Tk()
root.title("ismail's GUI")
root.geometry("300x300+300+450")

var = IntVar()

def show():
    global t
    print(text.get("1.0",END))
    t = threading.Timer(0.5,show)
    t.start()
text = Text(root)
threading.Timer(0.5,show).start()
text.pack()
try:
    root.mainloop()
    t.cancel()
except:
    exit()
'''
'''
root = Tk()
root.title("ismail's GUI")
root.geometry("300x300+300+450")

def NewWindow():
    new = Toplevel(root)
    new.title("the new window")
    root.geometry("300x300+300+450")
    Label(new,text="ismail is here",bg="black",fg="red").pack()

btn = Button(root,text="open new window",fg='red',command=NewWindow)
btn.pack()
root.mainloop()
'''


