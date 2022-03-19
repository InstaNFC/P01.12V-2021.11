# Access Pro (P01.12V-2021.11)

<p align="middle">
  <img src="https://github.com/InstaNFC/P01.12V-2021.11/blob/main/Hardware%20Images/3d-front-large.png?raw=true" width="40%" />
  <img src="https://github.com/InstaNFC/P01.12V-2021.11/blob/main/Hardware%20Images/3d-back-large.png?raw=true" width="40%" />
</p>


|         Feature 	| Model                                                                                               	| Comment                                                                                                   	|
|----------------:	|-----------------------------------------------------------------------------------------------------	|-----------------------------------------------------------------------------------------------------------	|
| Microcontroller 	| ESP32-WROOM-32E                                                                                     	|                                                                                                           	|
|         Storage 	| 8MB                                                                                                 	| Wear levelling consideration, 1.9MB app storage & 190kb SPIFFS for access control log - updatable via OTA 	|
|   Communication 	| BLE 4.2 & WiFi 2.4Ghz                                                                               	|                                                                                                           	|
|           Audio 	| Piezo speaker                                                                                       	|                                                                                                           	|
|          Visual 	| Blue & green LED                                                                                    	| Red LED is present, but wonkey                                                    	|
|            RFID 	| NXP MFRC522 13.56MHZ                                                                                	|                                                                                                           	|
|             RTC 	| MCP7940                                                                                             	|                                                                                                           	|
|          Sensor 	| SHTC3 Temperature & Humidity                                                                        	|                                                                                                           	|
|           Ports 	| Micro USB                                                                                           	|                                                                                                           	|
|              IO 	| 5V output, GND, 2 pins from ESP32 (IO33, IO26), HS (12V / Input Voltage), LS (ground toggle), + / - 	|                                                                                                           	|
|      Dimensions 	| 73mm x 64mm x 9mm                                                                                   	| Pins are not soldered on                                                                                  	|
|           Power 	| All features: 8 - 12V via Pins (+ / -)<br>Low Power Mode: 5V via USB                                	|                                                                                                           	|
|     I2C Address 	| 0x6F - RTC MCP7940 Functions<br>0x57 - RTC MCP7940 ROM<br>0x60 - LED Driver<br>0x70 - SHTC3 Sensor  	|                                                                                                           	|
