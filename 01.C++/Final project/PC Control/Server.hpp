#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <algorithm>
#include <string>

class Server {
public:
    Server();
    ~Server();

    bool CreateSocket();
    bool Bind(int port);
    bool Listen(int backlog = 5);
    bool AcceptConnection();
    void SendDataToClient(const std::string &message);
    std::string ReceiveDataFromClient();
    void CloseClientSocket();
    void CloseServerSocket();
    void Trim(std::string &str);

private:
    int serverSockFD; // Listening socket file descriptor
    int clientSockFD; // Client socket file descriptor
    char buffer[1024]; // Buffer for receiving data
};

#endif // SERVER_HPP