// P01.12V-2021.11 by InstaNFC
// Sample Code
// Feature: NFC 

// Check serial monitor for output

#include <SPI.h>
// Library required: https://github.com/miguelbalboa/rfid
#include "MFRC522.h"

#define SCK (18)
#define MOSI (23)
#define MISO (19)
#define SS (5)
#define RST (4)

MFRC522 rfid(SS, RST); 

void setup() {
  Serial.begin(115200);
  delay(1000);
  setupNFC();
}

void loop() {
  loopNFC();
}

void setupNFC() {
  SPI.begin();
  rfid.PCD_Init(); 
  recoverNFC();
}

void loopNFC() {
  if (rfid.PCD_ReadRegister(MFRC522::TModeReg) != 0x80) {
    recoverNFC();
    delay(50);
  }

  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;
  rfid.PICC_DumpToSerial(&(rfid.uid));
}

void recoverNFC() {
  rfid.PCD_WriteRegister(MFRC522::TxModeReg, 0x00);
  rfid.PCD_WriteRegister(MFRC522::RxModeReg, 0x00);
  rfid.PCD_WriteRegister(MFRC522::ModWidthReg, 0x26);
  rfid.PCD_WriteRegister(MFRC522::TModeReg, 0x80);
  rfid.PCD_WriteRegister(MFRC522::TPrescalerReg, 0xA9);
  rfid.PCD_WriteRegister(MFRC522::TReloadRegH, 0x03);
  rfid.PCD_WriteRegister(MFRC522::TReloadRegL, 0xE8);
  rfid.PCD_WriteRegister(MFRC522::TxASKReg, 0x40);
  rfid.PCD_WriteRegister(MFRC522::ModeReg, 0x3D);
  rfid.PCD_AntennaOn();
  rfid.PCD_SetAntennaGain(MFRC522::RxGain_43dB);
}
