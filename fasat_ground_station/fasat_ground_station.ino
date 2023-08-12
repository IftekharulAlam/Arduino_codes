void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String m = "1040,13:14:02.22,1,F,LAUNCH_WAIT,12.1,P,C,M,30.1,4.5,13:14:02.22,12.1,24.0001,23.0001,4,12.01,23.01,CXON";
  Serial.println(m);
  delay(1000);

}
