#include <FastLED.h>
#include "TimerOne.h"

#define DATA_PIN    11
#define CLK_PIN     13
#define LED_TYPE    APA102
#define COLOR_ORDER BGR
#define NUM_LEDS    60
#define BRIGHTNESS          90
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100
#define   TIMER          1000000

int A = 5;
int wind_i, wind_f;
boolean time;
uint8_t index;



CRGBPalette16 B_Palette(CRGB(0, 0, 255), CRGB(0, 80, 255), CRGB(0, 150, 255), CRGB::White);
CRGBPalette16 R_Palette(CRGB(255, 0, 0), CRGB(255, 30, 10), CRGB(255, 110, 90), CRGB::White);

CRGBPalette16 O_Palette(CRGB::Orange, CRGB::White);

void setup()
{
  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, DATA_PIN, CLK_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  Timer1.initialize(TIMER);
  Timer1.attachInterrupt(timer_Period);

  wind_i = 0;
  time = false;
  index = 0;
}


void loop()
{
  

  wind_f = get_WindSpeed(wind_i);

  for ( int i = 0; i < NUM_LEDS + A; i += A)
  {
    fill_solid( leds, i, ColorFromPalette( R_Palette, index, 255, NOBLEND ));
    fill_solid(leds, i - A, CRGB::Black);
    index++;
    FastLED.show();
    FastLED.clear();
    get_Delay();
  }

  wind_i = wind_f;
}


