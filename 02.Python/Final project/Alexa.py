from gtts import gTTS
import asyncio
import speech_recognition as sr
from datetime import datetime
import os
import calendar 
import webbrowser
from time import sleep
import pyautogui
import requests
import pywhatkit 
import pygame
import random
from datetime import date
import pyjokes
import plyer 
import schedule
from googletrans import Translator

my_lang = "en"  # Set language to English

def Listening(lang = my_lang):
    #Listens for and recognizes speech using speech_recognition.
    rec = sr.Recognizer()
    try:
        with sr.Microphone() as mic:
            print("am Listening...")
            #rec.adjust_for_ambient_noise(mic,duration=1)
            audio = rec.listen(mic)
            CMD = rec.recognize_google(audio,language = lang)
            print(CMD)
            return CMD

    except sr.UnknownValueError:
        print("Could not understand audio.")
        return ""
    except sr.RequestError as e:
        print(f"Could not request results from Google Speech Recognition service; {e}")
        return ""

def Speaking(text,lang = my_lang):
    speak = gTTS(text=text,lang=lang,slow=False)
    speak.save("welcome.mp3")

    pygame.mixer.init()
    pygame.mixer.music.load("welcome.mp3")
    pygame.mixer.music.play()

    while pygame.mixer.music.get_busy():
        pygame.time.Clock().tick(15)

    pygame.mixer.quit()
    os.remove("welcome.mp3")

def Alexa_greating():
    cur_time = datetime.now().strftime("%H")
    if cur_time < "12":
        response = "Good morning Ismail, how can i help you am all yours."
    elif cur_time < "18":
        response = "Good afternoon Ismail, how can i help you am all yours."
    else:
        response = "Good Evening Ismail, how can i help you am all yours."
    Speaking(response)

def Alexa_Get_time_now():
    Speaking (datetime.now().strftime("%H:%M:%S"))

def Alexa_Get_date():
    now = datetime.now()
    month = calendar.month_name[now.month]
    Speaking (f"today {now.strftime('%A')} {now.day} {month} {now.year}")

def Alexa_weather():
    api_key = "fae4e4336c31fe86cbbcc17161fec8e5"  # Replace with your actual API key
    city = "Alexandria" 
    url = f"http://api.openweathermap.org/data/2.5/weather?q={city}&appid={api_key}&units=metric"  # Use metric units

    try:
        response = requests.get(url)
        data = response.json()
        weather = data["weather"][0]["description"]
        temp = data["main"]["temp"]
        Humidity = data["main"]["humidity"]
        Speaking(f"The weather in {city} is {weather}. The temperature is {temp} degrees Celsius and the humidity is {Humidity}%.")
    except requests.exceptions.RequestException as e:
        Speaking(f"Error fetching weather data: {e}")

def Alexa_song():
    Speaking("whaat song would you like to listen to")
    song_name = Listening()
    try:
        pywhatkit.playonyt(song_name)
        response = f"Playing {song_name} on YouTube."
    except Exception as e:
        response = f"Failed to play {song_name}: {str(e)}"

    Speaking(response)

def Alexa_joke():
    Speaking("let me tell you a joke")
    jk = pyjokes.get_joke()
    Speaking(jk)



async def Alexa_Translate():
    Speaking("what would you like to translate to")
    while True:
        text = Listening()
        text = text.lower()
        if text == "arabic":
            translator = Translator() 
            Speaking("okay am listening")
            sentence = Listening('en')
            translate = await translator.translate(sentence, src='en', dest='ar')
            Speaking(translate.text,'ar')
            break
        elif text == "german":
            Speaking("okay am listening")
            translator = Translator() 
            sentence = Listening('en')
            translate = await translator.translate(sentence, src='en', dest='de')
            Speaking(translate.text,'de')
            break

def Alexa_google():
    Speaking("what would you like to Search for")
    text = Listening()
    url = f"https://www.google.com/search?q={text}"
    webbrowser.open(url)
    Speaking(f"Searching Google for: {text}")

def Take_screenshot():
    Speaking("taking a screenshot")
    image = pyautogui.screenshot()
    image.save("screenshot.png")
    Speaking("Screenshot taken")

def Alexa_WhoamI():
    response = "You Are Ismail an  Embedded Systems Engineer trying to be better"
    Speaking(response)

def Commit_on_github():
    Speaking("commiting to github")
    os.system("cd && cd Embedded_linux2024_diploma/02.Python/Final project/ && git add . && git commit -m \"Alexa Auto Comment\" && git push origin main ")
    webbrowser.open_new_tab("https://github.com/ismailTareq/Embedded_linux2024_diploma/tree/main/02.Python/Final%20project")

def Alexa_whatsapp():
    Speaking("whom would you like to send a message")
    number=""
    while not number.isnumeric():
        number = Listening()
        number=number.replace(" ","")
        if(number.isnumeric()):
            break
    if(number[0]!='0'):
        number = '0'+number
    Speaking("what would you like to send")
    message = Listening()
    pywhatkit.sendwhatmsg_instantly("+2"+number,message)
    while True:    
            try:
                pyautogui.locateOnScreen('mywhatsapp.png')
            except:
                print('image not found')
            else:
                print("image found")
                break    
    sleep(1)
    pyautogui.click(839,568)
    pyautogui.press('enter')
    Speaking("message sent")

def Alexa_writeFile():
    Speaking("what is the name of the file")
    file_name = Listening()
    Speaking("creating a file")
    file = open(f"{file_name}.txt","w")
    Speaking("what would you like to write")
    text = Listening()
    file.write(text)
    file.close()
    Speaking("file written")

def Alexa_readFile():
    Speaking("what is the name of the file")
    file_name = Listening()
    Speaking("reading the file")
    file = open(f"{file_name}.txt","r")
    text = file.read()
    Speaking(text)
    file.close()

def azantiming1():
    Speaking("what is the name of the city")
    city = Listening()
    url = f"https://www.islamicfinder.org/world/{city}-prayer-times/"
    webbrowser.open(url)
    Speaking(f"Showing prayer times for {city}")


def azantiming():
    api_endpoint = "https://api.aladhan.com/v1/timings"
    latitude = 30.14656  # Your latitude
    longitude = 31.39326  # Your long
    today = date.today().strftime("%Y-%m-%d")
    params = {
        "latitude": latitude,
        "longitude": longitude,
        "date": today,
    }
    response = requests.get(api_endpoint, params=params)
    data = response.json()
    Fajr = data["data"]["timings"]["Fajr"]
    Speaking(f"The Fajr prayer time is {Fajr}")
    Dhuhr = data["data"]["timings"]["Dhuhr"]
    Speaking(f"The Dhuhr prayer time is {Dhuhr}")
    Asr = data["data"]["timings"]["Asr"]
    Speaking(f"The Asr prayer time is {Asr}")
    Maghrib = data["data"]["timings"]["Maghrib"]
    Speaking(f"The Maghrib prayer time is {Maghrib}")
    Isha = data["data"]["timings"]["Isha"]
    Speaking(f"The Isha prayer time is {Isha}")


def Alexa_Email():
        response = "sending a email to ismail"
        Speaking(response)
        sleep(3)
        pyautogui.hotkey('win')
        sleep(3)
        pyautogui.write('outlook')
        sleep(2)
        pyautogui.press('enter')
        sleep(3)
        pyautogui.hotkey('ctrl', 'n')
        sleep(2)
        pyautogui.write('ismailelghawas12@gmail.com')
        pyautogui.press('tab')
        sleep(2)
        pyautogui.write('ismailelghawas12333@gmail.com')
        pyautogui.press('tab')
        sleep(2)
        pyautogui.write('python project')
        pyautogui.press('tab')
        sleep(2)
        pyautogui.write("hello ismail this is an email to let you know this function is working")
        pyautogui.moveTo(34, 249) 
        pyautogui.click()

def Alexa_notification():
    plyer.notification.notify(title="Reminder",message="good job ismail keep it up don't forget to drink water",timeout=60)
    schedule.every(5).seconds.do(Alexa_notification)
    Speaking("good job ismail keep it up")

schedule.every(60).seconds.do(Alexa_notification)

def Alexa_reminder():
    Speaking("what would you like me to remind you of")
    reminder = Listening()
    Speaking("when would you like me to remind you")
    time = Listening()
    Speaking("okay i will remind you")
    schedule.every().day.at(time).do(Alexa_notification)
    

def Search_for_words(words_list,search):
    for word in words_list:
        if word in search:
            return True

def Alexa_bye():
    response = "good bye if you want anything else don't hesitate"
    Speaking(response)

greeting = ["am here","what's up","yeah!","what's good bro","whaaaat!","yes dear","what's good my nigga"]

def Responses():
    
    
    status = True
    Alexa_greating()
    while status:
        me = Listening()
        me = me.lower()
        schedule.run_pending()
        if 'alexa' == me:
            Speaking(random.choice(greeting))
        elif Search_for_words(["who am i","who i am","tell me about myself"],me):
            Alexa_WhoamI()
        elif Search_for_words(["time","what's the time","what time is it"],me):
            Alexa_Get_time_now()
        elif Search_for_words(["tell me a joke","am sad","am upset","joke"],me):
            Alexa_joke()
        elif Search_for_words(["search","search about","i want information","search for me"],me):
            Alexa_google()
        elif Search_for_words(["weather","what is the weather","is it rainy","temprature"],me):
            Alexa_weather()
        elif Search_for_words(["song","play a song","play"],me):
            Alexa_song()
        elif Search_for_words(["send an email","email","email someone"],me):
            Alexa_Email()
        elif Search_for_words(["translate","i want to translate somthing"],me):
            asyncio.run(Alexa_Translate())
        elif Search_for_words(["close","bye","good night"],me):
            Alexa_bye()
        elif Search_for_words(["date","what's the date","what day is it","what day is it"],me):
            Alexa_Get_date()
        elif Search_for_words(["screenshot"],me):
            Take_screenshot()
        elif Search_for_words(["commit","push","push to github"],me):
            Commit_on_github()
        elif Search_for_words(["whatsapp","send a message","send a whatsapp message"],me):
            Alexa_whatsapp()
        elif Search_for_words(["create a file","write a file","write"],me):
            Alexa_writeFile()
        elif Search_for_words(["read a file","read"],me):
            Alexa_readFile()
        elif Search_for_words(["azan timing","prayer timing"],me):
            azantiming1()
        elif Search_for_words(["reminder","remind me","remind"],me):
            Alexa_reminder()
        else:
            Speaking("i didn't get that")
            continue

Responses()