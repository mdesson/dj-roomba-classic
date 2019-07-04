#include <SoftwareSerial.h>

// Roomba Notes
// 128: Start
// 131: Safe mode
// 132: Full mode
// 173: Stop
// 133: Power Off
// pin constants

const int ddPin = 5;
const int rxPin=10;
const int txPin=11;

// Create Roomba
SoftwareSerial Roomba(rxPin, txPin);

void setup() {
  // Set up Serial Ports
  Serial.begin(19200);
  Roomba.begin(19200);
  pinMode(ddPin, OUTPUT);
  delay(1000);

  // Wake up Roomba
  Serial.println("Waking up Roomba");
  digitalWrite(ddPin, HIGH);
  delay(100);
  digitalWrite(ddPin, LOW);
  delay(500);
  digitalWrite(ddPin, HIGH);
  delay(2000);
  Serial.println("Roomba awake");

  // Start and set to full mode
  Roomba.write(128);
  Roomba.write(132);
  delay(1000);

  Serial.println("Placing Mario theme in slot 1 and slot 2");
  Roomba.write("\x8c\x01\x0c\x4c\x0c\x4c\x0c\x14\x0c\x4c\x0c\x14\x0c\x48\x0c\x4c\x0c\x14\x0c\x4f\x0c\x14\x24\x43\x0c\x14\x24");
  Roomba.write("\x8c\x02\x0c\x4c\x0c\x4c\x0c\x14\x0c\x4c\x0c\x14\x0c\x48\x0c\x4c\x0c\x14\x0c\x4f\x0c\x14\x24\x43\x0c\x14\x24");
  Serial.println("Playing Slot 1");
  Roomba.write("\x8d\x01"); // [141] [1] play it (in slot 1)
  Serial.println("Waiting 3 seconds");
  delay(3000);
  Serial.println("Playing Slot 2");
  Roomba.write("\x8d\x02"); // [141] [1] play it (in slot 1)
  Serial.println("Waiting 3 seconds");
  delay(3000);
  // Shut down roomba
  Serial.println("Stopping Roomba");
  Roomba.write(133);
}

void loop() {

}