int ENA_for_one = 10;
int INA_for_one = 36;
int INB_for_one = 34;
int INC_for_one = 32;
int IND_for_one = 30;
int ENB_for_one = 11;
//----
int ENA_for_two = 9;
int INA_for_two = 22;
int INB_for_two = 24;
int INC_for_two = 26;
int IND_for_two = 28;
int ENB_for_two = 8;

int incomingByte=0; // for incoming serial data
int speed_min = 135; //the minimum "speed" the motors will turn - take it lower and motors don't turn
int speed_max = 255; //

int speed_left = speed_max; // set both motors to maximum speed
int speed_right = speed_max;

void left();
void right();
void forward();
void backward();
void forward_left();
void forward_right();
void back_left();
void back_right();
void setup() {
  Serial.begin(9600);
pinMode(ENA_for_one,OUTPUT);
pinMode(INA_for_one,OUTPUT);
pinMode(INB_for_one,OUTPUT);
pinMode(INC_for_one,OUTPUT);
pinMode(IND_for_one,OUTPUT);
pinMode(ENB_for_one,OUTPUT);
//---
pinMode(ENA_for_two,OUTPUT);
pinMode(INA_for_two,OUTPUT);
pinMode(INB_for_two,OUTPUT);
pinMode(INC_for_two,OUTPUT);
pinMode(IND_for_two,OUTPUT);
pinMode(ENB_for_two,OUTPUT);
}

void loop() {

if (Serial.available() > 0) {
    incomingByte = Serial.read();
    }
  switch(incomingByte)
  {
     case 'S':
      {
        stopo();
       //Serial.println("Stop\n"); 
       incomingByte='*';}
     break;
     
     case 'F':
      
     {  forward();
       
      // Serial.println("Forward\n");
       incomingByte='*';}
     break;
    
      case 'B':
       
    {   backward();
      // Serial.println("Backward\n");
       incomingByte='*';}
     break;
     
     case 'R':
     // turn right
     {  
       right(); 
      // Serial.println("Rotate Right\n");
       incomingByte='*';}
     break;
       case 'L':
      { 
       left();     
       //Serial.println("Rotate Left\n");
       incomingByte='*';}
     break;
     case '1':
        
      { speed_left = 100; 
       speed_right = 100;
       //Serial.println("Speed 1\n");
       incomingByte='*';}
     break;
    case '2':
      { 
        speed_left = 130; 
       speed_right = 130;
       //Serial.println("Speed 2 \n");
       incomingByte='*';}
     break;
    case '3':
      { 
        speed_left = 140; 
       speed_right = 140;
       //Serial.println("Speed 3 \n");
       incomingByte='*';}
     break; 
        case '4':
      { 
        speed_left = 150; 
       speed_right = 150;
       //Serial.println("Speed 4 \n");
       incomingByte='*';}
     break; 
        case '5':
      { 
        speed_left = 170; 
       speed_right = 170;
       //Serial.println("Speed 5 \n");
       incomingByte='*';}
     break; 
        case '6':
      { 
        speed_left = 180; 
       speed_right = 180;
       //Serial.println("Speed 6 \n");
       incomingByte='*';}
     break; 
        case '7':
      { 
        speed_left = 200; 
       speed_right = 200;
      // Serial.println("Speed 7 \n");
       incomingByte='*';}
     break; 
        case '8':
      { 
        speed_left = 210; 
       speed_right = 210;
       //Serial.println("Speed 8 \n");
       incomingByte='*';}
     break; 
        case '9':
      { 
        speed_left = 220; 
       speed_right = 220;
       //Serial.println("Speed 9 \n");
       incomingByte='*';}
     break; 
        case 'q':
      { 
        speed_left = 255; 
       speed_right = 255;
       Serial.println("Speed full \n");
       incomingByte='*';}
     break; 
        case 'G':
      { 
       forward_left();
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;
      case 'I':
      { 
       forward_right();
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;
      case 'H':
      { 
       back_left();
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;
      case 'J':
      { 
       back_right();
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;      
  }

  
}
void forward(){
analogWrite(ENA_for_one,speed_left);
digitalWrite(INA_for_one,HIGH);
digitalWrite(INB_for_one,LOW);
digitalWrite(INC_for_one,HIGH);
digitalWrite(IND_for_one,LOW);
analogWrite(ENB_for_one,speed_left); 
analogWrite(ENA_for_two,speed_right);
digitalWrite(INA_for_two,HIGH);
digitalWrite(INB_for_two,LOW);
digitalWrite(INC_for_two,HIGH);
digitalWrite(IND_for_two,LOW);
analogWrite(ENB_for_two,speed_right); 
  };
void backward(){
   analogWrite(ENA_for_one,speed_left);
digitalWrite(INA_for_one,LOW);
digitalWrite(INB_for_one,HIGH);
digitalWrite(INC_for_one,LOW);
digitalWrite(IND_for_one,HIGH);
analogWrite(ENB_for_one,speed_left); 
//---
 
analogWrite(ENA_for_two,speed_right);
digitalWrite(INA_for_two,LOW);
digitalWrite(INB_for_two,HIGH);
digitalWrite(INC_for_two,LOW);
digitalWrite(IND_for_two,HIGH);
analogWrite(ENB_for_two,speed_right);
  };
void left(){
   analogWrite(ENA_for_one,speed_left);
digitalWrite(INA_for_one,LOW);
digitalWrite(INB_for_one,HIGH);
digitalWrite(INC_for_one,LOW);
digitalWrite(IND_for_one,HIGH);
analogWrite(ENB_for_one,speed_left); 
//---
analogWrite(ENA_for_two,speed_right);
digitalWrite(INA_for_two,HIGH);
digitalWrite(INB_for_two,LOW);
digitalWrite(INC_for_two,HIGH);
digitalWrite(IND_for_two,LOW);
analogWrite(ENB_for_two,speed_right); 
  };
void right(){
analogWrite(ENA_for_one,speed_left);
digitalWrite(INA_for_one,HIGH);
digitalWrite(INB_for_one,LOW);
digitalWrite(INC_for_one,HIGH);
digitalWrite(IND_for_one,LOW);
analogWrite(ENB_for_one,speed_left); 
//--
analogWrite(ENA_for_two,speed_right);
digitalWrite(INA_for_two,LOW);
digitalWrite(INB_for_two,HIGH);
digitalWrite(INC_for_two,LOW);
digitalWrite(IND_for_two,HIGH);
analogWrite(ENB_for_two,speed_right);
  
  };
void stopo(){
analogWrite(ENA_for_one,speed_left);
digitalWrite(INA_for_one,LOW);
digitalWrite(INB_for_one,LOW);
digitalWrite(INC_for_one,LOW);
digitalWrite(IND_for_one,LOW);
analogWrite(ENB_for_one,speed_left); 
//----
analogWrite(ENA_for_two,speed_right);
digitalWrite(INA_for_two,LOW);
digitalWrite(INB_for_two,LOW);
digitalWrite(INC_for_two,LOW);
digitalWrite(IND_for_two,LOW);
analogWrite(ENB_for_two,speed_right);
  
  };
void forward_right(){
analogWrite(ENA_for_one,speed_left);
digitalWrite(INA_for_one,HIGH);
digitalWrite(INB_for_one,LOW);
digitalWrite(INC_for_one,HIGH);
digitalWrite(IND_for_one,LOW);
analogWrite(ENB_for_one,speed_left); 
analogWrite(ENA_for_two,speed_right);
digitalWrite(INA_for_two,LOW);
digitalWrite(INB_for_two,LOW);
digitalWrite(INC_for_two,LOW);
digitalWrite(IND_for_two,LOW);
analogWrite(ENB_for_two,speed_right);
  
  };
void forward_left(){
  analogWrite(ENA_for_one,speed_left);
digitalWrite(INA_for_one,LOW);
digitalWrite(INB_for_one,LOW);
digitalWrite(INC_for_one,LOW);
digitalWrite(IND_for_one,LOW);
analogWrite(ENB_for_one,speed_left); 
  //---
analogWrite(ENA_for_two,speed_right);
digitalWrite(INA_for_two,HIGH);
digitalWrite(INB_for_two,LOW);
digitalWrite(INC_for_two,HIGH);
digitalWrite(IND_for_two,LOW);
analogWrite(ENB_for_two,speed_right); 
  };
void back_right(){
   analogWrite(ENA_for_one,speed_left);
digitalWrite(INA_for_one,LOW);
digitalWrite(INB_for_one,HIGH);
digitalWrite(INC_for_one,LOW);
digitalWrite(IND_for_one,HIGH);
analogWrite(ENB_for_one,speed_left); 
//----
analogWrite(ENA_for_two,speed_right);
digitalWrite(INA_for_two,LOW);
digitalWrite(INB_for_two,LOW);
digitalWrite(INC_for_two,LOW);
digitalWrite(IND_for_two,LOW);
analogWrite(ENB_for_two,speed_right);
  
  };
void back_left(){
  
 analogWrite(ENA_for_one,speed_left);
digitalWrite(INA_for_one,LOW);
digitalWrite(INB_for_one,LOW);
digitalWrite(INC_for_one,LOW);
digitalWrite(IND_for_one,LOW);
analogWrite(ENB_for_one,speed_left); 
//--
analogWrite(ENA_for_two,speed_right);
digitalWrite(INA_for_two,LOW);
digitalWrite(INB_for_two,HIGH);
digitalWrite(INC_for_two,LOW);
digitalWrite(IND_for_two,HIGH);
analogWrite(ENB_for_two,speed_right);
  };




