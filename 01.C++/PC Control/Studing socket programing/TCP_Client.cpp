#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

constexpr int BUFFER_SIZE = 1024;

int main() 
{
    // Create socket for the client
    int clientSockFD = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSockFD == -1) {
        std::cerr << "Failed to create a socket. Exiting..." << std::endl;
        return -1;
    } else {
        std::cout << "Socket created successfully with FD: " << clientSockFD << std::endl;
    }

    // Define server address
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported. Exiting..." << std::endl;
        return -1;
    }

    // Connect to the server
    if (connect(clientSockFD, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Failed to connect to the server. Exiting..." << std::endl;
        return -1;
    } else {
        std::cout << "Connected to the server successfully." << std::endl;
    }

    // Send data to the server
    char buffer[BUFFER_SIZE] = "Hello from the client!";
    send(clientSockFD, buffer, strlen(buffer), 0);

    // Receive data from the server
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytesRead = recv(clientSockFD, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
        std::cerr << "Failed to receive data from the server. Exiting..." << std::endl;
    } else {
        std::cout << "Data received from the server: " << buffer << std::endl;
    }

    // Close the socket
    close(clientSockFD);
    return 0;
}
