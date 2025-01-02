import requests

x=requests.get('https://api.ipify.org/?format=json')
print(x.json())


x=requests.get(' https://ipinfo.io/156.192.247.109/geo')
print(x.json())
