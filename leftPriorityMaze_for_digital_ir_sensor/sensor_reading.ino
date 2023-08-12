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
    error=((s[0]*10+s[1]*20+s[2]*30+s[3]*40+s[4]*50)/sum)-30;
  }
  else
  {
     error=420;
  }
  
  if(s[0]==1) lastSensor=1;
  else if(s[4]==1) lastSensor =2;
// Serial.println(error);
  return error;
}
