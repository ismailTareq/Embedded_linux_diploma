#include "publisher.hpp"
#include <mqtt/async_client.h>

const std::string SERVER_ADDRESS ="tcp://test.mosquitto.org:1883";
const std::string CLIENT_ID = "mqtt_publisher";
namespace mqtt {
    publisherCallback callback;

    void publisherCallback::connection_lost(const std::string &cause) {
        std::cout << "Connection lost: " << cause << std::endl;
    }
    void publisherCallback::delivery_complete(mqtt::delivery_token_ptr token) {
     std::cout << "Delivery complete for token: " << (token ? token->get_message_id() : 0) << std::endl;   
    }
    void publisherCallback::message_arrived(mqtt::const_message_ptr msg) {
        std::cout << "Message arrived: " << msg->get_payload_str() << std::endl;
    }
    publisher::publisher() : client(SERVER_ADDRESS, CLIENT_ID) 
    {
        client.connect()->wait();
        client.set_callback(callback);
    }
    publisher::~publisher() {
        client.disconnect()->wait();
    }
    void publisher::TriggerLed(bool value) 
    {
        try {
            std::string topic = "led/control";
        std::string data = value ? "ON" : "OFF";
        int qos = 1;
        bool retain = false;
        client.publish(topic, data, qos, retain)->wait();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    
        }
    catch (const mqtt::exception &e) {
        std::cerr << "MQTT Exception: " << e.what() << std::endl;
    }
}
}
