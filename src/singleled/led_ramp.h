#pragma once

void led_ramp(int lednr) {
  // Ramping up for timeEffect
  // Keeping on for timeOn
  // Ramping down for timeEffect
  unsigned long timeBezig;
  uint8_t bri_glow;

  timeBezig  = currentMillis - time_fase_beg[lednr];
  if( timeBezig >= time_fase_end[lednr] ) {   // naar de volgende fase
    fase[lednr]++;
    time_fase_beg[lednr] = currentMillis;
    switch (fase[lednr]){
      case 1:  //up fase
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeeffect;
        break;        
      case 2:  //on fase
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeon;
        break;        
      case 3:  //donw fase
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeeffect;
        break;        
      case 4:  //off fase
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeoff;
        break;        
      default: //5 door ophoging of iets anders: gewoon zelfde als fase1
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeeffect;
        fase[lednr] = 1;
        break;
    }
  }

  switch (fase[lednr])
  {
  case 1: // up
    bri_glow = map(timeBezig, time_fase_beg[lednr],  time_fase_end[lednr], 0, ledsingle[lednr].bri);
    break;
  case 2: // on
    bri_glow = ledsingle[lednr].bri;
    break;
  case 3: // down
    bri_glow = map(timeBezig, time_fase_beg[lednr], time_fase_end[lednr], ledsingle[lednr].bri, 0);
    break;
  case 4: // off
    bri_glow = 0;
    break;
  default:
    bri_glow = 0;
    break;
  }
  ledcWrite(ledsingle[lednr].pwm_channel, bri_glow);
}
