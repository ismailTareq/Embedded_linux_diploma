#include <iostream>
#include <string>
#include <curl/curl.h>

// WHY: Callback function to handle incoming HTTP response data
// In IoT, servers send back responses (success messages, error codes, new commands)
// This function collects all the response data pieces into one string
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    ((std::string*)userp)->append((char*)contents, totalSize);
    return totalSize;
}

class IoTHttpClient {
private:
    //Store device ID to identify which device is sending data
    std::string deviceId;

public:
    // Constructor - sets up our IoT device identity
    IoTHttpClient(const std::string& id) : deviceId(id) {
        // WHY: Initialize libcurl - necessary setup before making any HTTP requests
        curl_global_init(CURL_GLOBAL_DEFAULT);
        std::cout << "IoT Device " << deviceId << " initialized" << std::endl;
    }
    
    // Destructor - cleanup when device shuts down
    ~IoTHttpClient() {
        curl_global_cleanup();
        std::cout << "IoT Device " << deviceId << " shutting down" << std::endl;
    }
    
    //GET request - used to FETCH information
    std::string getConfiguration(const std::string& serverUrl) {
        std::cout << "\n=== GET: Checking for device configuration ===" << std::endl;
        
        CURL* curl = curl_easy_init();
        std::string response;
        
        if(curl) {
            // WHY: Set the target URL - where our IoT server is located
            curl_easy_setopt(curl, CURLOPT_URL, serverUrl.c_str());
            
            //callback function to collect response
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
            
            // Perform the actual HTTP GET request
            CURLcode res = curl_easy_perform(curl);
            
            if(res != CURLE_OK) {
                std::cerr << "GET failed: " << curl_easy_strerror(res) << std::endl;
                response = "ERROR: " + std::string(curl_easy_strerror(res));
            } else {
                std::cout << "✓ Successfully received configuration from server" << std::endl;
            }
            
            curl_easy_cleanup(curl);
        }
        
        return response;
    }
    
    // WHY: POST request - used when IoT device needs to SEND data
    // Examples: Send sensor readings, report status, log events
    std::string sendSensorData(const std::string& serverUrl, float temperature, float humidity) {
        std::cout << "\n=== POST: Sending sensor data to cloud ===" << std::endl;
        
        CURL* curl = curl_easy_init();
        std::string response;
        
        if(curl) {
            // WHY: Create JSON payload - standard format for IoT data exchange
            std::string jsonData = "{\n"
                                 "  \"device_id\": \"" + deviceId + "\",\n"
                                 "  \"temperature\": " + std::to_string(temperature) + ",\n"
                                 "  \"humidity\": " + std::to_string(humidity) + ",\n"
                                 "  \"timestamp\": " + std::to_string(time(nullptr)) + "\n"
                                 "}";
            
            std::cout << "Sending sensor data: " << std::endl;
            std::cout << jsonData << std::endl;
            
            // Set URL for POST request
            curl_easy_setopt(curl, CURLOPT_URL, serverUrl.c_str());
            
            // WHY: Tell libcurl we're doing a POST request (not GET)
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            
            // WHY: Provide the actual data we want to send
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonData.c_str());
            
            // Set up response handling
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
            
            // WHY: Set timeout - important for battery-powered IoT devices
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
            
            // WHY: Set HTTP headers - tell server we're sending JSON data
            struct curl_slist* headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            
            // Perform the actual HTTP POST request
            CURLcode res = curl_easy_perform(curl);
            
            if(res != CURLE_OK) {
                std::cerr << "POST failed: " << curl_easy_strerror(res) << std::endl;
                response = "ERROR: " + std::string(curl_easy_strerror(res));
            } else {
                std::cout << "✓ Successfully sent data to cloud server" << std::endl;
            }
            
            // Cleanup
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }
        
        return response;
    }
};

// WHY: Simulate sensor readings - in real IoT, you'd read from actual sensors
// This demonstrates the data collection part of IoT
float readTemperatureSensor() {
    // Simulate temperature between 20.0°C and 30.0°C
    return 20.0f + (rand() % 100) / 10.0f;
}

float readHumiditySensor() {
    // Simulate humidity between 40% and 80%
    return 40.0f + (rand() % 400) / 10.0f;
}

int main() {
    std::cout << "=== IoT HTTP Client Demo ===" << std::endl;
    std::cout << "Simulating a smart environmental sensor device\n" << std::endl;
    
    // WHY: Create our IoT device with unique ID
    // In real IoT, each device needs a unique identifier
    IoTHttpClient sensorDevice("ENV_SENSOR_001");
    
    // Server URLs (using free test servers)
    std::string configServer = "http://httpbin.org/get";
    std::string dataServer = "http://httpbin.org/post";
    
    // WHY: Demo sequence showing real IoT device workflow
    
    // 1. GET configuration from server
    std::string config = sensorDevice.getConfiguration(configServer);
    std::cout << "Configuration response: " << config.substr(0, 200) << "..." << std::endl;
    
    // 2. Read sensors (simulated)
    float temp = readTemperatureSensor();
    float humidity = readHumiditySensor();
    std::cout << "\nSensor Readings - Temperature: " << temp << "°C, Humidity: " << humidity << "%" << std::endl;
    
    // 3. POST sensor data to cloud
    std::string serverResponse = sensorDevice.sendSensorData(dataServer, temp, humidity);
    std::cout << "Server response: " << serverResponse.substr(0, 300) << "..." << std::endl;
    
    std::cout << "\n=== IoT Device Cycle Complete ===" << std::endl;
    
    return 0;
}
