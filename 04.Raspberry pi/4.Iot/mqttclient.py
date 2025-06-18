import paho.mqtt.client as mqtt

def on_connect(client, userdata, flags, rc):
    print("Connected with result code {rc}")
    client.subscribe("test/topic1")
    client.subscribe("test/topic2")

def on_message(client, userdata, msg):
    print(msg.topic + " " + str(msg.payload))
    if str(msg.payload).find("hello") != -1:
        print("Hello message received!")
    if msg.payload == 'world!':
        print("world message received ")

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("test.mosquitto.org", 1883, 60)
client.loop_forever()
