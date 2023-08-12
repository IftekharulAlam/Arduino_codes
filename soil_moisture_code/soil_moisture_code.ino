/*** www.arduinopoint.com ***/
/*** Arduino Soil Moisture Sensor Project***/
/*
 # the sensor value description
 # 0 ~300 dry soil
 # 300~700 humid soil
 # 700~950 in water
*/
int sensorPin = A0; // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor
void setup(){
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}
void loop(){
 // Get a reading from the Moisture sensor:
  sensorValue = analogRead(sensorPin);  
/*------Display Moisture Sensor Value in Serial Monitor------*/
 Serial.print("Moisture Sensor Value:");
 Serial.println(sensorValue); 
 //Display the Moisture Percentage
 float moisturePercentage = 100 -( (sensorValue / 1023.00) * 100);
 Serial.print("Moisture Percentage = ");
 Serial.print(moisturePercentage);
 Serial.print("%\n");
 

 
 Serial.print("\n");
 delay(500);
} 
