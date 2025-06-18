import requests

url=requests.get("http://192.168.1.20:8000/test.txt")
print(url.text)
