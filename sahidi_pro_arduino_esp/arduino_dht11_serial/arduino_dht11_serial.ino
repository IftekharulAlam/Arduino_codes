//#include <SoftwareSerial.h>


int temp,humi;
String str;
//SoftwareSerial Serial(2, 3); // RX, TX

void setup(){
 Serial.begin(115200);
}
void loop()
{
//  DHT.read11(DHT11_PIN);
//  humi=DHT.humidity;
//  temp=DHT.temperature;
  humi=10;
  temp=10;
  Serial.print("H: ");
  Serial.print(humi); 
  Serial.print("% ");
  Serial.print(" T: ");
  Serial.print(temp); 
  Serial.print(char(176));
  Serial.println("C");
  str =String('H')+String(humi)+String('T')+String(temp);
  Serial.println(str);
  delay(1000);
}
