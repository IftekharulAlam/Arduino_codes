#define light_one_pin 4
#define light_two_pin 5
#define light_three_pin 6
#define light_four_pin 7
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
char incomingByte=0; // for incoming serial data

void light_one_on();
void light_one_off();
void light_two_on();
void light_two_off();
void light_three_on();
void light_three_off();
void light_four_on();
void light_four_off();

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
mySerial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0) {
    incomingByte = mySerial.read();
    }
  switch(incomingByte)
  {
     
     case '1':
        
      { light_one_on();
       Serial.println("Light one is on \n");
       incomingByte='*';}
     break;
    case '2':
      { 
        light_one_off();
       Serial.println("Light one is off \n");
       incomingByte='*';}
     break;
    case '3':
      { 
      light_two_on();
       Serial.println("Light two is on \n");
       incomingByte='*';}
     break; 
        case '4':
      { 
        light_two_off();
       Serial.println("Light two is off \n");
       incomingByte='*';}
     break; 
        case '5':
      { 
       light_three_on();
       Serial.println("Light three is on \n");
       incomingByte='*';}
     break; 
        case '6':
      { 
        light_three_off();
 
       Serial.println("Light three is off \n");
       incomingByte='*';}
     break; 
        case '7':
      { 
      light_four_on();
       Serial.println("Light four is on \n");
       incomingByte='*';}
     break; 
        case '8':
      { 
        light_four_off();

       Serial.println("Light four is off \n");
       incomingByte='*';}
     break; 
    
       
  }

}
void light_one_on(){
  digitalWrite(light_one_pin,LOW);
  };
void light_one_off(){
   digitalWrite(light_one_pin,HIGH);
  
  };
void light_two_on(){
   digitalWrite(light_two_pin,LOW);
  
  };
void light_two_off(){
   digitalWrite(light_two_pin,HIGH);
  
  };
void light_three_on(){
   digitalWrite(light_three_pin,LOW);
  
  };
void light_three_off(){
   digitalWrite(light_three_pin,HIGH);
  };
void light_four_on(){
   digitalWrite(light_four_pin,LOW);
  
  };
void light_four_off(){
   digitalWrite(light_four_pin,HIGH);
  };
