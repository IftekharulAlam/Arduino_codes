void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A4, INPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
}

void loop() {

  // put your main code here, to run repeatedly:
  int sensor1 = digitalRead(A0);
  int sensor2 = digitalRead(A1);
  int sensor3 = digitalRead(A2);
  int sensor4 = digitalRead(A3);
  int sensor5 = digitalRead(A4);
//  sensor1 =  1  - sensor1;
//  sensor2 =  1  - sensor2;
//  sensor3 =  1  - sensor3;
//  sensor4 =  1  - sensor4;
//  sensor5 =  1  - sensor5;




  Serial.print(sensor1);
  Serial.print(" ");
  Serial.print(sensor2);
  Serial.print(" ");
  Serial.print(sensor3);
  Serial.print(" ");
  Serial.print(sensor4);
  Serial.print(" ");
  Serial.print(sensor5);
  Serial.println(" ");


}
