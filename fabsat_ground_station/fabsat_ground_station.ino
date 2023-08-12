void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("1041,13:14:02.22,1,F,LAUNCH_WAIT,25.1,P,C,M,32.1,5.1,6:07:00,25.1,24.1,23.1,5,5.1,5.0,CXON");
  delay(1000);
}
