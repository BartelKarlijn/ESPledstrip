// definities van animaties en ledstrip
// effecten leds
#define EFFLED_UIT     10
#define EFFLED_AAN     11
#define EFFLED_GLOW    12

//jpeg files
#define IMG_BOVEN1 "file_img_1.png"
#define IMG_2      "file_img_2.png"
#define IMG_3      "file_img_3.png"
#define IMG_4      "file_img_4.png"
#define IMG_ONDER5 "file_img_5.png"

typedef struct {
  String  desc;
  int     pin1;
  int     pin2;
  int     pwm_channel;
  unsigned long timeon;
  unsigned long timeoff;
  long    timeeffect;  //negatieve waarden toelaten
  int     bri;    //255 mogelijkheden
  uint8_t effect;
  String  image;
} str_ledsingle;


#define LED_NR_ITEMS 5
const str_ledsingle LED_DEFAULT[LED_NR_ITEMS] {
// description    ,pin1, pin2, cha, brigh,timeon,timeoff,timeeff, eff
 {"Boven1        ",  0,    5 ,   0,   125, 10000,   1000,    150, EFFLED_AAN  , IMG_BOVEN1}
,{"2             ",  1,    6,    1,   125, 10000,   1000,    150, EFFLED_AAN  , IMG_2     }
,{"3             ",  2,    7,    2,   125, 10000,   1000,    150, EFFLED_AAN  , IMG_3     }
,{"4             ",  3,    8,    3,   125, 10000,   1000,    150, EFFLED_AAN  , IMG_4     }
,{"Onder5        ",  4,    9,    4,   125, 10000,   1000,   2500, EFFLED_GLOW , IMG_ONDER5}
};

str_ledsingle ledsingle[LED_NR_ITEMS];     //variabele om de waarden in bij te houden (default, uitlezen of aangepast)
unsigned long timer_led_aan[LED_NR_ITEMS];
unsigned long time_led_eff[LED_NR_ITEMS];  //van begin aan tot eind van effect (gaat dus over meerder effecten heen)
uint8_t effectledbri[LED_NR_ITEMS];
