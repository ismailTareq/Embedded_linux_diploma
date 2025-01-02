import speech_recognition as sr
import pyttsx3
import webbrowser
from datetime import datetime
from time import sleep
import wikipedia
import pywhatkit
import calendar  

def Listen_to_User():

    rec = sr.Recognizer()

    # properly opened and closed
    # Reading Microphone as source
    # listening the speech and store in audio_text variable
    with sr.Microphone() as source:
        print("Listening.....")
        audio = rec.listen(source)
    try:
        CMD = rec.recognize_google(audio,language = 'en')
        print(f"you said {CMD}")
        #to make sure it goes to the write command
        return CMD.lower()
    except sr.UnknownValueError:
        print("Speech Recognition could not understand audio")
        return ""
    
def Respond_Voice(Respones):
    TTS = pyttsx3.init()
    
    # Slowing down the speech rate
    rate = TTS.getProperty('rate')   # Getting current speech rate
    TTS.setProperty('rate', rate - 80) # Reducing the rate by 80 units

    TTS.say(Respones)
    TTS.runAndWait()

def User_greating():
    cur_time = datetime.now().strftime("%H")
    if cur_time < "12":
        response = "Good morning Ismail."
    elif cur_time < "18":
        response = "Good afternoon Ismail."
    else:
        response = "Good Evening Ismail."
    Respond_Voice(response)

def Get_time_now():
    return datetime.now().strftime("%H:%M:%S")

def Get_date():
    now = datetime.now()
    month = calendar.month_name[now.month]
    return f"{now.strftime('%A')} {now.day} {month} {now.year}"

def get_wikipedia_summary(command):
    search_query = command.replace('tell me ', '')
    response = wikipedia.summary(search_query, sentences=1)
    try:
        response = wikipedia.summary(search_query, sentences=1)

    except wikipedia.exceptions.DisambiguationError as e:
        response = f"Multiple options found. {str(e)}"
    except wikipedia.exceptions.PageError as e:
        response = f"No information found. {str(e)}"
    return response
def play_song(command):
    #to remove any white spaces
    song_name = command.replace('play', '').strip()
    try:
        pywhatkit.playonyt(song_name)
        response = f"Playing {song_name} on YouTube."
    except Exception as e:
        response = f"Failed to play {song_name}: {str(e)}"

    print(response)
    return response 

def main():
    User_greating()
    
    CMD = Listen_to_User()

    if 'google' in CMD:
        webbrowser.open("https://gemini.google.com/app")
        response = "opening google."
        Respond_Voice(response)
    elif 'tell me about' in CMD:
        response = get_wikipedia_summary(CMD)
        Respond_Voice(response)
    elif 'date' in CMD:
        response = Get_date()
        Respond_Voice(response)
    elif 'time' in CMD:
        response = Get_time_now()
        Respond_Voice(response)
    elif 'play' in CMD:
        response = play_song(CMD)
        Respond_Voice(response)

if __name__ == "__main__":
    main()



    

