#include <WiFi.h>
#include <PubSubClient.h>

// WiFi credentials
const char* ssid = "WE_AD0E4F";
const char* password = "k1908408";

// MQTT broker details
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;

const int ledPin = 21;  // GPIO 21

// Create a WiFi client
WiFiClient espClient;

// Create an MQTT client
PubSubClient client(espClient);

// Callback function to handle incoming messages
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  // Convert payload to string
  char message[length + 1];
  for (unsigned int i = 0; i < length; i++) {
    message[i] = (char)payload[i];
    Serial.print(message[i]);
  }
  message[length] = '\0';
  Serial.println();

  // Act based on message
  if (strcmp(message, "ON") == 0) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED turned ON");
  } else if (strcmp(message, "OFF") == 0) {
    digitalWrite(ledPin, LOW);
    Serial.println("LED turned OFF");
  }
}


void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // start with LED off

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  client.setServer(mqtt_server, mqtt_port);  // <-- Add this
  client.setCallback(callback);              // <-- And this

  if (client.connect("ESP32_ClientID")) {
    Serial.println("Connected to MQTT broker");
    client.subscribe("led/control");
  } else {
    Serial.print("Failed to connect to MQTT broker, rc=");
    Serial.print(client.state());
  }
}


void loop() {
  // Maintain the connection to the MQTT broker
  if (!client.connected()) {
    Serial.println("MQTT connection lost, attempting to reconnect...");
    if (client.connect("ESP32_ClientID")) { // Use the client ID here
      Serial.println("Connected to MQTT broker");
      client.subscribe("led/control"); // Re-subscribe to the topic
    } else {
      Serial.print("Failed to reconnect to MQTT broker, rc=");
      Serial.print(client.state());
    }
  }

  client.loop();
}