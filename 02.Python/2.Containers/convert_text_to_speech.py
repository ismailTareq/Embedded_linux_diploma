from gtts import gTTS
import vlc  

text = 'hello ismail am proud of u'
lang = 'en'
slow = False

# Save audio in mp3 format
obj = gTTS(text=text, lang=lang, slow=slow)
obj.save("ismail.mp3")

# Play the audio using VLC
p = vlc.MediaPlayer("./ismail.mp3")
p.play()




