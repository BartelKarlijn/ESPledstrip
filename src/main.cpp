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
//  loadAnimatie();         // ini file, terugvallen naar default
  SetupFinished();
}
void loop() {
  currentMillis = millis();
  delay(10);
  ElegantOTA.loop();
  
  showled();
  show_fps();    // print om de zoveel tijd de fps

}
