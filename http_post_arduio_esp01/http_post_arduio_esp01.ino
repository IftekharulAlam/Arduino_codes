#include <SoftwareSerial.h>

SoftwareSerial esp(2, 3); // RX, TX
String SSI ="dhong";
String PASS= "01521439838";
#define TIME_IP "api.timezonedb.com"

void setup()
{
  Serial.begin(9600);
  esp.begin(115200);
  Init();
}

void loop()
{
  updateTS();
  delay(100000);
}
//
int updateTS()
{
  String res;
  String subStr;
  int index;
  String cmd = "AT+CIPSTART=1,\"TCP\",\"";// Setup TCP connection
  cmd += TIME_IP;
  cmd += "\",80";
  esp.println(cmd);
  delay(2000);
  if ( Serial.find( "Error" ) )
  {
    esp.print( "RECEIVED: Error\nExit1" );
    return -1;
  }
  delay(100);
  String cmd1 = "GET 192.168.0.2/SS_IOT/esp-data.php HTTP/1.1";
  String cmd2 = "Host: api.timezonedb.com";
  String cmd3 = "Connection: keep-alive";
 
  esp.print( "AT+CIPSEND=1," );
  esp.println("137");
  if (esp.find(">"))
  {
    Serial.println("Ready");
  }
  esp.println(cmd1);
  esp.println(cmd2);
  esp.println(cmd3);
  esp.println();
  delay(500);
  res = esp.readString();
  index = res.indexOf("formatted");
  subStr = res.substring(index+12, index+28);
  Serial.print(subStr);
  //Serial.print(res);
  esp.println( "AT+CIPCLOSE" );//close TCP connection
  return 0;
}

void Init()
{
  esp.println("AT");
  if (esp.find("OK"))
    Serial.println("Ready.");

    String cmd = "AT+CWJAP=\"" + SSI + "\",\"" + PASS + "\"";

  esp.println(cmd);
  delay(5000);

  if (esp.find("OK"))
  {
    Serial.println("WiFi connected");
  }
  else
  {
    Serial.println("WiFi Not connected");
  }
}
