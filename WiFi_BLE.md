
## MCU 基本功能練習

### [MCU Interfaces](https://github.com/rkuo2000/EdgeAI-AMB82mini/blob/main/MCU_interfaces.md)

---
### Basic I/O 範例練習
**Examples> 01.Basics > Blink**<br>
  
![](https://github.com/rkuo2000/EdgeAI-AMB82mini/blob/main/assets/AMB82-mini_Arduino_examples_01.Basics_Blink.png?raw=true)
    
**Examples> 02.Digitial > GPIO > Button**<br>
  
![](https://github.com/rkuo2000/EdgeAI-AMB82mini/blob/main/assets/AMB82-mini_Arduino_examples_02.Digital_Button.png?raw=true)

程式碼修改：<br>
const int buttonPin = `1`;  // the number of the pushbutton pin<br>
const int ledPin = `LED_BUILTIN`;    // the number of the LED pin<br>

**Examples> 01.Basic > AnalogReadSerial**<br>

![](https://github.com/rkuo2000/EdgeAI-AMB82mini/blob/main/assets/AMB82-mini_Arduino_examples_01.Basics_AnalogReadSerial.png?raw=true)

程式碼修改：Serial.begin(`115200`);<br>

---
### WiFi
**Examples> WiFi > SimpleTCPServer**<br>
[WiFi - Simple TCP Server](https://www.amebaiot.com/en/amebapro2-arduino-server-client/)<br>

**Examples> WiFi > SimpleHttpWeb > ReceiveData**<br>
[WiFi - Simple Http Server to Receive Data](https://www.amebaiot.com/en/amebapro2-arduino-web-server-status/)<br>

**Examples> WiFi > SimpleHttpWeb > ControlLED**<br>
[WiFi - Simple Http Server to Control LED](https://www.amebaiot.com/en/amebapro2-arduino-ameba-web-server/)<br>

**Sketchbook> AMB82-mini > WebServer_ControlLED**<br>
[Sketchbook> WebServer_ControlLED](https://github.com/rkuo2000/EdgeAI-AMB82mini/blob/main/Arduino/AMB82-mini/WebServer_ControlLED/WebServer_ControlLED.ino)<br>
![](https://github.com/rkuo2000/EdgeAI-AMB82mini/blob/main/assets/AMB82-mini_Arduino_Sketch_WebServer_ControlLED.png?raw=true)

---
### BLE

**Exmples> AmebaBLE > BLEV7RC_CAR_VIDEO** <br>

[BLE V7RC](https://www.amebaiot.com/zh/amebad-arduino-ble-v7rc/)<br>

ParseCMDString(String cmd) is a customized function will take a string “cmd” as input and process it. Currently, there are 6 available commands from V7RC App, which are: “SS2”,”SS4”,”SRT”,”SR2”, and “SRV”.<br>

* [V7RC APP 介紹](https://hackmd.io/@accomdemy/v7rc)<br>
* 安裝[手機App V7RC](https://play.google.com/store/apps/details?id=com.v7idea.v7rcliteandroidsdkversion&hl=en)<br>
<p>
<img width="50%" height="50%" src="https://www.amebaiot.com/wp-content/uploads/2023/08/ble-v7rc/p1_zh.png">
<img width="50%" height="50%" src="https://www.amebaiot.com/wp-content/uploads/2023/08/ble-v7rc/p2_zh.png">
</p>

