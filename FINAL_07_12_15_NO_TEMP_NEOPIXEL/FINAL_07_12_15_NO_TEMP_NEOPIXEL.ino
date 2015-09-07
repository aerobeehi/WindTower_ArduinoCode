#include <SPI.h>
#include "FastLED.h"

#define BAUD_RATE        9600

#define DATA_PIN         6
//#define CLOCK_PIN        7

#define LED_TYPE         NEOPIXEL
#define COLOR_ORDER      GRB

#define PATTERN_LENGTH   7

#define NUMBER_PIXELS    140


CRGB leds[NUMBER_PIXELS + 2 * PATTERN_LENGTH];

volatile byte anemoCounter;
int patternIndex;

//////////////////////////////////////////////////////////////////

void setup()
{
  systemSetup();
}


void loop()
{
 Serial.println(patternIndex);
}

