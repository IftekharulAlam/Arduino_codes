float kp = 8;
float kd = 15;
float ki = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    kp = Serial.parseFloat();
    kd = Serial.parseFloat();
    ki = Serial.parseFloat();
  }
  Serial.print(kp);
  Serial.print(" ");
  Serial.print(kd);
  Serial.print(" ");
  Serial.print(ki);
  Serial.println(" ");
  
}
