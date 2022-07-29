void other_init()
{
  lastSensor=0;
  lastError=0;
  for(int j=0; j<100; j++)
  {
    path[j]=0;
  }
  p=0;
  Serial.begin(9600);
}

void mot_init()
{
  pinMode(inA,OUTPUT);
  pinMode(inB,OUTPUT);
  pinMode(inC,OUTPUT);
  pinMode(inD,OUTPUT);

  
  digitalWrite(inA,HIGH);
  digitalWrite(inB,HIGH);
  digitalWrite(inC,HIGH);
  digitalWrite(inD,HIGH);
}
