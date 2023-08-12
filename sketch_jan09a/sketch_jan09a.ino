void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(16, INPUT);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = digitalRead(14);
  int b = digitalRead(15);
  int c = digitalRead(16);

  Serial.print(a);
  Serial.print(" ");
  Serial.print(b);
  Serial.print(" ");
  Serial.print(c);
  Serial.println();
delay(1000);


}
