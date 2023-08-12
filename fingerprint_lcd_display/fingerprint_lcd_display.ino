#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Servo.h>
Servo myservo;
#include <Adafruit_Fingerprint.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

int fingerprintID = 0;

String IDname;

void setup() {  
    finger.begin(57600);
   // Serial.begin(9600);
myservo.attach(9);
if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } 
  else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
//   put your setup code here, to run once:
lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
lcd.backlight();//To Power ON the back light

 lcd.setCursor(0,0);
lcd.print("___Bank Vault___");
myservo.write(60); 
}

void loop() {
//myservo.write(2); 
//remember adding a while(True) loop here
  fingerprintID = getFingerprintIDez();
  delay(50);
 if(fingerprintID==1){
  lcd.setCursor(4,1);
    lcd.print("UNLOCKED");  
    myservo.write(2);         
  }  
  delay(6000);
  myservo.write(60); 
  lcd.setCursor(4,1);
    lcd.print("  LOCKED");          
  
}
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
//  Serial.print("Found ID #"); 
//  Serial.print(finger.fingerID); 
//  Serial.print(" with confidence of "); 
//  Serial.println(finger.confidence);
  return finger.fingerID; 
}
