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


#define LED_NR_ITEMS 10
const str_ledsingle LED_DEFAULT[LED_NR_ITEMS] {
// descr  ,pin1, pin2, cha, brigh,timeon,timeoff,timeeff, eff
 {"12R   ", 14,   32 ,   0,   125,   500,    500,    150, EFFLED_AAN  , IMG_BOVEN1}
,{"14R   ", 27,   32,    1,   125,   500,    500,    150, EFFLED_AAN  , IMG_2     }
,{"16R   ", 26,   32,    2,   125,   500,    500,    150, EFFLED_AAN  , IMG_3     }
,{"18R   ", 25,   32,    3,   125,   500,    500,    150, EFFLED_AAN  , IMG_4     }
,{"20R   ", 33,   32,    4,   125,   500,    500,    150, EFFLED_AAN , IMG_ONDER5}
,{"11L   ", 16,   32,    5,   125,   500,    500,    150, EFFLED_AAN  , IMG_BOVEN1}
,{"13L   ", 17,   32,    6,   125,   500,    500,    150, EFFLED_AAN  , IMG_2     }
,{"15L   ", 18,   32,    7,   125,   500,    500,    150, EFFLED_AAN  , IMG_3     }
,{"17L   ", 22,   32,    8,   125,   500,    500,    150, EFFLED_AAN  , IMG_4     }
,{"19L   ", 23,   32,    9,   125,   500,    500,    150, EFFLED_AAN  , IMG_ONDER5}
};

str_ledsingle ledsingle[LED_NR_ITEMS];     //variabele om de waarden in bij te houden (default, uitlezen of aangepast)
unsigned long timer_led_aan[LED_NR_ITEMS];
unsigned long time_led_eff[LED_NR_ITEMS];  //van begin aan tot eind van effect (gaat dus over meerder effecten heen)
uint8_t effectledbri[LED_NR_ITEMS];
