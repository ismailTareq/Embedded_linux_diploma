#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

constexpr int buffer = 50;

void Write(int sock,char *buf);
void Read(int sock,char *buf);


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
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1984);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(clientSockFD,(struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        std::cerr << "Failed to connect to the server. Exiting..." << std::endl;
        return -1;
    }
    else
    {
        
        std::cout << "Connected to the server successfully." << std::endl;
    }
    char buffer[buffer];
    pid_t PID = fork();
    if(PID == 0)
    {
        //chiled process
        Write(clientSockFD,buffer);
    }
    else
    {
        //parent process
        Read(clientSockFD,buffer);
    }



    return 0;
}
void Write(int sock,char *buf)
{
    while(1)
    {
        std::cin.getline(buf, sizeof(buf));
        send(sock, buf, sizeof(buf), 0);
        if(buf[0] == 'q' && buf[1] == '\0')
        {
            std::cout << "Disconnected from the server." << std::endl;
            close(sock);
            return;
        }
        memset(buf, 0, buffer);
    }
}
void Read(int sock,char *buf)
{
    while(1)
    {
        if(buf[0] == 'q' && buf[1] == '\0')
        {
            //std::cout << "Disconnected from the server." << std::endl;
            close(sock);
            return;
        }
        recv(sock, buf, buffer, 0);
        std::cout << "Data received from the server: " << buf << std::endl;
        memset(buf, 0, buffer);
        break;
    }
}