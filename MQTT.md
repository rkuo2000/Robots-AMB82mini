---
### [MQTT](https://mqtt.org/)
MQTT is an OASIS standard messaging protocol for the Internet of Things (IoT)<br>
[How MQTT Works -Beginners Guide](http://www.steves-internet-guide.com/mqtt-works/)<br>

**Examples> AmebaMQTTClient > MQTT_basic** <br>
[MQTT - Set up MQTT Client to Communicate with Broker](https://www.amebaiot.com/en/amebapro2-arduino-mqtt-upload-listen/)<br>
<p><img width="50%" height="50%" src="https://www.amebaiot.com/wp-content/uploads/2023/06/network/mqtt1-1.png"></p>

`pip install paho.mqtt`<br>

---
### Running Publisher
**publish messages to AMB82-mini** <br>
```
import paho.mqtt.publish as publish
host = "test.mosquitto.org"
publish.single("TCFST/Robot1", "go to the kitchen", hostname=host)
```

---
### Running Subscriber
**subsribe messages from AMB82-mini** <br>
```
import paho.mqtt.subscribe as subscribe
host = "test.mosquitto.org"
msg = subscribe.simple("TCFST/Robot1", hostname=host)
print("%s %s" % (msg.topic, msg.payload.decode("utf-8")))
```

---
### Gemini MQTT Pusblisher
**[Gemini Canvas](https://gemini.google.com/canvas)** <br>

**Prompt:** `make an html to input MQTT topic and text to publish through Paho-MQTT test.mosquitto.org`<br>

**[Paho-MQTT Publisher](https://github.com/rkuo2000/Robots/blob/main/MQTT_publisher.html)
![](https://github.com/rkuo2000/Robots/blob/main/assets/Paho-MQTT_Publisher.png?raw=true)**

