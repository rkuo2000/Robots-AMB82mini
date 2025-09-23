/*
   RoboCar controlled by MQTT
   Sensor: VL53L0X
   Camera: Video Streaming, Capture Image to SDcard
*/
#include <WiFi.h>
#include <PubSubClient.h>

#include <Wire.h>
#include <VL53L0X_IR_libraries/VL53L0X.h>

#include "VideoStream.h"
#include "AmebaFatFS.h"

#define CHANNEL  0
String imgfile = "image.jpg";
String mp3file = "mp3/JarOfLove.mp3";

VideoSetting config(VIDEO_FHD, CAM_FPS, VIDEO_JPEG, 1);

uint32_t img_addr = 0;
uint32_t img_len = 0;

AmebaFatFS fs;
File file;

VL53L0X IRsensor;

char ssid[] = "HITRON-DF90-2.4G";    // your network SSID (name)
char pass[] = "0972211921";        // your network password
int status = WL_IDLE_STATUS;     // Indicator of Wifi status

char mqttServer[] = "test.mosquitto.org";
char clientId[] = "amebaClient";
char publishTopic[] = "outTopic";
char publishPayload[] = "hello world";
char subscribeTopic[] = "TCFST/Robot1";

// nSLEEP pin connected to Vcc
// nFAULT pin kept floating
#define IN1_PIN     5 // IN1 pin GPIO
#define IN2_PIN     6 // IN2 pin PWM
#define IN3_PIN     7 // IN3 pin GPIO
#define IN4_PIN     8 // IN4 pin PWM

#define FULLSPEED 255
#define HALFSPEED 128
#define STOPSPEED 0
char buffer[128];
String command;

#define STATE_STOP   0
#define STATE_RUN    1
uint8_t state;

void callback(char* topic, byte* payload, unsigned int length)
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (unsigned int i = 0; i < length; i++) {
        Serial.print((char)(payload[i]));
        buffer[i]=(char)(payload[i]);
    }
    Serial.println();

    // command
    command = (char*)buffer;
    Serial.println(command);
    if (command=="forward") {
      state = STATE_RUN;
      forward();
    } else if (command=="backward") {
      state = STATE_RUN;      
      backward();
    } else if (command=="turnleft") {
      state = STATE_RUN;      
      turnleft();
      delay(150); // 150ms
      stop();
    } else if (command=="turnright") {
      state = STATE_RUN;      
      turnright();
      delay(150); // 150ms
      stop();
    } else if (command=="stop") {
      state = STATE_STOP;      
      stop();
    } else if (command=="snap"){
      state = STATE_STOP;
      stop();
      LED_flash(LED_G, 2, 500);       
      Serial.println("Catpuring Image...");
      Camera.getImage(CHANNEL, &img_addr, &img_len);
    // list files under root directory
      fs.begin();
      file = fs.open(imgfile);      
      file.write((uint8_t *)img_addr, img_len);
      file.close();
      fs.end();
      Serial.println("Image stored into SDcard !");      
    } else if (command=="play"){
      fs.begin();
      file = fs.open(mp3file, MP3);
      file.setMp3DigitalVol(128);
      file.playMp3();
      file.close();
    }
    for (unsigned int i = 0; i < 128; i++) buffer[i] = 0;
}

WiFiClient wifiClient;
PubSubClient client(wifiClient);

void reconnect()
{
    // Loop until we're reconnected
    while (!(client.connected())) {
        Serial.print("\r\nAttempting MQTT connection...");
        // Attempt to connect
        if (client.connect(clientId)) {
            Serial.println("connected");
            // Once connected, publish an announcement and resubscribe
            client.publish(publishTopic, publishPayload);
            client.subscribe(subscribeTopic);
        } else {
            Serial.println("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

void setup()
{
    Serial.begin(115200);
    Wire.begin();

    // IR sensor: VL53L0X
    IRsensor.setTimeout(500);
    if (! IRsensor.init()) {
        Serial.println("Failed to detect and initialize IR sensor!");
        while (1) {  }
    }

    // LED pins
    pinMode(LED_B, OUTPUT);
    pinMode(LED_G, OUTPUT);

    // Motor pins
    pinMode(IN1_PIN, OUTPUT);
    pinMode(IN2_PIN, OUTPUT);
    pinMode(IN3_PIN, OUTPUT);
    pinMode(IN4_PIN, OUTPUT);    

    // Camera
    Camera.configVideoChannel(CHANNEL, config);
    Camera.videoInit();
    Camera.channelBegin(CHANNEL);

    // Attempt to connect to WiFi network
    while (status != WL_CONNECTED) {
        Serial.print("\r\nAttempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid, pass);

        // wait 10 seconds for connection:
        delay(10000);
    }

    wifiClient.setNonBlockingMode();
    client.setServer(mqttServer, 1883);
    client.setCallback(callback);

    // IR sensor scan continuously
    IRsensor.startContinuous();

    // Allow Hardware to sort itself out
    LED_flash(LED_B, 3, 200); // LED_Blue flash 3 times @200ms
    state = STATE_RUN;
}

void LED_flash (int ledPin, uint8_t flash, int time_ms)
{
  for (int count = 0; count < flash; count++) {
    digitalWrite(ledPin, HIGH);
    delay(time_ms);
    digitalWrite(ledPin, LOW);
    delay(time_ms);
  }
}

void backward(){
  digitalWrite(IN1_PIN, HIGH);
  analogWrite(IN2_PIN, STOPSPEED);

  digitalWrite(IN3_PIN, HIGH);
  analogWrite(IN4_PIN, STOPSPEED);  
}

void forward(){
  digitalWrite(IN1_PIN, LOW);
  analogWrite(IN2_PIN, FULLSPEED);

  digitalWrite(IN3_PIN, LOW);
  analogWrite(IN4_PIN, FULLSPEED);
}

void turnleft(){
  digitalWrite(IN1_PIN, HIGH);
  analogWrite(IN2_PIN, STOPSPEED);

  digitalWrite(IN3_PIN, LOW);
  analogWrite(IN4_PIN, FULLSPEED);
}

void turnright(){
  digitalWrite(IN1_PIN, LOW);
  analogWrite(IN2_PIN, FULLSPEED);

  digitalWrite(IN3_PIN, HIGH);
  analogWrite(IN4_PIN, STOPSPEED);
}

void stop(){
  digitalWrite(IN1_PIN, LOW);
  analogWrite(IN2_PIN, STOPSPEED);

  digitalWrite(IN3_PIN, LOW);
  analogWrite(IN4_PIN, STOPSPEED);
}

void loop()
{
    unsigned int distance = IRsensor.readRangeContinuousMillimeters();
    Serial.println(distance);

    if (distance <150 && state!=STATE_STOP) { 
      stop(); 
      LED_flash(LED_G, 1, 1000); // LED_G flash once (1 sec)
    }

    if (!(client.connected())) {
        reconnect();
    }
    client.loop();
}
