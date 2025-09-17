---
### [MQTT](https://mqtt.org/)
MQTT is an OASIS standard messaging protocol for the Internet of Things (IoT)<br>
[How MQTT Works -Beginners Guide](http://www.steves-internet-guide.com/mqtt-works/)<br>

**Examples> AmebaMQTTClient > MQTT_basic** <br>
[MQTT - Set up MQTT Client to Communicate with Broker](https://www.amebaiot.com/en/amebapro2-arduino-mqtt-upload-listen/)<br>
![](https://www.amebaiot.com/wp-content/uploads/2023/06/network/mqtt1-1.png)

`pip install paho.mqtt`<br>

**publish messages to AMB82-mini** <br>
```
import paho.mqtt.publish as publish
host = "test.mosquitto.org"
publish.single("ntou/edgeai/robot1", "go to the kitchen", hostname=host)
```

**subsribe messages from AMB82-mini** <br>
```
import paho.mqtt.subscribe as subscribe
host = "test.mosquitto.org"https://github.com/rkuo2000/EdgeAI-AMB82mini
msg = subscribe.simple("ntou/edgeai/robot1", hostname=host)
print("%s %s" % (msg.topic, msg.payload.decode("utf-8")))
```

---
### Gemini MQTT App
**[Google Gemini](https://gemini.google.com/) +Canvas** <br>

**Prompt:** `make an html to input MQTT topic and text to publish through Paho-MQTT test.mosquitto.org`<br>

**[Paho-MQTT Publisher](https://g.co/gemini/share/ae62311518bd)** <br>
![](https://github.com/rkuo2000/EdgeAI-AMB82mini/blob/main/assets/Gemini_Canvas_Paho-MQTT_Text_Publisher.png?raw=true)

