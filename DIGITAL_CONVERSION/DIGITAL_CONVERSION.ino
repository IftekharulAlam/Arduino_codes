int threshold[6] = {757,756,858,760,760,760};

int digital_value[6];
void setup()
{
 Serial.begin(9600);
}
void loop()
{
   for (int i = 0; i <= 5; i++)
 {
 if (analogRead(i) < threshold[i]) digital_value[i] = 1;
 else digital_value[i] = 0;
 Serial.print(digital_value[i]);
 Serial.print(" ");
 }
 Serial.println(" ");

}

  
