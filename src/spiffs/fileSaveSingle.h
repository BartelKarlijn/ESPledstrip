#pragma once
String  fileSaveSingle(int lednr) {
// Save Kring settings to file
  char filename[18];
  JsonDocument doc;

  sprintf(filename, "/cfg_string%02d.ini", lednr);

  Print("Filename ");
  Println(String(filename));

  // write variables to JSON file
  doc["desc"]        = ledsingle[lednr].desc;
  doc["pin1"]        = ledsingle[lednr].pin1;
  doc["pin2"]        = ledsingle[lednr].pin2;
  doc["pwm_channel"] = ledsingle[lednr].pwm_channel;
  doc["timeoff"]     = ledsingle[lednr].timeoff;
  doc["timeeffect"]  = ledsingle[lednr].timeeffect;
  doc["effect"]      = ledsingle[lednr].effect;
  doc["timeon"]      = ledsingle[lednr].timeon;
  doc["bri"]         = ledsingle[lednr].bri;
  doc["image"]       = ledsingle[lednr].image;

  // write config file
  String tmp = "";
  serializeJson(doc, tmp);
  writeFile(SPIFFS, filename, tmp);
  
  return "Settings bewaard voor " + ledsingle[lednr].desc;
}
