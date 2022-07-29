
int th[8] = {467, 485, 448, 406, 382, 492, 451, 429};
int sen_pins[8] = {A7, A6, A5, A4, A3, A2, A1, A0};
int sen[8]; int s[8];
int a = 0; int error = 0;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int i;
  sen[3] = analogRead(sen_pins[3]);
  sen[4] = analogRead(sen_pins[4]);
  sen[5] = analogRead(sen_pins[5]);
  a = (sen[3]+sen[4]-2*sen[5])/2;
  error = sen[4] - sen[3] - 2*a*3-a;
  Serial.println(error);
  


}
