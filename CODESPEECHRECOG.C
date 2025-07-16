#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX for Voice module

#define RELAY1 8

void setup() {
  pinMode(RELAY1, OUTPUT);
  digitalWrite(RELAY1, LOW); // Initial state OFF
  
  Serial.begin(9600);
  mySerial.begin(9600);

  Serial.println("Voice Recognition Ready...");
}

void loop() {
  if (mySerial.available()) {
    int command = mySerial.read();

    switch (command) {
      case 0x11: // Assuming 0x11 = "LIGHT ON"
        digitalWrite(RELAY1, HIGH);
        Serial.println("LIGHT ON");
        break;
      case 0x12: // Assuming 0x12 = "LIGHT OFF"
        digitalWrite(RELAY1, LOW);
        Serial.println("LIGHT OFF");
        break;
      default:
        Serial.print("Unknown command: ");
        Serial.println(command, HEX);
        break;
    }
  }
}
