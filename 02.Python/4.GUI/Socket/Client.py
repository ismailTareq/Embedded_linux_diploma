import socket

client = socket.socket(socket.AF_INET ,socket.SOCK_STREAM)

client.connect(("127.0.0.1",65432))

msg = str(input("enter message you want to send: "))
msg1 = msg.encode('UTF-8')
client.send(msg1)

data = client.recv(1024)
print(f"127.0.0.1 is sending this message {data.decode('UTF-8')}")
client.close()
