**Step 1: Assemble the sensor**

The materials you need for this project.

- Esp32

- HC-SR04

<img src="/Images/Conections_esp32_sensor_ultrasonic.png"> 



Pinout HC-SR04


- VCC  -> VCC


- Trig -> GPIO 12


- Echo -> GPIO 13


- GND  -> GND

**The whole circuit on breadboard**

 ![Whole circuit](https://github.com/ma-river/IOT2024/blob/main/Images/whole_circuit.jpeg)

**Step 2: Esp32 code**

For the project, you'll need to download Projeto_semb_iot and add the "ultrasonic.h" 
library to use the ultrasonic sensor, the "WiFi.h" library for 
the ESP to access the internet, and "ESPAsyncWebServer.h" and 
"AsyncTCP.h" libraries to create and communicate with the web socket, 
respectively.

In this part of the code 

const char* ssid = "SSID";

const char* password = "Password"; 

you should input your internet's SSID and password.

**Step 3: Node-Red**

In Node-RED, you should download the libraries "node-red-contrib-whatsapp-cmb" and "node-red-dashboard". 
Next, download the "security_alarm_flow" file and import it into Node-RED. 
Finally, replace the IP address in the WebSocket node of Node-RED with the IP address of your board, found in the serial monitor of the ".ino" code.

**Step 3.1: Dashboard**

To use the dasboard you must access the following link http://127.0.0.1:1880/ui.
The dasboard enable the user to turn the alarm on and off using a boton.

**Step 4: Whatsapp bot**

To access the bot, you need to add the number +34 644 81 58 78 to your phone and send the message "i allow callmebot to send me messages" via WhatsApp. 
The bot will then provide you with an API key. This key will be used in the configuration of the "node-red-contrib-whatsapp-cmb" block within the Account option. 
Here, you will configure your name, your phone number including the country code and area code, and this API key.
