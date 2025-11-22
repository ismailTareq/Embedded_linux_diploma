#include <iostream>
#include <mosquitto.h>

int main() {
    std::cout << "=== Simple MQTT Hello Publisher ===" << std::endl;

    mosquitto_lib_init();

    struct mosquitto* mosq = mosquitto_new("hello_publisher", true, NULL);
    
    if (!mosq) {
        std::cerr << "Error: Failed to create MQTT client" << std::endl;
        return 1;
    }

    int result = mosquitto_connect(mosq, "test.mosquitto.org", 1883, 60);
    
    if (result != MOSQ_ERR_SUCCESS) {
        std::cerr << "Error: Failed to connect to broker" << std::endl;
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return 1;
    }
    
    std::cout << "✅ Connected to broker successfully!" << std::endl;

    std::string topic = "hello/world";
    std::string message = "Hello MQTT from C++!";

    result = mosquitto_publish(mosq, NULL, topic.c_str(), message.length(), message.c_str(), 0, false);
    
    if (result == MOSQ_ERR_SUCCESS) {
        std::cout << "📤 Message sent successfully!" << std::endl;
        std::cout << "   Topic: " << topic << std::endl;
        std::cout << "   Message: " << message << std::endl;
    } else {
        std::cerr << "❌ Failed to send message" << std::endl;
    }
    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
    
    std::cout << "🔌 Disconnected and cleaned up" << std::endl;
    
    return 0;
}
