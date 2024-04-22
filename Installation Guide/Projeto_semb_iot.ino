#include <Ultrasonic.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>

// Replace with your network credentials
const char* ssid = "mesh_24";
const char* password = "Ma101002";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

Ultrasonic ultrasonic(12, 13);
int distance;
int tem_gente = 0;
const int ledPin = 25;
bool sensorState = 0;

void notifyClients() {
  ws.textAll(String(tem_gente) + "," + String(sensorState));
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    if (strcmp((char*)data, "toggle") == 0) {
      sensorState = !sensorState;
      notifyClients();
    }
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
 void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

String processor(const String& var){
  Serial.println(var);
  if(var == "STATE"){
    if (sensorState){
      return "ON";
    }
    else{
      return "OFF";
    }
  }
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

void setup() {
 Serial.begin(9600);
 pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, LOW);
 WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.println("Connecting to WiFi..");
}

// Print ESP Local IP Address
Serial.println(WiFi.localIP());
initWebSocket();
server.begin();
  }


void loop() {
  ws.cleanupClients();
  digitalWrite(ledPin, sensorState);
  notifyClients();
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();
 if (distance < 30){
  tem_gente = 1;
 delay(1000);
 } else{
  delay(1000);
  tem_gente = 0;
  	}
}
