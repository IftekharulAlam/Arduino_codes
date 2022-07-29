void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  Serial3.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial3.available())
  {
    char c = Serial3.read();
    Serial.println(c);

  }

}
