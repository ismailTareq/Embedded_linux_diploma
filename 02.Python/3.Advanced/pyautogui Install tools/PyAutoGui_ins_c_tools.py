import pyautogui as p
from time import sleep

sleep(3)
#print(p.position())

''''''
p.press('win')
#sleep(2)
p.write('vscode')
p.press('enter')
sleep(2)

try:
    loc = None
    while loc is None:
        loc = p.locateOnScreen('extenstion.png')
        sleep(2)
except p.ImageNotFoundException:
    print('ImageNotFoundException')
    exit()

p.click(loc.left,loc.top,duration=1)
p.moveTo(247,152)
sleep(2)
p.click()
p.write('clangd')
p.moveTo(228,211)
sleep(2)
p.click()
#p.moveTo(718,261)
#sleep(2)
#p.click()
sleep(2)
loc = p.locateOnScreen('Clangd.png')
if loc:
    x,y = p.center(loc)
    #print(x,y)
    p.click(x-87,y+40)



p.moveTo(247,152)
p.click()
p.hotkey('ctrl','a')
sleep(2)
p.press('delete')
sleep(3)
#p.click()
p.write('c++ testmate')
p.moveTo(228,211)
sleep(2)
p.click()
sleep(2)
loc = p.locateOnScreen('c++ testmate.png')
if loc:
    x,y = p.center(loc)
    #print(x,y)
    p.click(x-87,y+40)

p.moveTo(247,152)
p.click()
p.hotkey('ctrl','a')
sleep(2)
p.press('delete')
sleep(3)
#p.click()
p.write('c++ helper')
p.moveTo(228,211)
sleep(2)
p.click()
sleep(2)
loc = p.locateOnScreen('c++ helper.png')
if loc:
    x,y = p.center(loc)
    print(x,y)
    p.click(x-87,y+40)

p.moveTo(247,152)
p.click()
p.hotkey('ctrl','a')
sleep(2)
p.press('delete')
sleep(3)

p.write('cmake')
p.moveTo(228,211)
sleep(2)
p.click()

loc = p.locateOnScreen('cmake.png')
if loc:
    x,y = p.center(loc)
    p.click(x-101,y+35)

p.moveTo(235,287)
p.click()

loc = p.locateOnScreen('cmake tool.png')
if loc:
    x,y = p.center(loc)
    p.click(x-101,y+35)


