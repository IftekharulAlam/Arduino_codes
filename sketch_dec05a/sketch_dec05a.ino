#include<MFRC522.h>
#include<SPI.h>

#define RST_PIN         D2          // Configurable, see typical pin layout above
#define SS_PIN          D8
MFRC522 mfrc522(SS_PIN, RST_PIN);
void setup()
{
  pinMode(D4, OUTPUT);
  SPI.begin();
  Serial.begin(115200);
  mfrc522.PCD_Init();
  digitalWrite(D4, HIGH);

}
void loop()
{

  if (mfrc522.PICC_IsNewCardPresent())
  {
    if (mfrc522.PICC_ReadCardSerial())
    {
      String uid = "";

      for (int i = 0; i < mfrc522.uid.size; i++)
      {

        uid.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
        uid.concat(String(mfrc522.uid.uidByte[i], HEX));
      }
      uid.toUpperCase();

      if (uid == "6A758407")
      {
        Serial.println("1");
        digitalWrite(D4, LOW);
      }
      if (uid == "6B86CC21")
      {
        Serial.println("2");
        digitalWrite(D4, LOW);
      }
      if (uid == "3AFA8A07")
      {
        Serial.println("3");
        digitalWrite(D4, LOW);

      }
      if (uid == "2B2BB821")
      {
        Serial.println("4");
        digitalWrite(D4, LOW);
      }
    }
  }
  else {
    digitalWrite(D4, HIGH);
  }





}
