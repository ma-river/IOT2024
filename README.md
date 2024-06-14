
# Security Alarm system
Embedded Systems IoT Course

**Motivation**

- The motivation for the system is a modern dilemma regarding the safety and security of your home

**Objective**

- A system that provides monitoring of your house in an accessible manner and communicates with you in real-time through something that is always in your sight: your mobile device.

**Architecture**
- The project architecture begins with an ESP32 microcontroller interfaced with an ultrasonic sensor, which detects the presence of people. When the sensor detects movement, the ESP32 communicates this information to Node-RED using the WebSocket protocol. Node-RED receives the data and processes it according to predefined rules. Upon detecting the presence of people, Node-RED triggers an action to send a notification via WhatsApp (WPP), alerting about the presence of individuals. Additionally, the architecture includes an ESP32-CAM that communicates via an HTTP web server, sending real-time images to the Node-RED dashboard and taking photos whenever the sensor is activated. This setup seamlessly integrates sensor data acquisition, microcontroller logic, middleware processing with Node-RED, and real-time communication through WhatsApp, enabling effective monitoring and notification of people's presence with visual confirmation.
 ![architecture](https://github.com/ma-river/IOT2024/blob/main/Images/Architecture.jpeg)

[link for installation guide](https://github.com/ma-river/IOT2024/tree/main/Installation%20Guide)


