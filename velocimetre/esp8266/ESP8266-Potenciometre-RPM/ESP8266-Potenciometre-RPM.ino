#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define N 5
#define IP ""

const char* ssid     = "";
const char* password = "";
uint16_t tx = 45455;
WiFiUDP Udp;

void setup() {
  Serial.begin(115200);
  pinMode(A0,INPUT);
  connect();
  Serial.print("read");

}

void connect(){
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  pinMode(A0, INPUT);
}

void vSendVelocity(){
  Udp.beginPacket(IP, tx);
  Udp.print("km:");
  Udp.print(analogRead(A0));
  Udp.endPacket();
}

void vSendRPM(){
  Udp.beginPacket(IP, tx);
  Udp.print("rpm:");
  //Serial.println(analogRead(A0));
  Udp.print(analogRead(A0));
  Udp.endPacket();
}

long temps = millis();

void loop() {
  if(millis()-temps>=100){
    vSendRPM();
    temps=millis();
  }

  
  //Serial.println(analogRead(A0));

}
