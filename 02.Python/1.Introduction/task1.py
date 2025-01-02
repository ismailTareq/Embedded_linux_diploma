import pyfiglet as pf
import os
'''
print(pf.figlet_format("task 1 a"))
while True:
    try:
        data = input("enter list separated by commas: ")
        num = input("enter the number to search for in list: ")

        List = [i.strip() for i in data.split(',')]
        print(f"number{num} is counted: ",List.count(num))
        break
    except KeyboardInterrupt:
        print("\nprogrram terminated by user")
        break

while True:
    print(pf.figlet_format("task 1 b"))
    character = input("enter the character: ")
    print("vowel") if character in ['a','e','i','o','u'] else print("not vowel")
'''
print(pf.figlet_format("task 1 c"))
#print(os.environ["PATH"])
#print(os.environ.get('PATH'))
#print(os.getcwd()) #get the current directory
#for key,value in os.environ.items(): #get all enviroment variables
#    print(f"{key}: {value}")

#get specific enviroment variables
def get_Enviroment(vars):
    v = os.environ[vars]
    return f"{vars}: {v}"
vars = ['HOME','PATH','USER','SHELL']

for i in vars:
    print(get_Enviroment(i))
