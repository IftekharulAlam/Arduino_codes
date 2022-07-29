#define BUTTON_UP 2
#define BUTTON_RIGHT 3
#define BUTTON_DOWN 4
#define BUTTON_LEFT 5
#define BUTTON_E 6
#define BUTTON_F 7
#define DELAY 500
#define PIN_ANALOG_X 0

#define PIN_ANALOG_Y 1


void setup() {

 Serial.begin(9600);
 // to enable pull up resistors first write pin mode

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


Serial.write("S");
delay(1000);
 }

 else if(digitalRead(BUTTON_RIGHT) == LOW) {


Serial.write("R");
delay(1000);

 }

 else if(digitalRead(BUTTON_DOWN) == LOW) {

Serial.write("O");
delay(1000);

 }

 else if(digitalRead(BUTTON_LEFT) == LOW) {

Serial.write("L");
delay(1000);
 }
 
 else if(analogRead(PIN_ANALOG_Y) > 600){
  Serial.write("L");
delay(1000);
  }
  else if(analogRead(PIN_ANALOG_Y) == 0){
  Serial.write("R");
delay(1000);
  }
   else if(analogRead(PIN_ANALOG_X) > 600){
  Serial.write("F");
delay(1000);
  }
  else if(analogRead(PIN_ANALOG_X) == 0){
  Serial.write("B");
delay(1000);
  }
 else if(analogRead(PIN_ANALOG_X) == 0 && analogRead(PIN_ANALOG_Y) > 600){
  //Serial.write("");
   Serial.write("H");
delay(1000);
  }

}
