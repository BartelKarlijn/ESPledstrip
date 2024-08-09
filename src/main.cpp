#include <0main\0include.h>

// =======================================================================================
// Setup
// =======================================================================================
void setup() {
  setupSerial();
  get_datafrom_eeprom (); // parameters uit eeprom halen (oa ssid/pw en PID)
  startWifi();
  setupSpiffs();          // van het ESP32 file systeem lezen
  setupLed();
  setupEncoder();
  SetupFinished();
}
void loop() {
  currentMillis = millis();
//  ElegantOTA.loop();
  
  showled();
  show_fps();    // print om de zoveel tijd de fps

}
