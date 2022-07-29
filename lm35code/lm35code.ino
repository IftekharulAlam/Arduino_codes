int val;
int tempPin = 6;

void setup()
{
Serial.begin(9600);
}
void loop()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

//Serial.print("TEMPRATURE = ");
Serial.println(cel);
//Serial.print("*C");
//Serial.println();
delay(1000);
}
