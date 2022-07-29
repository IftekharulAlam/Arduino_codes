#define BUTTON_UP 2
#define BUTTON_RIGHT 3
#define BUTTON_DOWN 4
#define BUTTON_LEFT 5
#define BUTTON_E 6
#define BUTTON_F 7
#define DELAY 0
#define PIN_ANALOG_X 0

#define PIN_ANALOG_Y 1
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";


void setup() {

// Serial.begin(9600);
 // to enable pull up resistors first write pin mode
 radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setChannel(1);
  radio.stopListening();
 // and then make that pin HIGH

 pinMode(BUTTON_UP, INPUT);
 digitalWrite(BUTTON_UP, HIGH);
 
 pinMode(BUTTON_RIGHT, INPUT);
 digitalWrite(BUTTON_RIGHT, HIGH);
 
 pinMode(BUTTON_DOWN, INPUT);
 digitalWrite(BUTTON_DOWN, HIGH);
 
 pinMode(BUTTON_LEFT, INPUT);
 digitalWrite(BUTTON_LEFT, HIGH);
 
 pinMode(BUTTON_E, INPUT);
 digitalWrite(BUTTON_E, HIGH);

 pinMode(BUTTON_F, INPUT);
 digitalWrite(BUTTON_F, HIGH);

}

void loop() {

 if(digitalRead(BUTTON_UP) == LOW) {


char text[] = "L";
 radio.write(&text, sizeof(text));
delay(DELAY);
 }

 else if(digitalRead(BUTTON_RIGHT) == LOW) {

char text[] = "F";
 radio.write(&text, sizeof(text));
delay(DELAY);

 }

 else if(digitalRead(BUTTON_DOWN) == LOW) {

char text[] = "R";
 radio.write(&text, sizeof(text));
delay(DELAY);

 }

 else if(digitalRead(BUTTON_LEFT) == LOW) {

char text[] = "B";
 radio.write(&text, sizeof(text));
delay(DELAY);
 }
 
 else if(analogRead(PIN_ANALOG_Y) > 600){
  char text[] = "F";
 radio.write(&text, sizeof(text));
delay(DELAY);
  }
  else if(analogRead(PIN_ANALOG_Y) == 0){
  //Serial.write("R");
  char text[] = "B";
 radio.write(&text, sizeof(text));
delay(DELAY);
  }
   else if(analogRead(PIN_ANALOG_X) > 600){
  //Serial.write("L");
  char text[] = "R";
 radio.write(&text, sizeof(text));
delay(DELAY);
  }
  else if(analogRead(PIN_ANALOG_X) == 0){
  //Serial.write("");
  char text[] = "L";
 radio.write(&text, sizeof(text));
delay(DELAY);
  }
  else if(analogRead(PIN_ANALOG_X) > 600 && analogRead(PIN_ANALOG_Y) > 600){
  //Serial.write("");
  char text[] = "RF";
 radio.write(&text, sizeof(text));
delay(DELAY);
  }
  else if((analogRead(PIN_ANALOG_X) == 0) && (analogRead(PIN_ANALOG_Y) > 600)){
  //Serial.write("");
  char text[] = "G";
 radio.write(&text, sizeof(text));
delay(DELAY);
  }
  else if(analogRead(PIN_ANALOG_X) > 600 && analogRead(PIN_ANALOG_Y) == 0){
  //Serial.write("");
  char text[] = "RB";
 radio.write(&text, sizeof(text));
delay(DELAY);
  }
  else if(analogRead(PIN_ANALOG_X) == 0 && analogRead(PIN_ANALOG_Y) == 0){
  //Serial.write("");
  char text[] = "LB";
 radio.write(&text, sizeof(text));
delay(DELAY);
  }
else{
  char text[] = "S";
 radio.write(&text, sizeof(text));
delay(DELAY);
  
  }

}
