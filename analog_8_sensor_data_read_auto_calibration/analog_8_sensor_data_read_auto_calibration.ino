
int th[8];
int sen_pins[8] = {A7, A6, A5, A4, A3, A2, A1, A0};
int sen[8]; int s[8];

int black_line[8];
int white_line[8];
void blink_times(int times);
void blink_fast_times(int times);
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
    for (int i = 0; i < 8; i++)
  {

    black_line[i] = analogRead(sen_pins[i]);
  }
  blink_fast_times(5);


  for (int i = 0; i < 8; i++)
  {
    white_line[i] = analogRead(sen_pins[i]);
  }


  for (int i = 0; i < 8; i++)
  {
    th[i] =  (black_line[i] +  white_line[i]) / 2;
  }
  blink_times(3);
}

// the loop routine runs over and over again forever:
void loop() {
  int i;
  for (i = 0; i < 8; i++)
  {
    sen[i] = analogRead(sen_pins[i]);
    if (sen[i] < th[i])
    {
      s[i] = 1;
    }
    else {
      s[i] = 0;
    }
  }
      Serial.print("Thersholds = ");

   for (i = 0; i < 8; i++)
  {

    Serial.print(th[i]);
    Serial.print(" ");

  }
    Serial.println();
    Serial.print("Analogs Now = ");

  for (i = 0; i < 8; i++)
  {

    Serial.print(sen[i]);
    Serial.print(" ");

  }
  Serial.println();

  for (i = 0; i < 8; i++)
  {

    Serial.print(s[i]);
    Serial.print(" ");

  }
  Serial.println();
  delay(1000);
}
void blink_times(int times) {
  for (int i = 0 ; i < times; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    delay(2000);
  }
}
void blink_fast_times(int times) {
  for (int i = 0 ; i < times; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    delay(1000);
  }
}
