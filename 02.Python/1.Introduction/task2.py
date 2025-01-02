import math as m
import pyfiglet as pf


print(pf.figlet_format("task 2"))

radius = float(input("enter the radius of circle: "))
print("Area:" ,round(m.pi * m.pow(radius,2),4))



