String TEAM_ID = "1041";
String MISSION_TIME = "13:14:02";
int PACKET_COUNT = 0;
String MODE = "F";
String STATE = "LAUNCH_WAIT";
String ALTITUDE = "26.5";
String HS_DEPLOYED = "P";
String PC_DEPLOYED = "C";
String MAST_RAISED = "M";
String TEMPERATURE = "35.0";
String VOLTAGE = "5.0";
String PRESSURE = "25.0";
String GPS_TIME = "13:14:02";
String GPS_ALTITUDE = "35.0";
String GPS_LATITUDE = "25.0";
String GPS_LONGITUDE = "24.0";
String GPS_SATS = "20";
String TILT_X = "5.0";
String TILT_Y = "5.0";
String CMD_ECHO = "CXON";

void setup() {

  Serial.begin(115200);
}

void loop() {


  String m = TEAM_ID + "," + MISSION_TIME + "," + String(PACKET_COUNT) + "," + MODE + "," + STATE + "," + ALTITUDE + "," + HS_DEPLOYED + "," + PC_DEPLOYED + "," + MAST_RAISED + "," + TEMPERATURE + "," + VOLTAGE + "," + PRESSURE + "," + GPS_TIME + "," + GPS_ALTITUDE + "," + GPS_LATITUDE + "," + GPS_LONGITUDE + "," + GPS_SATS + "," + TILT_X + "," + TILT_Y + "," + CMD_ECHO;
  Serial.println(m);
  delay(1000);
PACKET_COUNT++;
}
