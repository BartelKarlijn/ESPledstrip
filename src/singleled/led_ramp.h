#pragma once

void led_ramp(int lednr) {
  // Ramping up for timeEffect
  // Keeping on for timeOn
  // Ramping down for timeEffect
  unsigned long timeBezig;
  unsigned long timeEffect;
  uint8_t bri_glow;

  if( currentMillis >= time_fase_end[lednr] ) {   // naar de volgende fase
    fase[lednr]++;
    time_fase_beg[lednr] = currentMillis;
    switch (fase[lednr]){
      case 1:  //up fase
        Println("fase1");
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeeffect;
        break;        
      case 2:  //on fase
        Println("fase2");
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeon;
        break;        
      case 3:  //donw fase
        Println("fase3");
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeeffect;
        break;        
      case 4:  //off fase
        Println("fase4");
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeoff;
        break;        
      default: //5 door ophoging of iets anders: gewoon zelfde als fase1
        Println("fase5");
        time_fase_end[lednr] = currentMillis + ledsingle[lednr].timeeffect;
        fase[lednr] = 0;
        break;
    }
  }

  timeBezig  = currentMillis - time_fase_beg[lednr];
  timeEffect = time_fase_end[lednr] - time_fase_beg[lednr];
  switch (fase[lednr])
  {
  case 1: // up
    bri_glow = map(timeBezig, 0,  timeEffect, 0, ledsingle[lednr].bri);
    break;
  case 2: // on
    bri_glow = ledsingle[lednr].bri;
    break;
  case 3: // down
    bri_glow = map(timeBezig, 0, timeEffect, ledsingle[lednr].bri, 0);
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
