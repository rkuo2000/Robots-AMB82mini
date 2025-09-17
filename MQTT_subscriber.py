import paho.mqtt.subscribe as subscribe
host = "test.mosquitto.org"
msg = subscribe.simple("TCFST/Robot1", hostname=host)
print("%s %s" % (msg.topic, msg.payload.decode("utf-8")))
