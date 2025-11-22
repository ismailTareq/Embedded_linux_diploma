#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>  // ⭐ ADD THIS HEADER ⭐

class ChatServer {
private:
    int server_fd;
    struct sockaddr_in address;
    std::vector<int> clients;
    std::mutex clients_mutex;
    
public:
    ChatServer(int port) {
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == 0) {
            throw std::runtime_error("Socket creation failed");
        }
        
        int opt = 1;
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
            throw std::runtime_error("Setsockopt failed");
        }
        
        address.sin_family = AF_INET;
        // address.sin_addr.s_addr = INADDR_ANY;
        inet_pton(AF_INET, "192.168.1.19", &address.sin_addr);
        address.sin_port = htons(port);
        
        if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            throw std::runtime_error("Bind failed");
        }
        
        if (listen(server_fd, 10) < 0) {
            throw std::runtime_error("Listen failed");
        }
        
        std::cout << "💬 Chat Server started on port " << port << std::endl;
        std::cout << "Clients can connect and see each other's messages!" << std::endl;
    }
    
    void start() {
        while (true) {
            std::cout << "⏳ Waiting for clients..." << std::endl;
            
            int client_socket = accept(server_fd, nullptr, nullptr);
            if (client_socket < 0) {
                std::cerr << "Accept failed" << std::endl;
                continue;
            }
            
            // Add client to our list
            {
                std::lock_guard<std::mutex> lock(clients_mutex);
                clients.push_back(client_socket);
            }
            
            std::cout << "✅ New client connected! Total clients: " << clients.size() << std::endl;
            
            // Broadcast that new user joined
            broadcastMessage("🚀 New user joined the chat!", client_socket);
            
            // Handle client in separate thread
            std::thread client_thread(&ChatServer::handleClient, this, client_socket);
            client_thread.detach();
        }
    }
    
private:
    void handleClient(int client_socket) {
        char buffer[1024] = {0};
        char client_name[32] = "Anonymous";
        
        // Get client's name
        int bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            strncpy(client_name, buffer, sizeof(client_name) - 1);
            broadcastMessage("🎉 " + std::string(client_name) + " has joined the chat!", client_socket);
        }
        
        while (true) {
            memset(buffer, 0, sizeof(buffer));
            bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
            
            if (bytes_read <= 0) {
                break;
            }
            
            buffer[bytes_read] = '\0';
            std::string message = "[" + std::string(client_name) + "]: " + buffer;
            
            std::cout << "💬 " << message << std::endl;

            broadcastMessage(message, client_socket);
        }
        
        // Client disconnected
        {
            std::lock_guard<std::mutex> lock(clients_mutex);
            clients.erase(std::remove(clients.begin(), clients.end(), client_socket), clients.end());
        }
        
        std::string leave_msg = "👋 " + std::string(client_name) + " left the chat";
        broadcastMessage(leave_msg, client_socket);
        std::cout << leave_msg << std::endl;
        std::cout << "📊 Remaining clients: " << clients.size() << std::endl;
        
        close(client_socket);
    }
    
    void broadcastMessage(const std::string& message, int sender_socket) {
        std::lock_guard<std::mutex> lock(clients_mutex);
        
        for (int client : clients) {
            if (client != sender_socket) { // Don't send back to sender
                send(client, message.c_str(), message.length(), 0);
            }
        }
    }
    
public:
    ~ChatServer() {
        if (server_fd > 0) {
            close(server_fd);
            std::cout << "🔌 Chat Server shutdown" << std::endl;
        }
    }
};

int main() {
    std::cout << "=== 💬 Chat Room Server ===" << std::endl;
    
    try {
        ChatServer server(8080);
        server.start();
    } catch (const std::exception& e) {
        std::cerr << "❌ Server error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}