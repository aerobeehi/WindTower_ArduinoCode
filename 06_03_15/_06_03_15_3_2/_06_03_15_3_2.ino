#include <FastLED.h>
#include "TimerOne.h"

#define DATA_PIN    11
#define CLK_PIN     13
#define LED_TYPE    APA102
#define COLOR_ORDER BGR
#define NUM_LEDS    240
#define BRIGHTNESS          100
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

int A = 5;


CRGBPalette16 B_Palette(CRGB(0, 0, 255), CRGB(0, 80, 255), CRGB(0, 150, 255), CRGB::White);
CRGBPalette16 R_Palette(CRGB(255, 0, 0), CRGB(255, 30, 10), CRGB(255, 110, 90), CRGB::White);

CRGBPalette16 O_Palette(CRGB::Green, CRGB::Blue);

void setup()
{
  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, DATA_PIN, CLK_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}


void loop()
{
 static uint8_t index = 0;
 
  for ( int i = 0; i < NUM_LEDS + A; i += A)
  {
    fill_solid( leds, i, ColorFromPalette( O_Palette, index, 255, NOBLEND ));
    index++;
    FastLED.show();
    FastLED.clear();
    delay(100);
  }

delay(100);
}


