
int sen_pins[8] = {A7, A6, A5, A4, A3, A2, A1, A0};
int sen[8]; int s[8];
int Print3Smallest(int array[], int n);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int i;
  for (i = 0; i < 8; i++)
  {
    sen[i] = analogRead(sen_pins[i]);

  }
    for (i = 0; i < 8; i++)
  {

    Serial.print(sen[i]);
    Serial.print(" ");

  }
  Serial.println();

  Print3Smallest(sen, 8);


  delay(1000);
}
int Print3Smallest(int array[], int n)
{
  int MAX = 1200;
 
  int firstmin = MAX, secmin = MAX, thirdmin = MAX;
  for (int i = 0; i < n; i++)
  {
    /* Check if current element is less than
      firstmin, then update first, second and
      third */
    if (array[i] < firstmin)
    {
      thirdmin = secmin;
      secmin = firstmin;
      firstmin = array[i];
    }

    /* Check if current element is less than
      secmin then update second and third */
    else if (array[i] < secmin)
    {
      thirdmin = secmin;
      secmin = array[i];
    }

    /* Check if current element is less than
      then update third */
    else if (array[i] < thirdmin)
      thirdmin = array[i];
  }

  Serial.print(firstmin);
  Serial.print(" ");

  Serial.print(secmin);
  Serial.print(" ");
  Serial.print(thirdmin);
  Serial.println(" ");

}
