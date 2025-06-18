#include <iostream>
#include <string>
#include <mqtt/async_client.h>

const std::string SERVER_ADDRESS("tcp://localhost:1883");
const std::string CLIENT_ID("raspi_sub");
const std::string TOPIC("raspi/test");

class SubscriberCallback : public mqtt::callback {
public:
    void message_arrived(mqtt::const_message_ptr msg) override {
        std::cout << "Received on [" << msg->get_topic() << "]: " 
                  << msg->get_payload_str() << std::endl;
    }
};

int main() {
    try {
        // 1. Create client
        mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);
        
        // 2. Set callback
        SubscriberCallback cb;
        client.set_callback(cb);

        // 3. Configure connection
        mqtt::connect_options connOpts;
        connOpts.set_clean_session(true);

        // 4. Connect and subscribe
        client.connect(connOpts)->wait();
        client.subscribe(TOPIC, 1)->wait();
        
        std::cout << "Subscribed to " << TOPIC << "\nWaiting for messages..." << std::endl;

        // 5. Keep running until Enter is pressed
        std::cin.get();

        // 6. Clean disconnect
        client.unsubscribe(TOPIC)->wait();
        client.disconnect()->wait();
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    }

    return 0;
}
