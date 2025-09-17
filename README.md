# Robots
 
## AMB82mini 開發板介紹
### RTL8735B晶片簡介
32-bit Arm v8M, up to 500MHz, 768KB ROM, 512KB RAM, 16MB Flash (MCM embedded DDR2/DDR3L up to 128MB)<br>
802.11 a/b/g/n WiFi 2.4GHz/5GHz, BLE 5.1, *NN Engine 0.4 TOPS*, Crypto Engine, Audio Codec, ...<br>

---
### [HUB 8735 Ultra](https://robotkingdom.com.tw/product/hub-8735-ultra/)
#### [https://github.com/ideashatch/HUB-8735](https://github.com/ideashatch/HUB-8735)

<p><img width="25%" height="25%" src="https://robotkingdom.com.tw/wp-content/uploads/2024/09/HUB_8735_Ultra-4-510x680.jpg"></p>

[![](https://markdown-videos-api.jorgenkh.no/youtube/-_NMUnY0kK4)](https://youtu.be/-_NMUnY0kK4)

---
### [AMB82-mini](https://www.icshop.com.tw/products/368030501864)
#### [Ameba Arduino](https://www.amebaiot.com/en/ameba-arduino-summary/)

<p><img width="25%" height="25%" src="https://github.com/rkuo2000/EdgeAI-AMB82-mini/blob/main/assets/AMB82-mini.png?raw=true"></p>

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
