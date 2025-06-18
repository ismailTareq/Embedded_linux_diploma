#include <iostream>
#include <mqtt/async_client.h>

const std::string SERVER_ADDRESS("tcp://localhost:1883");
const std::string CLIENT_ID("mqtt_client");

class ClientCallback : public virtual mqtt::callback {
public:
  void connection_lost(const std::string &cause) override {
    std::cout << "Connection lost: " << cause << std::endl;
  }

  void delivery_complete(mqtt::delivery_token_ptr token) override {}

  void message_arrived(mqtt::const_message_ptr msg) override {}
};

int main() {
  mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);

  try {
    ClientCallback callback;
    client.set_callback(callback);

    mqtt::connect_options conn_opts;
    conn_opts.set_keep_alive_interval(20);
    conn_opts.set_clean_session(true);

    client.connect(conn_opts)->wait();

    std::string topic = "test/topic";
    std::string payload = "Hello, MQTT!";
    int qos = 1;
    bool retained = false;

    client.publish(topic, payload, qos, retained)->wait();

    std::this_thread::sleep_for(std::chrono::seconds(2));

    client.disconnect()->wait();
  } catch (const mqtt::exception &exc) {
    std::cerr << "Error: " << exc.what() << std::endl;
    return 1;
  }

  return 0;
}

