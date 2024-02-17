#pragma once
String  fileSaveSingle(int kringnr) {
// Save Kring settings to file
  char filename[18];
  JsonDocument doc;

  sprintf(filename, "/cfg_kring%02d.ini", kringnr);

  Print("Filename ");
  Println(String(filename));

  // write variables to JSON file
  doc["desc"]        = ledsingle[kringnr].desc;
  doc["pin1"]        = ledsingle[kringnr].pin1;
  doc["pin2"]        = ledsingle[kringnr].pin2;
  doc["pwm_channel"] = ledsingle[kringnr].pwm_channel;
  doc["timeoff"]     = ledsingle[kringnr].timeoff;
  doc["timeeffect"]  = ledsingle[kringnr].timeeffect;
  doc["effect"]      = ledsingle[kringnr].effect;
  doc["timeon"]      = ledsingle[kringnr].timeon;
  doc["bri"]         = ledsingle[kringnr].bri;
  doc["image"]       = ledsingle[kringnr].image;

  // write config file
  String tmp = "";
  serializeJson(doc, tmp);
  writeFile(SPIFFS, filename, tmp);
  
  return "Settings bewaard voor " + ledsingle[kringnr].desc;
}
