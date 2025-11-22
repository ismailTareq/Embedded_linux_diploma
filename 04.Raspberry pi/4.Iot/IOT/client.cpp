#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <atomic>

class ChatClient {
private:
    int sock;
    std::string username;
    std::atomic<bool> running{true};
    
public:
    ChatClient(const std::string& server_ip, int port, const std::string& name) 
        : username(name) {
        
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            throw std::runtime_error("Socket creation failed");
        }
        
        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        
        if (inet_pton(AF_INET, server_ip.c_str(), &serv_addr.sin_addr) <= 0) {
            throw std::runtime_error("Invalid address");
        }
        
        std::cout << "🔗 Connecting to chat server..." << std::endl;
        
        if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
            throw std::runtime_error("Connection failed");
        }
        
        // Send username to server
        send(sock, username.c_str(), username.length(), 0);
    }
    
    void start() {
        std::cout << "✅ Connected to chat room as: " << username << std::endl;
        std::cout << "💬 Start chatting! (type 'exit' to leave)" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        
        std::thread receiver(&ChatClient::receiveMessages, this);
        
        sendMessages();
        
        running = false;
        receiver.join();
    }
    
private:
    void receiveMessages() {
        char buffer[1024] = {0};
        
        while (running) {
            memset(buffer, 0, sizeof(buffer));
            int valread = read(sock, buffer, sizeof(buffer) - 1);
            
            if (valread > 0) {
                buffer[valread] = '\0';
                std::cout << "\r" << buffer << std::endl; // \r to clear current line
                std::cout << "You: " << std::flush;
            } else if (valread == 0) {
                std::cout << "\r❌ Disconnected from server" << std::endl;
                running = false;
                break;
            }
        }
    }
    
    void sendMessages() {
        std::string message;
        
        while (running) {
            std::cout << "You: ";
            std::getline(std::cin, message);
            
            if (message == "exit") {
                running = false;
                break;
            }
            
            if (!message.empty()) {
                send(sock, message.c_str(), message.length(), 0);
            }
        }
    }
    
public:
    ~ChatClient() {
        if (sock > 0) {
            close(sock);
            std::cout << "🔌 Disconnected from chat" << std::endl;
        }
    }
};

int main(int argc, char* argv[]) {
    std::cout << "=== 💬 Chat Room Client ===" << std::endl;
    
    std::string server_ip = "192.168.1.19"; 
    int port = 8080;
    std::string username = "User";
    
    if (argc > 1) {
        server_ip = argv[1];
    }
    if (argc > 2) {
        port = std::stoi(argv[2]);
    }
    if (argc > 3) {
        username = argv[3];
    } else {
        std::cout << "Enter your username: ";
        std::getline(std::cin, username);
    }
    
    try {
        ChatClient client(server_ip, port, username);
        client.start();
        
    } catch (const std::exception& e) {
        std::cerr << "❌ Client error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}