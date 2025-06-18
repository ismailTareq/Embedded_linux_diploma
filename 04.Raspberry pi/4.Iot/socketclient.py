import socket

def run_client(server_host='127.0.0.1', server_port=1234):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((server_host, server_port))
        
        message = "Hello from client\n"
        s.sendall(message.encode())
        print(f"Sent: {message}")
        
        data = s.recv(1024)
        print(f"Received: {data.decode()}")

if __name__ == "__main__":
    run_client()
