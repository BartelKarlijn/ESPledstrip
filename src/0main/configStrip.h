// definities van animaties en ledstrip
// effecten leds
#define EFFLED_AAN     10
#define EFFLED_GLOW    12
#define EFFLED_UIT     13

typedef struct {
  char    desc[20];
  int     pin;
  int     pwm_channel;
  int     bri;    //255 mogelijkheden
  unsigned long timeon;
  unsigned long timeoff;
  long    timeeffect;  //negatieve waarden toelaten
  uint8_t effect;
} str_ledsingle;


#define LED_NR_ITEMS 10
const str_ledsingle LED_DEFAULT[LED_NR_ITEMS] {
//    description (20) ,pin, cha, brigh,timeon,timeoff,timeeff, eff
 {"LinksBoven1        ",  0,   0,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"Links2             ",  1,   1,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"Links3             ",  2,   2,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"Links4             ",  3,   3,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"LinksOnder5        ",  4,   4,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"RechtsBoven6       ",  5,   5,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"Rechts7            ",  6,   6,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"Rechts8            ",  7,   7,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"Rechts9            ",  8,   8,   125, 10000,   1000,    150, EFFLED_AAN  }
,{"RechtsOnder10      ",  9,   9,   125, 10000,   1000,    150, EFFLED_AAN  }
};

str_ledsingle ledsingle[LED_NR_ITEMS];
unsigned long timer_led_aan[LED_NR_ITEMS];
unsigned long time_led_eff[LED_NR_ITEMS];  //van begin aan tot eind van effect (gaat dus over meerder effecten heen)
uint8_t effectledbri[LED_NR_ITEMS];
