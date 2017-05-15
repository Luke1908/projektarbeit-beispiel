/**@file RFID-A02-A03.ino */

#include <SPI.h> // SPI-Bibiothek hinzufügen
#include <MFRC522.h> // RFID-Bibiothek hinzufügen

#include "registration.h"

#define SS_PIN 53 // Funduino MEGA Pin 53
#define RST_PIN 5 // Funduino MEGA Pin 5

Registration registration;

MFRC522 mfrc522(SS_PIN, RST_PIN); // RFID-Empfänger benennen


void setup() // Beginn des Setups:
{
  Serial.begin(9600); // Serielle Verbindung starten (Monitor)
  SPI.begin(); // SPI-Verbindung aufbauen
  mfrc522.PCD_Init(); // Initialisierung des RFID-Empfängers
}


void loop() // Hier beginnt der Loop-Teil
{
  if (!mfrc522.PICC_IsNewCardPresent()) // Wenn keine Karte in Reichweite ist...
  {
    return; // ...verlasse die Funktion
  }

  if (!mfrc522.PICC_ReadCardSerial()) // Wenn kein RFID-Sender ausgewählt wurde...
  {
    return; // ...verlasse die Funktion
  }

  if(mfrc522.uid.size == 4) // Es wird angenommen, dass die Tag-Ids 4 Byte gross sind
  {
    char const* rfidReadCode =  mfrc522.uid.uidByte;
    registration.registerPerson(rfidReadCode, 4);

    delay(2000); // 2 Sekunden warten, damit die Karte entfernt werden kann
    return;
  }
}
