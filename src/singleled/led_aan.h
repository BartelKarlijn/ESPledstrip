#pragma once

void led_aan(int lednr) {
  // Keeping on for timeOn
  // Keeping on for timeOff
  unsigned long timeBezig;
  uint8_t bri_glow;

  timeBezig  = currentMillis - time_fase_beg[lednr];
  if( timeBezig >= time_fase_end[lednr] ) {   // naar de volgende fase
    fase[lednr]++;
    time_fase_beg[lednr] = currentMillis;
    switch (fase[lednr]){
      case 1:  //on fase
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeon;
        break;        
      case 2:  //off fase
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeoff;
        break;        
      default: //3 door ophoging of iets anders: gewoon zelfde als fase1
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeeffect;
        fase[lednr] = 0;
        break;
    }
  }
  
  switch (fase[lednr])
  {
  case 1: // on
    bri_glow = ledsingle[lednr].bri;
    break;
  case 2: // off
    bri_glow = 0;
    break;
  default:
    bri_glow = 0;
    break;
  }
  ledcWrite(ledsingle[lednr].pwm_channel, bri_glow);
}
