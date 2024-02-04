void setupLed(){
  // leds initialiseren met default
  for (size_t lednr = 0; lednr < LED_NR_ITEMS; lednr++) {
    
    ledsingle[lednr] = LED_DEFAULT[lednr];
    pinMode(ledsingle[lednr].pin1, OUTPUT);
    pinMode(ledsingle[lednr].pin2, OUTPUT);
    ledcSetup(ledsingle[lednr].pwm_channel, PWM_FREQUENCY, PWM_RESOLUTION);  //eenmalig frequentie opzetten
    ledcAttachPin(ledsingle[lednr].pin1, ledsingle[lednr].pwm_channel);       //pin aan pwm channel hangen
    ledcAttachPin(ledsingle[lednr].pin2, ledsingle[lednr].pwm_channel);       
  }

  Println("Pins defined as output");
}