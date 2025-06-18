import socket

def run_server(host='127.0.0.1', port=1234):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((host, port))
        s.listen()
        print(f"Server listening on {host}:{port}")
        
        conn, addr = s.accept()
        with conn:
            print(f"Connected by {addr}")
            while True:
                data = conn.recv(1024)
                if not data:
                    break
                conn.sendall(data)  # Echo back the received data
                print(f"Received and sent back: {data.decode()}")

if __name__ == "__main__":
    run_server()
