#include <SPI.h>
#include "FastLED.h"


#define NUMBER_PIXELS      149
#define BAUD_RATE       9600

#define DATA_PIN_A    6
#define CLOCK_PIN_A   7

#define DATA_PIN_B    4
#define CLOCK_PIN_B   5

#define PATTERN_LENGTH 10

CRGB leds[NUMBER_PIXELS];


int patternIndex;


void setup()
{
  systemSetup();
}


void loop()
{
 digitalWrite(13, LOW);
}
