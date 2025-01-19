#include "Server.hpp"

Server::Server() : serverSockFD(-1), clientSockFD(-1) {
    memset(buffer, 0, sizeof(buffer));
}

Server::~Server() {
    CloseClientSocket();
    CloseServerSocket();
}

bool Server::CreateSocket() {
    serverSockFD = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSockFD <= 0) {
        std::cerr << "Cannot create socket" << std::endl;
        return false;
    }
    return true;
}

bool Server::Bind(int port) {
    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    if (bind(serverSockFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Failed to bind TCP socket. Exiting..." << std::endl;
        return false;
    }
    return true;
}

bool Server::Listen(int backlog) {
    if (listen(serverSockFD, backlog) == -1) {
        std::cerr << "Failed to listen on TCP socket. Exiting..." << std::endl;
        return false;
    }
    return true;
}

bool Server::AcceptConnection() {
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);
    clientSockFD = accept(serverSockFD, (struct sockaddr *)&clientAddress, &clientAddressLen);
    if (clientSockFD == -1) {
        std::cerr << "Failed to accept incoming TCP connection." << std::endl;
        return false;
    }
    std::cout << "Client connected with socket FD: " << clientSockFD << std::endl;
    return true;
}

void Server::SendDataToClient(const std::string &message) {
    int bytes_sent = send(clientSockFD, message.c_str(), message.size(), 0);
    std::cout << "sent message: " << message << std::endl;

    if(bytes_sent == -1){
        std::cerr << "failed to send" << std::endl;
        //return -1;
    }
    //return true;
}

std::string Server::ReceiveDataFromClient() {
    if (clientSockFD == -1) {
        return "ERROR: No client connected";
    }

    ssize_t bytesRead = recv(clientSockFD, buffer, sizeof(buffer), 0);
    if (bytesRead < 0) {
        std::cerr << "Error, data not received" << std::endl;
        return "ERROR";
    } else if (bytesRead == 0) {
        std::cerr << "Client closed the connection" << std::endl;
        return "CLOSED";
    }

    std::string receivedData(buffer, bytesRead);
    Trim(receivedData); // Trim whitespace
    return receivedData;
}

void Server::CloseClientSocket() {
    if (clientSockFD != -1) {
        close(clientSockFD);
        clientSockFD = -1;
    }
}

void Server::CloseServerSocket() {
    if (serverSockFD != -1) {
        close(serverSockFD);
        serverSockFD = -1;
    }
}

void Server::Trim(std::string &str) {
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}