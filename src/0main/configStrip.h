// definities van animaties en ledstrip
// effecten leds
#define EFFLED_UIT     10
#define EFFLED_AAN     11
#define EFFLED_GLOW    12
#define EFFLED_RAMP    13
#define EFFLED_RAND    14

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


#define LED_NR_ITEMS 1
const str_ledsingle LED_DEFAULT[LED_NR_ITEMS] {
// description    ,pin1, pin2, cha, brigh,timeon,timeoff,timeeff, eff
 {"Boven1        ",  2,    3 ,   0,   125, 10000,   1000,    150, EFFLED_AAN  , IMG_BOVEN1}
};

str_ledsingle ledsingle[LED_NR_ITEMS];     //variabele om de waarden in bij te houden (default, uitlezen of aangepast)
unsigned long timer_led_aan[LED_NR_ITEMS];
unsigned long time_fase_beg[LED_NR_ITEMS];  //begin van een nieuwe fase
unsigned long time_fase_end[LED_NR_ITEMS];  //eind van een nieuwe fase
uint8_t fase[LED_NR_ITEMS];  //welke fase zitten we (bv ramp fase 1=up, 2=on, 3=down, 4=off)

uint8_t effectledbri[LED_NR_ITEMS];
