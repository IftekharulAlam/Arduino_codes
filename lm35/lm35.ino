
float t;
int reading;
int tempPin = 0;
int relay = 8;

void setup()
{
analogReference(INTERNAL);


}

void loop()
{
reading = analogRead(tempPin);
t = reading / 9.31;

}

