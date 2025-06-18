#include <mqtt/async_client.h>
#include <string>
namespace mqtt {
const std::string SERVER_ADDRESS("tcp://192.168.1.24:1883");
const std::string CLIENT_ID("mqtt_client");
class publisherCallback : public virtual mqtt::callback {

public:
  void connection_lost(const std::string &cause) override;
  void delivery_complete(mqtt::delivery_token_ptr token) override;
  void message_arrived(mqtt::const_message_ptr msg) override;
};

class publisher : public virtual mqtt::callback {
public:
  publisher();
  ~publisher();

  void TriggerLed(bool value);

private:
  mqtt::async_client client;
  publisherCallback callback;
};
}
