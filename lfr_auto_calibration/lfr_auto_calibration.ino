int th[8];
int sen_pins[8] = {A7, A6, A5, A4, A3, A2, A1, A0};

int black_line[8];
int white_line[8];
void blink_times(int times);
void blink_fast_times(int times);

void setup() {
  // put your setup code here, to run once:
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

void loop() {
  // put your main code here, to run repeatedly:



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
