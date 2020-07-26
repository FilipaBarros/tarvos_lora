#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#define LED D4

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  while (!Serial);

  Serial.println("LoRa Receiver");
  //LoRa.setPins(ss, reset, dio0)
  LoRa.setPins(D8, D1, D2);

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  digitalWrite(LED,HIGH);
}

void loop() {
  // try to parse packet
  //Serial.print("Tou aqui");
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    digitalWrite(LED,LOW);
    // received a packet
    Serial.print("Received packet '");
    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    
    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
    digitalWrite(LED,HIGH);
  }
}