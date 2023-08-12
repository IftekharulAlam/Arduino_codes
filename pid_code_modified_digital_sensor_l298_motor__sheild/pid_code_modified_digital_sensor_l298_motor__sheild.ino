
#include <SoftwareSerial.h> 
#include <AFMotor.h> 

AF_DCMotor motor_one(1); // create motor #1, 1KHz pwm
AF_DCMotor motor_two(2); 
const int irPins[5] = {A4,A3,A2,A1,A0};

void wheel(int lm, int rm);
int s[5] = {0,0,0,0,0}; 
int i, lastSensor,lastError;
int uturn = 255;
int base_L=250;
int base_R=250;
float kp=3;
float kd=1;

void setup()
{
 //Serial.begin(9600);
  mot_init();
  other_init();

}
void loop()
{ 
  //line_follow();
wheel(200,200);
}


void other_init()
{
  lastSensor=0;
  lastError=0;
  //Serial.begin(9600);
}

void mot_init()
{
 

}

void wheel(int lm, int rm)
{
  if(lm==0)
  {
      motor_one.run(RELEASE);
  }
  if(lm>0)
  {
     motor_one.run(FORWARD);
  }
  else if(lm<0)
  {
     motor_one.run(BACKWARD);
  }
  if(rm==0)
  { 
motor_two.run(RELEASE);
  }
  if(rm>0)
  {
    
motor_two.run(FORWARD); 
  }
  else if(rm<0)
  {
motor_two.run(BACKWARD); 
  }
  if(lm>254) lm=254;
  if(lm<-254) lm=-254;
  if(rm>254) rm=254;
  if(rm<-254) rm=-254;
  

  motor_one.setSpeed(lm);
motor_two.setSpeed(rm); 
  
}

int readSensor()
{
   
    s[0]=digitalRead(irPins[0]);
    s[1]=digitalRead(irPins[1]);
    s[2]=digitalRead(irPins[2]);
    s[3]=digitalRead(irPins[3]);
    s[4]=digitalRead(irPins[4]);
    s[0]=1-s[0];
    s[1]=1-s[1];
    s[2]=1-s[2];
    s[3]=1-s[3];
    s[4]=1-s[4];
  int error,sum;
  sum=s[0]+s[1]+s[2]+s[3]+s[4];
  if(sum!=0)
  {
    error=(s[0]*10+s[1]*20+s[2]*30+s[3]*40+s[4]*50)/sum-30;
  }
  else
  {
     error=420;
  }
  
  if(s[0]==1) lastSensor=1;
  else if(s[4]==1) lastSensor=2;
  //Serial.print(error);
  //Serial.print(" ");
  return error;
}
 

void line_follow()
{
  int error,corr;
  float p,d;
 error=readSensor();
 if(error==420)
 {
   if(lastSensor==1) wheel(-uturn,uturn);
   else if(lastSensor==2) wheel(uturn,-uturn);
 }
 else 
 { 
   p=kp*error;
   d=kd*(error-lastError);
   corr=p+d;
  // Serial.println(corr);
   wheel(base_L+corr,base_R-corr);
   if((error-lastError)!=0) delay(5);
   lastError=error; 
 }
}
