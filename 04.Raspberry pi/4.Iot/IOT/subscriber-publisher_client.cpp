#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mosquitto.h>

class MQTT_Client {
private:
    struct mosquitto* mosq;
    std::string clientId;
    std::string broker;
    int port;
    bool connected;

    //receive a message from subscribed topics
    static void on_message(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* msg) {
        MQTT_Client* client = static_cast<MQTT_Client*>(userdata);
        
        std::string topic = msg->topic;
        std::string message = static_cast<char*>(msg->payload);
        
        std::cout << "📨 Received MQTT Message:" << std::endl;
        std::cout << "  Topic: " << topic << std::endl;
        std::cout << "  Data: " << message << std::endl;

        if (topic == "home/bedroom/light/command") {
            if (message == "ON") {
                std::cout << "💡 ACTION: Turning light ON" << std::endl;
            } else if (message == "OFF") {
                std::cout << "💡 ACTION: Turning light OFF" << std::endl;
            }
        }
    }

    //know when we're connected to broker
    static void on_connect(struct mosquitto* mosq, void* userdata, int result) {
        MQTT_Client* client = static_cast<MQTT_Client*>(userdata);
        
        if (result == 0) {
            std::cout << "✅ Connected to MQTT broker successfully!" << std::endl;
            client->connected = true;

            mosquitto_subscribe(mosq, NULL, "home/bedroom/light/command", 0);
            mosquitto_subscribe(mosq, NULL, "home/bedroom/temperature/set", 0);
            std::cout << "📝 Subscribed to command topics" << std::endl;
        } else {
            std::cerr << "❌ Failed to connect to MQTT broker. Error: " << result << std::endl;
            client->connected = false;
        }
    }

public:
    // Constructor
    MQTT_Client(const std::string& id, const std::string& broker_ip = "localhost", int broker_port = 1883) 
        : clientId(id), broker(broker_ip), port(broker_port), connected(false) {
        mosquitto_lib_init();
        
        mosq = mosquitto_new(clientId.c_str(), true, this);
        
        if (!mosq) {
            throw std::runtime_error("Failed to create MQTT client");
        }
        
        //callback functions for message and connection events
        mosquitto_connect_callback_set(mosq, on_connect);
        mosquitto_message_callback_set(mosq, on_message);
        
        std::cout << "🔧 MQTT Client '" << clientId << "' initialized" << std::endl;
    }
    
    // Destructor
    ~MQTT_Client() {
        if (mosq) {
            disconnect();
            mosquitto_destroy(mosq);
        }
        mosquitto_lib_cleanup();
        std::cout << "🔌 MQTT Client '" << clientId << "' destroyed" << std::endl;
    }
    
    // Connect to MQTT broker
    bool connect() {
        std::cout << "🔗 Connecting to MQTT broker at " << broker << ":" << port << "..." << std::endl;
        
        int result = mosquitto_connect(mosq, broker.c_str(), port, 60); // 60 second keepalive
        
        if (result != MOSQ_ERR_SUCCESS) {
            std::cerr << "❌ Connection failed: " << mosquitto_strerror(result) << std::endl;
            return false;
        }
        
        //Start network loop in background thread for IoT devices
        // This handles incoming messages and keepalive packets
        mosquitto_loop_start(mosq);
        return true;
    }
    
    // Disconnect from broker
    void disconnect() {
        if (connected) {
            mosquitto_loop_stop(mosq, false);
            mosquitto_disconnect(mosq);
            connected = false;
            std::cout << "🔌 Disconnected from MQTT broker" << std::endl;
        }
    }
    
    //main way IoT devices send information
    bool publishSensorData(float temperature, float humidity) {
        if (!connected) {
            std::cerr << "❌ Not connected to broker" << std::endl;
            return false;
        }
        
        std::string payload = "{\"device_id\":\"" + clientId + 
                             "\",\"temperature\":" + std::to_string(temperature) + 
                             ",\"humidity\":" + std::to_string(humidity) + 
                             ",\"timestamp\":" + std::to_string(time(nullptr)) + "}";
        
        //organized hierarchy for IoT
        // QoS 0 = fire and forget, QoS 1 = at least once, QoS 2 = exactly once
        int result = mosquitto_publish(mosq, NULL, 
                                     "home/bedroom/sensor/data",  // Topic
                                     payload.length(),           // Message length
                                     payload.c_str(),            // Message data
                                     1,                         // QoS 1 - at least once delivery
                                     false);                    // Don't retain message
        
        if (result == MOSQ_ERR_SUCCESS) {
            std::cout << "📤 Published sensor data: " << payload << std::endl;
            return true;
        } else {
            std::cerr << "❌ Publish failed: " << mosquitto_strerror(result) << std::endl;
            return false;
        }
    }
    
    //monitoring IoT devices
    bool publishStatus(const std::string& status) {
        if (!connected) {
            return false;
        }
        
        std::string payload = "{\"device_id\":\"" + clientId + "\",\"status\":\"" + status + "\"}";
        
        int result = mosquitto_publish(mosq, NULL, 
                                     "home/bedroom/sensor/status",
                                     payload.length(),
                                     payload.c_str(),
                                     1,    // QoS 1
                                     true); // Retain - so new subscribers get last status
        
        if (result == MOSQ_ERR_SUCCESS) {
            std::cout << "📤 Published status: " << status << std::endl;
            return true;
        } else {
            std::cerr << "❌ Status publish failed: " << mosquitto_strerror(result) << std::endl;
            return false;
        }
    }
    
    bool isConnected() const {
        return connected;
    }
};

float readTemperatureSensor() {
    // Simulate temperature between 20.0°C and 30.0°C
    return 20.0f + (rand() % 100) / 10.0f;
}

float readHumiditySensor() {
    // Simulate humidity between 40% and 80%
    return 40.0f + (rand() % 400) / 10.0f;
}

int main() {
    std::cout << "=== IoT MQTT Client Demo ===" << std::endl;
    std::cout << "Simulating a smart bedroom sensor with remote control\n" << std::endl;
    
    try {
        MQTT_Client sensor("BEDROOM_SENSOR_001", "test.mosquitto.org", 1883);
        
        // Connect to MQTT broker
        if (!sensor.connect()) {
            std::cerr << "Failed to connect to broker" << std::endl;
            return 1;
        }

        std::cout << "⏳ Waiting for connection..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        
        // Publish initial status
        sensor.publishStatus("online");
        
        // read sensors and publish data periodically
        for (int i = 0; i < 5; ++i) {
            if (sensor.isConnected()) {
                // Read sensors
                float temp = readTemperatureSensor();
                float humidity = readHumiditySensor();
                
                std::cout << "\n--- Sensor Reading " << (i + 1) << " ---" << std::endl;
                std::cout << "Temperature: " << temp << "°C, Humidity: " << humidity << "%" << std::endl;
                
                // Publish sensor data
                sensor.publishSensorData(temp, humidity);
                
                std::this_thread::sleep_for(std::chrono::seconds(5));
            } else {
                std::cerr << "❌ Lost connection to broker" << std::endl;
                break;
            }
        }
        
        // Publish offline status before disconnecting
        sensor.publishStatus("offline");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
    } catch (const std::exception& e) {
        std::cerr << "❌ Error: " << e.what() << std::endl;
        return 1;
    }
    
    std::cout << "\n=== IoT MQTT Demo Complete ===" << std::endl;
    return 0;
}