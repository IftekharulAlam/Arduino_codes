 String TEAM_ID="1041";
 String MISSION_TIME=""; 
 String PACKET_COUNT; 
 String MODE;
 String STATE; 
 String ALTITUDE;
String HS_DEPLOYED; 
String PC_DEPLOYED; 
String MAST_RAISED; 
String TEMPERATURE; 
String VOLTAGE;
String PRESSURE; 
String GPS_TIME; 
String GPS_ALTITUDE; 
String GPS_LATITUDE; 
String GPS_LONGITUDE;
String GPS_SATS;
String TILT_X; 
String TILT_Y; 
String CMD_ECHO;

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  String m = TEAM_ID, MISSION_TIME, PACKET_COUNT, MODE, STATE, ALTITUDE,
HS_DEPLOYED, PC_DEPLOYED, MAST_RAISED, TEMPERATURE, VOLTAGE,
PRESSURE, GPS_TIME, GPS_ALTITUDE, GPS_LATITUDE, GPS_LONGITUDE,
GPS_SATS, TILT_X, TILT_Y, CMD_ECHO
  Serial.println(m);
  delay(1000);

}
