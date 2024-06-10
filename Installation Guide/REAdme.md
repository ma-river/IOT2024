**Step 1: Assemble the sensor**

The materials you need for this project.

- Esp32

- HC-SR04
  
**Observer Esp32 pinout**
  
![pinout](https://github.com/ma-river/IOT2024/blob/main/Images/esp32-pinout-reference-wroom-devkit.png)

**Assemble Esp32 to HC-SR04**

<img src="/Images/Conections_esp32_sensor_ultrasonic.png"> 



Pinout HC-SR04


- VCC  -> VCC


- Trig -> GPIO 12


- Echo -> GPIO 13


- GND  -> GND

**The whole circuit on breadboard**

 ![Whole circuit](https://github.com/ma-river/IOT2024/blob/main/Images/whole_circuit.jpeg)

**Step 2: Esp32 code**

**Step 2.1: Sensor**

For the project, you'll need to download Projeto_semb_iot and add the "ultrasonic.h" 
library to use the ultrasonic sensor, the "WiFi.h" library for 
the ESP to access the internet, and "ESPAsyncWebServer.h" and 
"AsyncTCP.h" libraries to create and communicate with the web socket, 
respectively.

In this part of the code 

const char* ssid = "SSID";

const char* password = "Password"; 

you should input your internet's SSID and password.

**Step 2.2: Esp32 Cam**

In the board manager, it is important to install version 2.0.2 because the more recent versions are presenting bugs.

In the code, you should replace the SSID and password with the network address.

To upload the file, select the "ESP32 Wrover Module" board. Select "Huge APP" in the Partition Scheme, otherwise the code will not compile because it is too large.

**Step 3: Node-Red**

In Node-RED, you should download the libraries "node-red-contrib-whatsapp-cmb" and "node-red-dashboard". 
Next, download the "Semb_IOT_2024.json" file and import it into Node-RED.

**Step 3.1: Sensor**

Finally, replace the IP address in the WebSocket node of Node-RED with the IP address of your board, found in the serial monitor of the ".ino" code.

**Step 3.2: Cam**

The address retrieved in the camera code will be used to replace the IP address spaces in the following blocks:

You need to change the IP in the blocks:

- Brightness control
- Contrast control
- Led intensity
- Display Stream
- Capture Image
  
Additionally, you need to replace "C:/prints/" in the Save Image block with the path where you want to save the screenshot.

It is important that Node-RED has access to the directory where you want to save the image.

**Step 3.3: Dashboard**
 
To use the dasboard you must access the following link http://127.0.0.1:1880/ui.

On the dashboard, it is possible to enable or disable the camera stream. The screenshot button is intended to take a snapshot of the screen and save it to a specified folder within the computer's directory. When the sensor is activated, a screenshot is also taken.

Some functions for controlling the camera include:

- LED Intensity: Adjusts the brightness of an LED on the board.
  
- Contrast and Brightness: These functions adjust the image itself on the dashboard.
  
- Sensor Activation: Allows the sensor to be enabled or disabled and includes a count of how many times the sensor has been activated.

<img src="/Images/Dashboard.jpeg">

**Step 4: Whatsapp bot**

To access the bot, you need to add the number +34 644 81 58 78 to your phone and send the message "i allow callmebot to send me messages" via WhatsApp. 
The bot will then provide you with an API key. This key will be used in the configuration of the "node-red-contrib-whatsapp-cmb" block within the Account option. 
Here, you will configure your name, your phone number including the country code and area code, and this API key.

