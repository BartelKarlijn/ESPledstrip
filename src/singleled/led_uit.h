#pragma once

void led_uit(int lednr) {
    ledcWrite(ledsingle[lednr].pwm_channel, 0);
}
