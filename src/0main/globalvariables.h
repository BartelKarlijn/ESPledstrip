//////////////// OPERATION ///////////////////////
Preferences pref_eeprom;           // to store & read parameters from eprom

//////// Wifi //////////
// Create AsyncWebServer object on port 80
//AsyncWebServer webserver(80);
//DNSServer dnsServer;    //Even afgezet want voor eigen AP wellicht niet nodig
String wifi_ssid ;
String wifi_pwd  ;
String wifi_scan;         //Lijst met scan van wifi netwerken
String listFiles(bool ishtml = false);

bool   flagWifiOn = false;
const char* PARAM_ssid   = "ssid";     // voor de asyncwebserver
const char* PARAM_pwd    = "pwd" ;     // voor de asyncwebserver


//////// Encoder //////////
RotaryEncoder rotaryEncoder(PIN_ENCODER_A, PIN_ENCODER_B, PIN_ENCODER_SW);

//////// Timing //////////
unsigned long currentMillis;
unsigned long ota_progress_millis;
unsigned long fpsMillis;
unsigned long cntfps = 1;  // we willen geen 0 om eventuele delingen door 0 te vermijden
