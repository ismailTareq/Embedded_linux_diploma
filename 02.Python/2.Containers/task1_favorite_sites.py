import webbrowser 

dic = {
    "1":'https://www.facebook.com/',
    "2":'https://web.whatsapp.com/',
    "3":'https://www.youtube.com/',
    "4":'https://github.com/',
    "5":'https://www.gmail.com/'
}

def brave(url):
    webbrowser.open_new_tab(url)

while True:
    print("Enter the number of the website you will use:")
    print("1 - Facebook")
    print("2 - WhatsApp")
    print("3 - YouTube")
    print("4 - github")
    print("5 - gmail")

    x = input("enter ur choice")

    url = dic.get(x)
    brave(url)
