const int potPin = A0; //Pot at Arduino A0 pin 
//Variables:
int value ; //Value from pot

void setup() {

  //Start the serial communication
  Serial.begin(9600); //Baud rate must be the same as is on xBee module
digitalWrite(8,LOW);
}

void loop() {
    
    //Read the analog value from pot and store it to "value" variable
    value = analogRead(A0);
    //Map the analog value to pwm value
    value = map (value, 0, 1023, 0, 255);
  //Send the message:
  Serial.print('<');  //Starting symbol
  Serial.print(value);//Value from 0 to 255
  Serial.println('>');//Ending symbol


}
