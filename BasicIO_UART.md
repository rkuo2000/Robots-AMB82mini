
## MCU 基本功能練習

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
### GTimer
**Examples> AmebaGTimer > [TimerOneShot](https://ameba-doc-arduino-sdk.readthedocs-hosted.com/en/latest/ameba_pro2/amb82-mini/Example_Guides/GTimer/Timer%20Oneshot.html)**

**Examples> AmebaGTimer > [TimerPeriodical](https://ameba-doc-arduino-sdk.readthedocs-hosted.com/en/latest/ameba_pro2/amb82-mini/Example_Guides/GTimer/Timer%20Periodical.html)** <br>

---
## UART（Universal Asynchronous Receiver/Transmitter）序列埠
[BASICS OF UART COMMUNICATION](https://www.circuitbasics.com/basics-uart-communication/)
<img width="50%" height="50%" src="https://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-UART-Data-Transmission-Diagram.png">
![](https://makerpro.cc/wp-content/uploads/2019/08/2.png)

### Protocol 通訊協定
![](https://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-UART-Packet-Frame-and-Bits-2.png)
* Standard Packet : 8 data bits, even parity, 1 stop bit
  - If the parity bit is a 0 (even parity), the 1 bits in the data frame should total to an even number. 
  - If the parity bit is a 1 (odd parity), the 1 bits in the data frame should total to an odd number.
![](https://makerpro.cc/wp-content/uploads/2019/08/4.png)
RS232 的Vpp電壓較高，有 6V~30V；UART 則是較低的 3.3V 或 5V<br>
RS232 為負邏輯， UART 為正邏輯，因此兩者波形是反相的<br>
**Baud Rate**<br>
![](https://github.com/rkuo2000/MCU-course/blob/main/images/UART-baudrates.png?raw=true)

---
### UART examples
Examples> Communication > **[MultiSerial](https://docs.arduino.cc/built-in-examples/communication/MultiSerialMega/)** <br>

Examples> Communication > **[SerialPassThrough](https://docs.arduino.cc/built-in-examples/communication/SerialPassthrough/)** <br>

Examples> Communication > **[SerialCallResponseASCII](https://docs.arduino.cc/built-in-examples/communication/SerialCallResponseASCII/)** <br>

Examples> Communication > **[SerialCallResponse](https://docs.arduino.cc/built-in-examples/communication/SerialCallResponse/)** <br>
![](https://docs.arduino.cc/static/9945133ddd45e77b74174ead53888478/a6d36/schematic.png)


