// definities van animaties en ledstrip
// effecten leds
#define EFFLED_AAN     10
#define EFFLED_GLOW    12
#define EFFLED_UIT     13

typedef struct {
  char    desc[20];
  int     pin1;
  int     pin2;
  int     pwm_channel;
  int     bri;    //255 mogelijkheden
  unsigned long timeon;
  unsigned long timeoff;
  long    timeeffect;  //negatieve waarden toelaten
  uint8_t effect;
} str_ledsingle;


#define LED_NR_ITEMS 5
const str_ledsingle LED_DEFAULT[LED_NR_ITEMS] {
//    description (20) ,pin1, pin2, cha, brigh,timeon,timeoff,timeeff, eff
 {"Boven1        ",  0,    5 ,   0,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"2             ",  1,    6,    1,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"3             ",  2,    7,    2,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"4             ",  3,    8,    3,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"Onder5        ",  4,    9,    4,   125, 10000,   1000,   2500, EFFLED_GLOW }
};

str_ledsingle ledsingle[LED_NR_ITEMS];
unsigned long timer_led_aan[LED_NR_ITEMS];
unsigned long time_led_eff[LED_NR_ITEMS];  //van begin aan tot eind van effect (gaat dus over meerder effecten heen)
uint8_t effectledbri[LED_NR_ITEMS];
