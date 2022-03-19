// P01.12V-2021.11 by InstaNFC
// Sample Code
// Feature: RTC 

// Check serial monitor for output

// Library required: https://github.com/Zanduino/MCP7940
#include "MCP7940.h"

MCP7940_Class MCP7940;

void setup() {
  Serial.begin(115200);
  delay(1000);

  setupTime();
}

void loop() {
  loopTime();
}

void setupTime() {
  Wire.begin();
  MCP7940.begin();
  MCP7940.deviceStart();
  MCP7940.setBattery(true);
}

void loopTime() {
  printTime();
  delay(1000);
}

void printTime() {
  char inputBuffer[32];
  DateTime now = MCP7940.now();
  sprintf(inputBuffer, "%04d-%02d-%02d %02d:%02d:%02d", now.year(),now.month(), now.day(), now.hour(), now.minute(), now.second());
  Serial.println(inputBuffer);     
}
