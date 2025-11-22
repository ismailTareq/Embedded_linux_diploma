#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <atomic>
#include <mqtt/async_client.h>

const std::string SERVER_ADDRESS = "tcp://test.mosquitto.org: 1883";
const std::string CLIENT_ID = "Sub";
const std::string TOPIC = "hello/async/world";

class HelloSubscriber : public virtual mqtt::callback {
private:
    mqtt::async_client client;
    std::atomic<bool> message_received{false};
    
public:
    HelloSubscriber() : client(SERVER_ADDRESS, CLIENT_ID) {
        std::cout << "Creating async MQTT subscriber..." << std::endl;
        
        client.set_callback(*this);
    }
    
    void message_arrived(mqtt::const_message_ptr msg) override {
        std::cout << "\n🎉 MESSAGE ARRIVED!" << std::endl;
        std::cout << "   Topic: " << msg->get_topic() << std::endl;
        std::cout << "   Payload: " << msg->to_string() << std::endl;
        std::cout << "   QoS: " << msg->get_qos() << std::endl;
        
        message_received = true;
    }
    
    void connection_lost(const std::string& cause) override {
        std::cout << "❌ Connection lost: " << cause << std::endl;
    }
    
    // void delivery_complete(mqtt::delivery_token_ptr token) override {
    // }
    
    bool connect() {
        try {
            std::cout << "🔗 Connecting to broker..." << std::endl;
            
            auto connOpts = mqtt::connect_options_builder()
                .clean_session(true)
                .finalize();
            
            client.connect(connOpts)->wait();
            std::cout << "✅ Connected successfully!" << std::endl;
            
            std::cout << "📝 Subscribing to topic: " << TOPIC << std::endl;
            client.subscribe(TOPIC, 0)->wait();
            std::cout << "✅ Subscribed successfully!" << std::endl;
            
            return true;
            
        } catch (const mqtt::exception& exc) {
            std::cerr << "❌ Connection failed: " << exc.what() << std::endl;
            return false;
        }
    }
    
    void waitForMessage() {
        std::cout << "\n⏳ Waiting for hello messages..." << std::endl;
        
        for (int i = 0; i < 30; i++) {
            if (message_received) {
                std::cout << "✅ Received message!" << std::endl;
                break;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        if (!message_received) {
            std::cout << "⏰ Timeout - no messages received" << std::endl;
        }
    }
    
    void disconnect() {
        try {
            std::cout << "🔌 Disconnecting..." << std::endl;
            client.unsubscribe(TOPIC)->wait();
            client.disconnect()->wait();
            std::cout << "✅ Disconnected successfully!" << std::endl;
        } catch (const mqtt::exception& exc) {
            std::cerr << "❌ Disconnect failed: " << exc.what() << std::endl;
        }
    }
};

int main() {
    std::cout << "=== Async MQTT Hello Subscriber ===" << std::endl;
    
    HelloSubscriber subscriber;
    
    if (subscriber.connect()) {
        subscriber.waitForMessage();
        subscriber.disconnect();
    }
    
    std::cout << "=== Demo Complete ===" << std::endl;
    return 0;
}