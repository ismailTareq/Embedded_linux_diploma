#include <iostream>
#include <string>
#include <curl/curl.h>

// Callback function to write response data
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

class SimpleHttpClient {
public:
    SimpleHttpClient() {
        curl_global_init(CURL_GLOBAL_DEFAULT);
    }
    
    ~SimpleHttpClient() {
        curl_global_cleanup();
    }
    
    // GET Request
    std::string get(const std::string& url) {
        CURL* curl;
        CURLcode res;
        std::string response;
        
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
            
            res = curl_easy_perform(curl);
            
            if(res != CURLE_OK) {
                std::cerr << "GET failed: " << curl_easy_strerror(res) << std::endl;
            }
            
            curl_easy_cleanup(curl);
        }
        return response;
    }
    
    // POST Request
    std::string post(const std::string& url, const std::string& data) {
        CURL* curl;
        CURLcode res;
        std::string response;
        
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
            
            // Set content type for JSON
            struct curl_slist* headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            
            res = curl_easy_perform(curl);
            
            if(res != CURLE_OK) {
                std::cerr << "POST failed: " << curl_easy_strerror(res) << std::endl;
            }
            
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }
        return response;
    }
};

// IoT Sensor Data Structure
struct SensorData {
    int device_id;
    float temperature;
    float humidity;
    long timestamp;
    
    std::string toJson() const {
        return "{\"device_id\":" + std::to_string(device_id) +
               ",\"temperature\":" + std::to_string(temperature) +
               ",\"humidity\":" + std::to_string(humidity) +
               ",\"timestamp\":" + std::to_string(timestamp) + "}";
    }
};

int main() {
    SimpleHttpClient http;
    
    // Example 1: GET Request
    std::cout << "=== Testing GET Request ===" << std::endl;
    std::string getResponse = http.get("http://httpbin.org/get");
    std::cout << "GET Response: " << getResponse << std::endl;
    
    // Example 2: POST Request
    std::cout << "\n=== Testing POST Request ===" << std::endl;
    
    SensorData sensorReading;
    sensorReading.device_id = 12345;
    sensorReading.temperature = 22.5f;
    sensorReading.humidity = 60.8f;
    sensorReading.timestamp = time(nullptr);
    
    std::string jsonData = sensorReading.toJson();
    std::cout << "Sending: " << jsonData << std::endl;
    
    std::string postResponse = http.post("http://httpbin.org/post", jsonData);
    std::cout << "POST Response: " << postResponse << std::endl;
    
    return 0;
}