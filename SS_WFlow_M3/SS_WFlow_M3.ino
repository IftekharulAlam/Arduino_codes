
signed short minutesl, secondes;

int pin = 9;
int Repeat_Time=2;

int sigk;

int Pump_Time = 1;
int counte = 0;
int Menu_Pin = 2;
int ledPin1=3;
int ledPin2=4;
int ledPin3=5;
int ledPin4=6;
int ledPin5=7;
void ledON(int ledNumber){
  
  if(ledNumber == 1){
    digitalWrite(ledPin1, HIGH);
     digitalWrite(ledPin2, LOW);
     digitalWrite(ledPin3, LOW);
     digitalWrite(ledPin4, LOW);
     digitalWrite(ledPin5, LOW);
    }
     if(ledNumber == 2){
    digitalWrite(ledPin2, HIGH);
     digitalWrite(ledPin1, LOW);
     digitalWrite(ledPin3, LOW);
     digitalWrite(ledPin4, LOW);
     digitalWrite(ledPin5, LOW);
    }
     if(ledNumber == 3){
    digitalWrite(ledPin3, HIGH);
     digitalWrite(ledPin2, LOW);
     digitalWrite(ledPin1, LOW);
     digitalWrite(ledPin4, LOW);
     digitalWrite(ledPin5, LOW);
    
    }
     if(ledNumber == 4){
    digitalWrite(ledPin4, HIGH);
     digitalWrite(ledPin2, LOW);
     digitalWrite(ledPin3, LOW);
     digitalWrite(ledPin1, LOW);
     digitalWrite(ledPin5, LOW);
    
    }
     if(ledNumber == 5){
    digitalWrite(ledPin5, HIGH);
     digitalWrite(ledPin2, LOW);
     digitalWrite(ledPin3, LOW);
     digitalWrite(ledPin4, LOW);
     digitalWrite(ledPin1, LOW);
    
    }


    
  
  };
void setupDevice(){



};
void setup() {
  pinMode(pin,OUTPUT);
  pinMode(Menu_Pin,INPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
  pinMode(ledPin5,OUTPUT);

  
    Repeat_Time = analogRead(A0);
    Repeat_Time = Repeat_Time/100;
   // ledON(Repeat_Time);

    Pump_Time = analogRead(A1);
    Pump_Time = Pump_Time/100;
      if(Pump_Time > 5 ){Pump_Time = 5;};
  if(Pump_Time < 1 ){Pump_Time = 1;};
    ledON(Pump_Time);

  

//    setupDevice();

  digitalWrite(pin,HIGH);

}

void loop() {
   sigk = digitalRead(Menu_Pin);

  
    if(sigk == HIGH){
      counte++;
      
      }
       if(counte > 3){
      counte = 0;
     
       }
       
  if (secondes == 60)
  {
    secondes = 0;
    minutesl++;
  }
  if(minutesl == Repeat_Time){
    digitalWrite(pin,LOW);
    
    }
if(minutesl == Repeat_Time+Pump_Time){
    secondes = 0;
    minutesl=0;
    digitalWrite(pin,HIGH);
    }
    if(counte > 0){
    

  Repeat_Time = analogRead(A0);
  Repeat_Time = Repeat_Time/100;
  
  Pump_Time = analogRead(A1);
  Pump_Time = Pump_Time/100;
  if(Pump_Time > 5 ){Pump_Time = 5;};
  if(Pump_Time < 1 ){Pump_Time = 1;};
    ledON(Pump_Time);


   secondes = 0;
    minutesl=0;
 digitalWrite(pin,HIGH);
    }

 

else{

  
  delay(1000);
  secondes++;

  
  }     


    

}
