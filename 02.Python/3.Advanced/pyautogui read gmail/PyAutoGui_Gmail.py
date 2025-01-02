import pyautogui
import webbrowser
from time import sleep

url = "https://mail.google.com/mail/u/1/#inbox"

webbrowser.open(url,new=2)
sleep(10)
try:
    location = None
    while location is None:
        location = pyautogui.locateOnScreen('search.png')
        sleep(1)
        pyautogui.click(location.left+15,location.top+10)
        sleep(1)
        pyautogui.typewrite('label:')
        pyautogui.typewrite('unread')
        sleep(1)
        pyautogui.click(location.left,location.top)
        sleep(5)
        location2 = pyautogui.locateOnScreen('select.png')
        sleep(1)
        pyautogui.click(location2.left+15,location2.top+5)
        sleep(2)
        pyautogui.click(location2.left+215,location2.top+5)

except pyautogui.ImageNotFoundException:
    print("Image not found")