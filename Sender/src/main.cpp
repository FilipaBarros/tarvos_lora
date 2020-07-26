
#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#define LED 5
 
void loop() {
  delay(500);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
}

int counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  while (!Serial);

  Serial.println("LoRa Sender");
  LoRa.setPins(4, 17, 2);
  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);
  digitalWrite(LED,HIGH);
  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;
  delay(1000);
  digitalWrite(LED,LOW);
  delay(4000);
}