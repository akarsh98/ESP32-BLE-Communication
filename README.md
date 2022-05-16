# ESP32-BLE-Communication

![alt text](https://github.com/akarsh98/ESP32-BLE-Communication/blob/main/Images/10.JPG)

In this tutorial, We are going to have a look at M5STICK and M5Stamp ESP32 Modules. We will create a BLE Connection between these two modules where the M5Stick module will behave as the Transmitter and the M5Stamp module will behave the receiver. There are no connections in this project as such. We just need to program the modules using the codes present in this Github repository through Arduino IDE and we will be good to go.One thing that needs to be taken care of is that in the receiver code, you need to provide the BLE Address of your MStickC. So change the field accordingly in the code. We will create a simple Transmitter Receiver pair using M5Stick C and M5Stamp PICO modules and whenever we will trigger the connection using a button on M5Stick C, an LED will blink on the M5Stamp showing that it has received the Signal. We will be using Arduino IDE to program these modules as Transmitter and Receiver So you can also check using the Serial Monitor whether the Transmission is happening or not.

![alt text](https://github.com/akarsh98/ESP32-BLE-Communication/blob/main/Images/11.JPG) ![alt text](https://github.com/akarsh98/ESP32-BLE-Communication/blob/main/Images/12.JPG)

M5StickC is a ESP32 development board with 0.96 inch TFT color screen (80 * 160 resolution), Red LED, button, Microphone, IR transmitter, 6-axis IMU (SH200Q) and 80 mAH battery. The ESP32 module ESP32-Pico in M5StickC also has a built-in 4MB flash. If the M5StickC is equipped with watch-base and watch-belt, you can wear it on your wrist.

![alt text](https://github.com/akarsh98/ESP32-BLE-Communication/blob/main/Images/9.JPG)

STAMP-PICO features an ultra-compact design with two low-power Xtensa® 32-bit LX6 microprocessors at 240MHz on a PCB as tiny and delicate as a postage stamp. low power consumption. It is ideal for any space-constrained or battery-powered devices such as wearables, medical devices, sensors, and other IoT devices. Some important features of this are:-
1, MULTIFORM: 5 options of installation, means endless possibilities! (SMT, DIP, flywire, grove interface), with a high-temperature resistant plastic shell, 3D antenna and components can be better protected.

 2, LOW-CODE DEVELOPMENT: STAMP-PICO supports UIFlow graphical programming platform, scripting-free, cloud push; and fully compatible with Arduino, MicroPython, ESP32-IDF, and other mainstream development platforms to quickly build various applications.

 3, HIGH INTEGRATION: STAMP-PICO contains a 5V->3.3V DC/DC port, GPIOx12, programmable RGB light x1, button x1, and finely tuned RF circuit, providing stable and reliable wireless communication.

 4, STRONG EXPANDABILITY: Easy access to M5Stack's hardware and software ecology system: a wealth of sensors, actuators, functional modules, and accessories to choose from, and Extremely fast adaptation.


![alt text](https://github.com/akarsh98/WebServers-on-ESP32-Codes/raw/master/Webservers%20on%20ESP32/pcbway.JPG)

You must check out [PCBWAY](https://www.pcbway.com/) for ordering PCBs online for cheap!

You get 10 good-quality PCBs manufactured and shipped to your doorstep for cheap. You will also get a discount on shipping on your first order. Upload your Gerber files onto PCBWAY to get them manufactured with good quality and quick turnaround time. [PCBWay](https://www.pcbway.com/) now could provide a complete product solution, from design to enclosure production. Check out their online Gerber viewer function. With reward points, you can get free stuff from their gift shop.
