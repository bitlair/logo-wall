
#include <FastLED.h>

#define DJO_DATA_PIN 7
#define DJO_NUM_LEDS 129

CRGB djo_leds[DJO_NUM_LEDS];

// Aanknopje 0-26
// D buiten 27-50
// D binnen 51-67
// J 68-90
// O 91-126

#define BITLAIR_DATA_PIN 6
#define BITLAIR_NUM_LEDS 288
#define BITLAIR_ORANGE CRGB(244, 30, 0)

//  01                            
//  02                14          20
//  03 10 09    11    16 15       21             29       32       35 36
//  04    08    12    17          22                28    31    34
//  05 06 07    13       18 19       23 24    25 26 27    30    33

CRGB bitlair_leds[BITLAIR_NUM_LEDS];


#define ROWS 15
#define COLUMNS 51
const int16_t bitlair_grid[ROWS][COLUMNS] = {
  // B                                                     I               T                                                     L                                                     A                                                     I                  R
  {    1,   0,   7,     -1,  -1,  -1,     -1,  -1,  -1,    -1,  -1,  -1,    -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1 },
  {    2,  -1,   6,     -1,  -1,  -1,     -1,  -1,  -1,    -1,  -1,  -1,    -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1 },
  {    3,   4,   5,     -1,  -1,  -1,     -1,  -1,  -1,    -1,  -1,  -1,    -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1 },

  {    9,   8,  15,     -1,  -1,  -1,     -1,  -1,  -1,    -1,  -1,  -1,   105, 104, 111,     -1,  -1,  -1,     -1,  -1,  -1,    153, 152, 159,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1 },
  {   10,  -1,  14,     -1,  -1,  -1,     -1,  -1,  -1,    -1,  -1,  -1,   106,  -1, 110,     -1,  -1,  -1,     -1,  -1,  -1,    154,  -1, 158,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1 },
  {   11,  12,  13,     -1,  -1,  -1,     -1,  -1,  -1,    -1,  -1,  -1,   107, 108, 109,     -1,  -1,  -1,     -1,  -1,  -1,    155, 156, 157,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1 },

  {   17,  16,  23,     73,  72,  79,     65,  64,  71,    81,  80,  87,   121, 120, 127,    113, 112, 119,     -1,  -1,  -1,    161, 160, 167,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,    225, 224, 231,     -1,  -1,  -1,    249, 248, 255,     -1,  -1,  -1,    273, 272, 279,    281, 280, 287 },
  {   18,  -1,  22,     74,  -1,  78,     66,  -1,  70,    82,  -1,  86,   122,  -1, 126,    114,  -1, 118,     -1,  -1,  -1,    162,  -1, 166,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,    226,  -1, 230,     -1,  -1,  -1,    250,  -1, 254,     -1,  -1,  -1,    274,  -1, 278,    282,  -1, 286 },
  {   19,  20,  21,     75,  76,  77,     67,  68,  69,    83,  84,  85,   123, 124, 125,    115, 116, 117,     -1,  -1,  -1,    163, 164, 165,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,    227, 228, 229,     -1,  -1,  -1,    251, 252, 253,     -1,  -1,  -1,    275, 276, 277,    283, 284, 285 },

  {   25,  24,  31,     -1,  -1,  -1,     57,  56,  63,    89,  88,  95,   129, 128, 135,     -1,  -1,  -1,     -1,  -1,  -1,    169, 168, 175,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,    217, 216, 223,    241, 240, 247,    265, 264, 271,     -1,  -1,  -1,     -1,  -1,  -1 },
  {   26,  -1,  30,     -1,  -1,  -1,     58,  -1,  62,    90,  -1,  94,   130,  -1, 134,     -1,  -1,  -1,     -1,  -1,  -1,    170,  -1, 174,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,    218,  -1, 222,    242,  -1, 246,    266,  -1, 270,     -1,  -1,  -1,     -1,  -1,  -1 },
  {   27,  28,  29,     -1,  -1,  -1,     59,  60,  61,    91,  92,  93,   131, 132, 133,     -1,  -1,  -1,     -1,  -1,  -1,    171, 172, 173,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,     -1,  -1,  -1,    219, 220, 221,    243, 244, 245,    267, 268, 269,     -1,  -1,  -1,     -1,  -1,  -1 },

  {   33,  32,  39,     41,  40,  47,     49,  48,  55,    97,  96, 103,    -1,  -1,  -1,    137, 136, 143,    145, 144, 151,     -1,  -1,  -1,    177, 176, 183,    185, 184, 191,    193, 192, 199,    201, 200, 207,    209, 208, 215,    233, 232, 239,    257, 256, 263,     -1,  -1,  -1,     -1,  -1,  -1 },
  {   34,  -1,  38,     42,  -1,  46,     50,  -1,  54,    98,  -1, 102,    -1,  -1,  -1,    138,  -1, 142,    146,  -1, 150,     -1,  -1,  -1,    178,  -1, 182,    186,  -1, 190,    194,  -1, 198,    202,  -1, 206,    210,  -1, 214,    234,  -1, 238,    258,  -1, 262,     -1,  -1,  -1,     -1,  -1,  -1 },
  {   35,  36,  37,     43,  44,  45,     51,  52,  53,    99, 100, 101,    -1,  -1,  -1,    139, 140, 141,    147, 148, 149,     -1,  -1,  -1,    179, 180, 181,    187, 188, 189,    195, 196, 197,    203, 204, 205,    211, 212, 213,    235, 236, 237,    259, 260, 261,     -1,  -1,  -1,     -1,  -1,  -1 }
};

class Animation {
  public: 
    virtual void update() {}
    virtual bool finished() { return true; }
};

class BitlairScrollUp: public Animation {
  public:
    BitlairScrollUp(CRGB color);
    virtual void update();
    virtual bool finished();
  private:
    CRGB _color;
    long _lastUpdate;
    int _step;
};

class Static: public Animation {
  public:
    Static(CRGB color, int delay, CRGB *data, int numLeds);
    virtual void update();
    virtual bool finished();
  private:
    long _waitUntil;
};

class DJOLetters: public Animation {
  public:
    DJOLetters(CRGB color);
    virtual void update();
    virtual bool finished();
  private:
    long _lastUpdate;
    long _step;
    CRGB _color;
    void fillLetter(int from, int to);
};

class BitlairLetters: public Animation {
  public:
    BitlairLetters(CRGB color);
    virtual void update();
    virtual bool finished();
  private:
    long _lastUpdate;
    long _step;
    CRGB _color;
    void fillLetter(int from, int to);
};

class Snake: public Animation {
  public:
    Snake(CRGB color, int speed, CRGB *data, int numLeds);
    virtual void update();
    virtual bool finished();
  private:
    CRGB _color;
    CRGB* _data;
    int _numLeds;
    long _lastUpdate;
    int _step;  
    int _speed;
};

Animation *bitlairAnimation;
int bitlairAnimationNum;
Animation *djoAnimation;
int djoAnimationNum;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, DJO_DATA_PIN, GRB>(djo_leds, DJO_NUM_LEDS);
  FastLED.addLeds<SK6812, BITLAIR_DATA_PIN, GRB>(bitlair_leds, BITLAIR_NUM_LEDS);
  FastLED.setBrightness(200);

  for(int i = 0; i < DJO_NUM_LEDS; i++) { djo_leds[i] = CRGB::Black; }
  for(int i = 0; i < BITLAIR_NUM_LEDS; i++) { bitlair_leds[i] = CRGB::Black; }
  FastLED.show();
  
  Serial.begin(9600);

  bitlairAnimation = new Animation();
  djoAnimation = new Animation();
}

void selectDJOAnimation() {
  if (djoAnimation->finished()) {
    switch(djoAnimationNum) {
      case 0: 
        djoAnimation = new Snake(CRGB::Blue, 25, djo_leds, DJO_NUM_LEDS);
        break;
      case 1:
        djoAnimation = new Snake(CRGB::Black, 25, djo_leds, DJO_NUM_LEDS);
        break;
      case 2:
        djoAnimation = new DJOLetters(CRGB::Blue);
        break;
      case 3:
        djoAnimation = new Static(CRGB::Blue, 5000, djo_leds, DJO_NUM_LEDS);
        break;
      case 4:
        djoAnimation = new DJOLetters(CRGB::Black);
        break;
      case 5:
        djoAnimation = new Static(CRGB::Black, 2000, djo_leds, DJO_NUM_LEDS);
        break;
      default:
        djoAnimationNum = 0;
        return;
    }

    djoAnimationNum++;
  }
}

void selectBitlairAnimation() {
  if (bitlairAnimation->finished()) {
    switch(bitlairAnimationNum) {
      case 0: 
        bitlairAnimation = new Snake(BITLAIR_ORANGE, 10, bitlair_leds, BITLAIR_NUM_LEDS);
        break;
      case 1:
        bitlairAnimation = new Static(BITLAIR_ORANGE, 5000, bitlair_leds, BITLAIR_NUM_LEDS);
        break;
      case 2:
        bitlairAnimation = new Snake(CRGB::Black, 10, bitlair_leds, BITLAIR_NUM_LEDS);
        break;
      case 3:
        bitlairAnimation = new BitlairScrollUp(BITLAIR_ORANGE);
        break; 
      case 4:
        bitlairAnimation = new Static(BITLAIR_ORANGE, 5000, bitlair_leds, BITLAIR_NUM_LEDS);
        break;
      case 5:
        bitlairAnimation = new BitlairScrollUp(CRGB::Black);
        break;      
      case 6:
        bitlairAnimation = new Static(CRGB::Black, 2000, bitlair_leds, BITLAIR_NUM_LEDS);
        break; 
      case 7:
        bitlairAnimation = new BitlairLetters(BITLAIR_ORANGE);
        break;
      case 8:
        bitlairAnimation = new Static(BITLAIR_ORANGE, 5000, bitlair_leds, BITLAIR_NUM_LEDS);
        break;    
      case 9:
        bitlairAnimation = new BitlairLetters(CRGB::Black);
        break;
      case 10:
        bitlairAnimation = new Static(CRGB::Black, 2000, bitlair_leds, BITLAIR_NUM_LEDS);
        break;        
      default:
        bitlairAnimationNum = 0;
        return;
    }

    bitlairAnimationNum++;
  }
}

void loop() {
  selectBitlairAnimation();
  selectDJOAnimation();
  
  bitlairAnimation->update();
  djoAnimation->update();
  FastLED.show();
}
