#include <Arduino.h>

void setup() {
   Serial.begin(9600); // must be same baudrate with the Serial Monitor
}

void loop() {
  Serial.print("Connecting to ");
  delay(1000);
}