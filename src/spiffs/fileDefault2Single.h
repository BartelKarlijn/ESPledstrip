#pragma once
String  fileDefault2Single(int kringnr) {
// Load Kring settings from defaults stored hardcoded
  ledsingle[kringnr] = LED_DEFAULT[kringnr];

  return ("Default teruggezet voor " + ledsingle[kringnr].desc );
}
