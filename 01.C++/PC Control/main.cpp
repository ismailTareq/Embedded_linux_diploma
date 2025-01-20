#include "Server.hpp"
#include "Commands.hpp"
#include <iostream>

int main() {
    Server server;
    Command CMD;
    std::string Buffer;
    std::string Buffer1;
    std::string MSG;
    // Create the server socket
    if (!server.CreateSocket()) {
        return 1;
    }

    // Bind the server socket to port 8080
    if (!server.Bind(8080)) {
        return 1;
    }

    // Start listening for incoming connections
    if (!server.Listen()) {
        return 1;
    }

    std::cout << "Server is listening on port 8080..." << std::endl;

    // Accept a client connection
    if (!server.AcceptConnection()) {
        return 1;
    }

    std::cout << "Client connected!" << std::endl;

    // Communicate with the client
    while (true) 
    {
        server.SendDataToClient("Enter command to Execute:\n");
        while(true)
        {
            Buffer = server.ReceiveDataFromClient();
            std::cout << Buffer << std::endl;
            if(Buffer == "exit")
            {
                server.CloseClientSocket();
                server.CloseServerSocket();
                break;
            }
            else if (Buffer == "terminal")
            {
                server.SendDataToClient("Enter command to Execute on terminal:\n");
                Buffer = server.ReceiveDataFromClient();
                MSG = CMD.openTerminal(Buffer);
                std::cout << MSG << std::endl;
            }
            else if(Buffer == "calculator")
            {
                server.SendDataToClient("opening calculator");
                MSG = CMD.openCalculator();
                std::cout << MSG << std::endl;
            }
            else if (Buffer == "open vscode") 
            {
                server.SendDataToClient("opening VScode");
                MSG = CMD.openVScode();
                std::cout << MSG << std::endl;
            }
            else if (Buffer == "open camera") 
            {
                server.SendDataToClient("opening camera");
                MSG = CMD.openCamera();
                std::cout << MSG << std::endl;
            }
            else if (Buffer == "take a photo") 
            {
                server.SendDataToClient("Say cheeseee");
                MSG = CMD.Takephoto();
                std::cout << MSG << std::endl;
            }
            else if (Buffer == "open a folder")
            {
                server.SendDataToClient("Enter folder PATH:\n");
                Buffer = server.ReceiveDataFromClient();
                MSG = CMD.openFolder(Buffer);
                std::cout << MSG << std::endl;
            }
            else if (Buffer == "file") 
            {
                server.SendDataToClient("what would you like to do: \nyou can CREATE A FILE | COPY A FILE | DELETE A FILE\n");
                Buffer = server.ReceiveDataFromClient();
                if (Buffer == "create")
                {
                    server.SendDataToClient("Name the file:\n");
                    Buffer = server.ReceiveDataFromClient();
                    CMD.createFile(Buffer);
                    break;
                }
                else if (Buffer == "copy")
                {
                    server.SendDataToClient("Enter the source file:\n");
                    Buffer = server.ReceiveDataFromClient();
                    server.SendDataToClient("Enter the destination file:\n");
                    Buffer1 = server.ReceiveDataFromClient();
                    CMD.copyFile(Buffer, Buffer1);
                    break;
                } 
                else if (Buffer == "delete")
                {
                    server.SendDataToClient("Name the file:\n");
                    Buffer = server.ReceiveDataFromClient();
                    CMD.deleteFile(Buffer);
                    break;
                }  
                
            }
            else if (Buffer == "shutdown") 
            {
                MSG = CMD.shutdown();
                std::cout << MSG << std::endl;
            }
            else if (Buffer == "restart") 
            {
                MSG = CMD.Restart();
                std::cout << MSG << std::endl;
            }

            else if (Buffer == "open youtube")
            {
                server.SendDataToClient("what do you want to watch:\n");
                Buffer = server.ReceiveDataFromClient();
                MSG =  CMD.youtube(Buffer);
                std::cout << MSG << std::endl;
            }
            else if (Buffer == "open linkedin")
            {
                MSG = CMD.linkedin();
                std::cout << MSG << std::endl;
            }
            else if (Buffer == "open github")
            {
                MSG = CMD.github();
                std::cout << MSG << std::endl;
            }
            else if ((Buffer == "search for")||(Buffer == "search"))
            {
                server.SendDataToClient("what do you want to search for:\n");
                Buffer = server.ReceiveDataFromClient();
                MSG = CMD.openBrowser(Buffer);
                std::cout << MSG << std::endl;
            }
            else
            {
                server.SendDataToClient("Invalid command please enter the supported commands!!");
                continue;
            }
            break;
        }
        if (Buffer == "exit")
        {
            break;
        }
    }

    server.CloseClientSocket();
    server.CloseServerSocket();

    return 0;
}