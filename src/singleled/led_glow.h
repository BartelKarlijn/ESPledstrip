#pragma once

void led_glow(int lednr) {
  // Ramping up for timeEffect
  // Ramping down for timeEffect
  // repeating untill timeOn runs out.  Remark: we always do full glow cycle
  // keeping off for timeOff
  unsigned long timeBezig;
  unsigned long timeEffect;
  uint8_t bri_glow;

  if( currentMillis >= time_fase_end[lednr] ) {   // naar de volgende fase
    fase[lednr]++;
    time_fase_beg[lednr] = currentMillis;
    switch (fase[lednr]){
      case 1:  //eerste glow
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeeffect;
        timer_led_aan[lednr] = currentMillis + ledsingle[lednr].timeon;
        fase[lednr] = 2;
        break;        
      case 2:  //up fase
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeeffect;
        break;
      case 3:  //down fase
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeeffect;
        break;
      case 4:  //check if timeOn runs out
        if( currentMillis >= timer_led_aan[lednr]) {
          time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeoff;
          fase[lednr] = 5;
        }
        else { //nieuw rondje op/af
          time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeeffect;
          fase[lednr] = 2;
        }
        break;
      default: //6 door ophoging of iets anders: gewoon zelfde als fase1
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeeffect;
        timer_led_aan[lednr] = currentMillis + ledsingle[lednr].timeon;
        fase[lednr] = 0;
        break;
    }
  }

  timeBezig  = currentMillis - time_fase_beg[lednr];
  timeEffect = time_fase_end[lednr] - time_fase_beg[lednr];
  switch (fase[lednr])
  {
  case 2: // up
    bri_glow = map(timeBezig, 0,  timeEffect, 0, ledsingle[lednr].bri);
    break;
  case 3: // down
    bri_glow = map(timeBezig, 0,  timeEffect, ledsingle[lednr].bri, 0);
    break;
  case 5: // off
    bri_glow = 0;
    break;
  default:
    bri_glow = 0;
    break;
  }
  ledcWrite(ledsingle[lednr].pwm_channel, bri_glow);
}
