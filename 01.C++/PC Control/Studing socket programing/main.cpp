#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

constexpr int BUFFER_SIZE = 1024;
constexpr int PORT = 8080;

void handle_tcp_client(int clientSockFD) 
{
    char buffer[BUFFER_SIZE];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        ssize_t bytesRead = recv(clientSockFD, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) {
            std::cout << "Client disconnected or error receiving data." << std::endl;
            break;
        }
        std::cout << "TCP Data received: " << buffer << std::endl;
        send(clientSockFD, buffer, bytesRead, 0);
    }
    close(clientSockFD);
}

int main() 
{
    // Create a socket
    int TCPSockFD = socket(AF_INET, SOCK_STREAM, 0);
    if (TCPSockFD == -1) {
        std::cerr << "Failed to create TCP socket. Exiting..." << std::endl;
        return -1;
    }

    int option = 1;
    setsockopt(TCPSockFD, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    // Bind
    struct sockaddr_in ServerAddress;
    memset(&ServerAddress, 0, sizeof(ServerAddress));
    ServerAddress.sin_addr.s_addr = INADDR_ANY;
    ServerAddress.sin_family = AF_INET;
    ServerAddress.sin_port = htons(PORT);
    if (bind(TCPSockFD, (struct sockaddr *)&ServerAddress, sizeof(ServerAddress)) == -1) {
        std::cerr << "Failed to bind TCP socket. Exiting..." << std::endl;
        return -1;
    }

    // Listen
    if (listen(TCPSockFD, 5) == -1) {
        std::cerr << "Failed to listen on TCP socket. Exiting..." << std::endl;
        return -1;
    }
    std::cout << "TCP server listening on port " << PORT << "..." << std::endl;

    while (true) {
        // Accept a new connection
        struct sockaddr_in ClientAddress;
        socklen_t ClientAddressLen = sizeof(ClientAddress);
        int clientSockFD = accept(TCPSockFD, (struct sockaddr *)&ClientAddress, &ClientAddressLen);
        if (clientSockFD == -1) {
            std::cerr << "Failed to accept incoming TCP connection." << std::endl;
            continue;
        }
        std::cout << "Accepted TCP connection from client." << std::endl;

        // Handle the client
        handle_tcp_client(clientSockFD);

        std::cout << "Client disconnected. Waiting for a new connection..." << std::endl;
    }

    // Close the listening socket
    close(TCPSockFD);
    return 0;
}