#include <SPI.h>

//Controller Pins
#define CSN_PIN 2 // Chip select not
#define CE_PIN 3 // Chip enable
#define MOSI_PIN 11 //Master out, slave in (Tx only)
#define SCK_PIN 13 //Serial Clock

//Joystick Analog Pins
#define VRX_PIN A0
#define VRY_PIN A1

//Communication
#define HEADER_BYTE 0xAA

void setup() {
  pinMode(CE_PIN, OUTPUT);
  pinMode(CSN_PIN, OUTPUT);
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(SCK_PIN, OUTPUT);

  digitalWrite(CE_PIN, LOW);
  digitalWrite(CSN_PIN, HIGH);
  digitalWrite(SCK_PIN, LOW);

  SPI.begin();
}

void loadByte(byte data) {
  digitalWrite(CSN_PIN, LOW);
  SPI.transfer(data);
  digitalWrite(CSN_PIN, HIGH);
}

void sendPacket(uint16_t vrx, uint16_t vry) {
  digitalWrite(CE_PIN, LOW);
  loadByte(HEADER_BYTE);
  loadByte((vrx >> 8) & 0xFF); //VRX HIGH
  loadByte((vrx & 0xFF)); //VRX LOW
  loadByte((vry >> 8) & 0xFF); //VRY HIGH
  loadByte((vry & 0xFF)); //VRY LOW
  digitalWrite(CE_PIN, HIGH); 
  delayMicroseconds(10) //CE needs to be high for at least 10 microseconds to transmit data
}

void loop() {
  uint16_t VRX = analogRead(VRX_PIN);
  uint16_t VRY = analogRead(VRY_PIN);

  sendPacket(VRX, VRY);

  delay(10);
}
