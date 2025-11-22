#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mqtt/async_client.h>

const std::string SERVER_ADDRESS = "tcp://test.mosquitto.org:1883";
const std::string CLIENT_ID = "Pub";
const std::string TOPIC = "hello/async/world";

class HelloPublisher {
private:
    mqtt::async_client client;
    
public:
    HelloPublisher() : client(SERVER_ADDRESS, CLIENT_ID) {
        std::cout << "Creating async MQTT client..." << std::endl;

        client.set_connection_lost_handler([](const std::string& cause) {
            std::cout << "❌ Connection lost: " << cause << std::endl;
        });
    }
    
    bool connect() {
        try {
            std::cout << "🔗 Connecting to broker..." << std::endl;
            
            auto connOpts = mqtt::connect_options_builder()
                .clean_session(true)
                .finalize();
            
            client.connect(connOpts)->wait();
            std::cout << "✅ Connected successfully!" << std::endl;
            return true;
            
        } catch (const mqtt::exception& exc) {
            std::cerr << "❌ Connection failed: " << exc.what() << std::endl;
            return false;
        }
    }
    
    void publishHello() {
        try {
            std::string message = "sub nigga 🚀";
            
            auto pubmsg = mqtt::make_message(TOPIC, message);
            
            pubmsg->set_qos(0);
            
            std::cout << "📤 Publishing message..." << std::endl;
            std::cout << "   Topic: " << TOPIC << std::endl;
            std::cout << "   Message: " << message << std::endl;
            
            client.publish(pubmsg)->wait();
            
            std::cout << "✅ Message published successfully!" << std::endl;
            
        } catch (const mqtt::exception& exc) {
            std::cerr << "❌ Publish failed: " << exc.what() << std::endl;
        }
    }
    
    void disconnect() {
        try {
            std::cout << "🔌 Disconnecting..." << std::endl;
            client.disconnect()->wait();
            std::cout << "✅ Disconnected successfully!" << std::endl;
        } catch (const mqtt::exception& exc) {
            std::cerr << "❌ Disconnect failed: " << exc.what() << std::endl;
        }
    }
};

int main() {
    std::cout << "=== Async MQTT Hello Publisher ===" << std::endl;
    
    HelloPublisher publisher;
    
    if (publisher.connect()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        publisher.publishHello();
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
        publisher.disconnect();
    }
    
    std::cout << "=== Demo Complete ===" << std::endl;
    return 0;
}