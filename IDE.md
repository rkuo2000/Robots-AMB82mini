
## 2. IDE使用介紹

### [Arduino IDE 2.3.6](https://www.arduino.cc/en/software) 下載 & 安裝
<p><img width="50%" height="50%" src="https://github.com/rkuo2000/EdgeAI-AMB82mini/blob/main/assets/Arduino_IDE.png?raw=true"></p>

---
### 偏好設定 (Preferences)
**Hub8735 ultra**<br>
`https://raw.githubusercontent.com/ideashatch/HUB-8735/main/amebapro2_arduino/Arduino_package/ideasHatch.json`<br>

**AMB82-mini**<br>
**main** `https://github.com/Ameba-AIoT/ameba-arduino-pro2/raw/main/Arduino_package/package_realtek_amebapro2_index.json`<br>
**dev** `https://github.com/Ameba-AIoT/ameba-arduino-pro2/raw/dev/Arduino_package/package_realtek_amebapro2_early_index.json`<br>

![](https://github.com/rkuo2000/EdgeAI-AMB82-mini/blob/main/assets/AMB82-mini_Arduino_IDE_preference.png?raw=true)

[![](https://markdown-videos-api.jorgenkh.no/youtube/-jQDpDFX2ao)](https://youtu.be/-jQDpDFX2ao)

---
### 選定開發板 AMB82-MINI
Tools > Board Manager > AMB82 package > 4.0.9<br>
<p><img width="75%" height="75%" src="https://github.com/rkuo2000/EdgeAI-AMB82-mini/blob/main/assets/AMB82-mini_Arduino_IDE_BoardManager.png?raw=true"></p>

Serial-monitor = `115200` baud <br>
---
### [Getting Started](https://www.amebaiot.com/en/amebapro2-amb82-mini-arduino-getting-started/)
首先將AMB82-mini板子用MicroUSB線 連接至電腦的USB port<br>
確認UART com port (Ubuntu OS需 `sudo chown usrname /dev/ttyUSB0`)

<p><img width="50%" height="50%" src="https://www.amebaiot.com/wp-content/uploads/2022/12/amb82-mini/P03.png"></p>

**燒錄程式碼：** <br>
* 按下UART_DOWNLOAD按鈕, 再按下RESET按鈕, 放開RESET按鈕, 再放開UART_DOWNLOAD按鈕,板子就進入燒錄模式.
* 然後于Arduino IDE上按下燒錄按鍵`Upload`

---
### Realtek AmebaPro2 hardware libraries
`C:\Users\user\AppData\Local\Arduino15\packages\realtek\hardware\AmebaPro2\4.0.9-build20250805\libraries`<br>

`C:\Users\user\AppData\Local\Arduino15\packages\realtek\hardware\AmebaPro2\4.0.9-build20250805\libraries\NeuralNetwork\src`<br>
GenAI.h<br>
GenAI.cpp<br> 
