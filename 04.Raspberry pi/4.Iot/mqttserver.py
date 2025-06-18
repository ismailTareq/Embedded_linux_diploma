import paho.mqtt.publish as publish

publish.single("test/topic1", "hello", hostname="test.mosquitto.org")
publish.single("test/topic2", "world!", hostname="test.mosquitto.org")
print("Messages published to test/topic1 and test/topic2")