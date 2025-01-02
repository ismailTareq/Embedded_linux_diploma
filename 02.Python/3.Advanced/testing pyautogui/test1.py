import pyautogui as p
import time
#print(p.size())
#print(p.position())
#print(p.position())

#while True:
#    print(p.displayMousePosition())

#p.moveTo(0,0,duration=0)
#print(p.position())
#p.click(128,146,duration=0)
#p.dragTo(100,100,duration=4)

#p.scroll(1000)
'''
for i in range(10):
    p.moveTo(100,100,duration=0.25)
    p.moveTo(200,100,duration=0.25)
    p.moveTo(200,200,duration=0.25)
    p.moveTo(100,100,duration=0.25)
'''
#time.sleep(3)

#p.mouseUp(100,100,button="left")
#p.mouseDown(100,100,button="left")
'''
#example
p.mouseDown(300,400,button="left")
p.moveTo(800,400,3)
p.mouseUp()
p.moveTo(1000,400,3)
# project drawing
time.sleep(3)
distance = 300
while distance > 0:
    p.dragRel(distance,0,1,button="left")
    distance = distance - 20
    p.dragRel(0,distance,1,button="left")
    p.dragRel(-distance,0,1,button="left")
    distance = distance - 20
    p.dragRel(0,-distance,1,button="left")
time.sleep(2)

#tiktok liked
time.sleep(3)
#print(p.position())

for i in range(10):
    #p.moveTo(450,500)
    time.sleep(1)
    #p.doubleClick()
    #time.sleep(1)
    p.moveTo(645,415)
    time.sleep(1)
    p.leftClick()

time.sleep(2)

p.write("hello ismail")
p.press("enter")

#dino game
time.sleep(3)
for i in range(20):
    p.press("space")
    time.sleep(1)
'''
p.screenshot("screen.png")























































