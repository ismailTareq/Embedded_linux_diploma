#!/usr/bin/python3
'''
name = "ismail tarek"
print(name.capitalize())
name = "ISMAIL Tarek"
print(name.casefold())
name = "ISMAIL Tarek"
print(name.lower())
name = "ISMAIL"
print(name.center(14))
print(name.center(14,"-"))
print(name.count('I'))

name  = "ISMAIL"
enc = name.encode('utf-8')
print(enc)
print(type(enc))
dec = enc.decode('utf-8')
print(dec)
print(type(dec))

name = "ismail tarek"
print(name.startswith("ismail"))
print(name.endswith("tarEk"))

print(name.find("s"))
print(name.find("s",2))
print(name.find("tarek"))

name = " ismail tarek "
print(name.strip())

name = " ismail tarek "
print(name.replace("i","e"))

name = "ismail takre elsayed"
print(name.split(" "))
print(name.split(" ")[1])

age = 30
name = "ismail"

x = "name {} and age {} ".format(name,age)
print(x)
x = f"name {name} and age {age} "
print(x)
x = "name {0} and age {1}".format(name,age)
print(x)
x = "name %s and age %d"%(name,age)
print(x)

names = ["hi","iam","ismail"]
print(" ".join(names))

def func():
    print("ismail is here")

func();

def func(name):
    print(f"{name} is here")

func("7amo");

def func(child3,child2,child1):
    print("the child1 is " + child1)
    print("the child1 is " + child2)
    print("the child1 is " + child3)

func("ismail",child2="jomana",child1="safia")

def func(country = "Egypt"):
    print("Iam from " + country)

func("sweden")
func("gboty")
func()

def func(arg):
    for x in arg:
        print(x)
list1 = ["apple","kiwi","banana"]
tuple1 = (1,"ismail",3.5)

func(list1)
func(tuple1)

def func(*arg):
    print(type(arg))
    print(arg[0])
    print(arg[1])
    print(arg[2])

func(1,"ismail",3.5)

def func(**arg):
    print(type(arg))
    print(arg["name"])
    print(arg["age"])
    print(arg["email"])
dic = {"name":"ismail","age":25, "email":"ismailelghawas12@gmail.com"}
func(name = "ismail",age = "25", email = "ismailelghawas12@gmail.com")
func(**dic)

x =55
def func():
    global x
    x = 77
    print(x)
    print(id(x))
func()
print(x)
print(id(x))

ls = [1,2,3,4,5,6,7,8,9]

print(list(filter(lambda x:x%2==0,ls)))

import calc

print(calc.sum(5,5))

import calc as c
print(c.sum(5,5))


ls = [1,2,3,4,5,6,"ismail","zain","safia"]

ls.append("jomana")
print(ls)
ls2 = ls.copy()
ls.append("7amza")
print(ls)
print(ls2)
ls.extend([1,2,3,4])
print(ls)
ls.insert(2,"akram")
print(ls)
'''
fruits = ("apple","banana","cherry","kiwi","zink")
(green,long,*fruit) = fruits
print(green)
print(long)
print(type(fruit))
print(fruit)





