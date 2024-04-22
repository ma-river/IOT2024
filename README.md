
# Security Alarm via WhatsApp
Embedded Systems IoT Course

**Motivation**

- Insecurity regarding the protection of your home

**Objective**

- A system that provides monitoring of your house in an accessible manner and communicates with you in real-time through something that is always in your sight: your mobile device.

**Architecture**
- The project architecture begins with an ESP32 microcontroller interfaced with an ultrasonic sensor, which detects the presence of people. When the sensor detects movement, the ESP32 communicates this information to Node-RED using WebSocket protocol. Node-RED, receives the data and processes it according to predefined rules. Upon detecting the presence of people, Node-RED triggers an action to send a notification via WhatsApp (WPP), alerting about the presence of individuals. This architecture seamlessly integrates sensor data acquisition, microcontroller logic, middleware processing with Node-RED, and real-time communication through WhatsApp, enabling effective monitoring and notification of people's presence.
 ![architecture](https://github.com/ma-river/IOT2024/blob/main/Blank%20board.png)
