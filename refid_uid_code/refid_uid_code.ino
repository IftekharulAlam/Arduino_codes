#include<MFRC522.h>
#include<SPI.h>

#define RST_PIN         5          // Configurable, see typical pin layout above
#define SS_PIN          53
MFRC522 mfrc522(SS_PIN, RST_PIN);
void setup()
{
  Serial.begin(9600);
  SPI.begin();
  Serial.print("#ACCESS CONTROL#");
  Serial.print("    Scan Tag");
  mfrc522.PCD_Init();
  Serial.println("Scan Tag");
}
void loop()
{
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  String uid = "";
  Serial.println();
  Serial.print("UID=");
  for (int i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    uid.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
    uid.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  uid.toUpperCase();
  if (uid == "8A3F3015")
  {
    Serial.print(":Dwij Patel");
    Serial.print(" ACCESS GRANTED");
    Serial.print("  Dwij Patel");

  }


  Serial.print("    Scan Tag");
  return;
}
