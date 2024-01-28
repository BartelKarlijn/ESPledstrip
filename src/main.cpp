#include <0main\0include.h>

// =======================================================================================
// Setup
// =======================================================================================
void setup() {
  setupSerial();
  get_datafrom_eeprom (); // parameters uit eeprom halen (oa ssid/pw en PID)
  startWifi();
  setupPins();
  setupSpiffs();          // van het ESP32 file systeem lezen
//  setupLed();
//  loadAnimatie();         // ini file, terugvallen naar default
  SetupFinished();
}
void loop() {
  currentMillis = millis();
  ElegantOTA.loop();
  
  ledcWrite(PWM_CHANNEL_R1, 255);
  delay(2000);
  ledcWrite(PWM_CHANNEL_R1, 125);
  delay(2000);
  ledcWrite(PWM_CHANNEL_R1, 0);
  delay(2000);
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(PWM_CHANNEL_R1, dutyCycle);
    delay(15);
  }
  ledcWrite(PWM_CHANNEL_R1, 0);
  delay(2000);
  show_fps();    // print om de zoveel tijd de fps

}
