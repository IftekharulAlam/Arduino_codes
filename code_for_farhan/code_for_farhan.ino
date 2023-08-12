int threshold[5] = {147,155,177,173,36};

int digital_value[5];
void setup()
{
 Serial.begin(9600);
 

}
void loop()
{
   for (int i = 0; i <= 4; i++)
 {
 if (analogRead(i) < threshold[i]) digital_value[i] = 1;
 else digital_value[i] = 0;
 Serial.print(digital_value[i]);
 Serial.print(" ");
 }
 Serial.println(" ");

}

  
