#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

constexpr int TRUE = 1;
constexpr int FALSE = 0;
constexpr int BUFFER_SIZE = 1024;

int main()
{
    //create socket for the client
    int clientSockFD = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSockFD == -1) {
        std::cerr << "Failed to create a socket. Exiting..." << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Socket created successfully with FD: "<< clientSockFD << std::endl;
    }
    int option = TRUE;
    if(setsockopt(clientSockFD, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) == -1)
    {
        std::cerr << "Failed to set socket options. Exiting..." << std::endl;
        return -1;
    }
    struct sockaddr_in clientAddr;

    memset(&clientAddr, 0, sizeof(clientAddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    clientAddr.sin_port = htons(1984);

    if(bind(clientSockFD, (struct sockaddr *)&clientAddr, sizeof(clientAddr)) == -1)
    {
        std::cerr << "Failed to bind the socket to the port. Exiting..." << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Socket binded to the port successfully." << std::endl;
    }
    //Connect to the client
    if(listen(clientSockFD, 4) == 0)
    {
        std::cout << "Listening for incoming connections..." << std::endl;
    }
    else
    {
        std::cerr << "Failed to listen for incoming connections. Exiting..." << std::endl;
        return -1;
    }
    //Accept the incoming connection
    struct sockaddr_in connectedClientAddr;
    socklen_t client_len = sizeof(connectedClientAddr);
    while(1)
    {
        memset(&connectedClientAddr, 0, sizeof(connectedClientAddr));
        int connectedClientSockFD = accept(clientSockFD, (struct sockaddr *)&connectedClientAddr, (socklen_t *)&client_len);
        if(connectedClientSockFD == -1)
        {
            std::cerr << "Failed to accept the incoming connection. Exiting..." << std::endl;
            return -1;
        }
        else
        {
            std::cout << "Accepted the incoming connection." << std::endl;
        }

        pid_t PID = fork();
        if(PID == -1)
        {
            //failed to fork repeat
            close (connectedClientSockFD);
            continue;
        }

        if(PID == 0)
        {
            //child process so  close because the sub prosses will handle the send and receive only will not listten
            close(clientSockFD);
            char buffer[BUFFER_SIZE] = {0} ;
            while (1) 
            {
                //receive data from the client
                memset(buffer, 0, sizeof(buffer));
                recv(connectedClientSockFD, buffer, sizeof(buffer), 0);
                std::cout << "Data received from the client: " << buffer << std::endl;
                if(buffer[0] == 'q' && buffer[1] == '\0')
                {
                    std::cout << "Client disconnected." << std::endl;
                    close(connectedClientSockFD);
                    break;
                }
                else
                {
                     //send data to the client
                    send(connectedClientSockFD, buffer, strlen(buffer), 0);
                }
            }
            break;
            
        }
        else
        {
            //parent process close so i can receive another connection
            close(connectedClientSockFD);


        }
    }
    
    

    return 0;
}

