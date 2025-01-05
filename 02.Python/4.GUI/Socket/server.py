import socket

soc = socket.socket(socket.AF_INET ,socket.SOCK_STREAM)

soc.bind(("127.0.0.1",65432))
soc.listen(10)

while True:
    client , address = soc.accept()
    data = client.recv(1024)
    print(f"{address} is sending this message {data.decode('UTF-8')}")
    msg = str(input("enter message you want to send: "))
    msg1 = msg.encode('UTF-8')
    client.send(msg1)
    client.close()
