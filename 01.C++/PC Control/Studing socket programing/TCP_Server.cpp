#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    //create socket for the server
    int serverSockFD = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSockFD == -1) {
        std::cerr << "Failed to create a socket. Exiting..." << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Socket created successfully with FD: "<< serverSockFD << std::endl;
    }
    //bind this socket to a specific port
    struct sockaddr_in serverAddr;

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Bind to any available network interface
    serverAddr.sin_port = htons(8080);

    if(bind(serverSockFD, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        std::cerr << "Failed to bind the socket to the port. Exiting..." << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Socket binded to the port successfully." << std::endl;
    }

    //listen for incoming connections
    if(listen(serverSockFD, 1) == 0)
    {
        std::cout << "Listening for incoming connections..." << std::endl;
    }
    else
    {
        std::cerr << "Failed to listen for incoming connections. Exiting..." << std::endl;
        return -1;
    }
    //accept the incoming connection
    struct sockaddr_in connectedClientAddr;
    memset(&connectedClientAddr, 0, sizeof(connectedClientAddr));
    socklen_t client_len = sizeof(connectedClientAddr);
    int connectedClientSockFD = accept(serverSockFD, (struct sockaddr *)&connectedClientAddr, (socklen_t *)&client_len);
    if(connectedClientSockFD == -1)
    {
        std::cerr << "Failed to accept the incoming connection. Exiting..." << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Accepted the incoming connection." << std::endl;
    }

    //send or receive data from the client
    char buffer[1024] = {0} ;
    recv(connectedClientSockFD, buffer, sizeof(buffer), 0);
    std::cout << "Data received from the client: " << buffer << std::endl;

    //close sockets
    close(connectedClientSockFD);
    close(serverSockFD);

    return 0;
}