#include <iostream>
#include <mosquitto.h>
#include <thread>
#include <chrono>

void on_message(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* msg) {
    std::string topic = msg->topic;
    std::string message = static_cast<char*>(msg->payload);
    
    std::cout << "📨 Received message!" << std::endl;
    std::cout << "   Topic: " << topic << std::endl;
    std::cout << "   Message: " << message << std::endl;

    mosquitto_disconnect(mosq);
}

void on_connect(struct mosquitto* mosq, void* userdata, int result) {
    if (result == 0) {
        std::cout << "✅ Connected to broker successfully!" << std::endl;

        mosquitto_subscribe(mosq, NULL, "hello/world", 0);
        std::cout << "📝 Subscribed to: hello/world" << std::endl;
    } else {
        std::cerr << "❌ Failed to connect to broker" << std::endl;
    }
}

int main() {
    std::cout << "=== Simple MQTT Hello Subscriber ===" << std::endl;
    std::cout << "Waiting for hello messages... (Press Ctrl+C to stop)" << std::endl;

    mosquitto_lib_init();

    struct mosquitto* mosq = mosquitto_new("hello_subscriber", true, NULL);
    
    if (!mosq) {
        std::cerr << "Error: Failed to create MQTT client" << std::endl;
        return 1;
    }

    mosquitto_connect_callback_set(mosq, on_connect);
    mosquitto_message_callback_set(mosq, on_message);

    int result = mosquitto_connect(mosq, "test.mosquitto.org", 1883, 60);
    
    if (result != MOSQ_ERR_SUCCESS) {
        std::cerr << "Error: Failed to connect to broker" << std::endl;
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return 1;
    }

    mosquitto_loop_start(mosq);

    for (int i = 0; i < 30; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        // Check if we're still connected
        if (!mosquitto_want_write(mosq)) {
            break; // Exit if disconnected
        }
    }
    mosquitto_loop_stop(mosq, false);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
    
    std::cout << "🔌 Subscriber stopped" << std::endl;
    
    return 0;
}
