
int th[6] = {730, 744, 722, 701, 642, 695};
int sen_pins[6] = {A0, A1, A2, A3, A4, A5};
int sen[6]; int s[6];
void setup() {
  // initialize Serial1 communication at 9600 bits per second:
  Serial1.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int i;
  for (i = 0; i < 6; i++)
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
  for (i = 0; i < 6; i++)
  {

    Serial1.print(sen[i]);
    Serial1.print(" ");

  }
  Serial1.println();

  for (i = 0; i < 6; i++)
  {

    Serial1.print(s[i]);
    Serial1.print(" ");

  }
  Serial1.println();
  delay(1000);
}
