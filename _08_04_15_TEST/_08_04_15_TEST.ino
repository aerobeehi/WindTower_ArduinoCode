#include <SPI.h>
#include "FastLED.h"

#define BAUD_RATE        9600

#define DATA_PIN         6
#define CLOCK_PIN        7

#define LED_TYPE         APA102
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
 //Serial.println(patternIndex);
}

//////////////////////////////////////////////////////////////////

void systemSetup()
{
  Serial.begin(BAUD_RATE);

  FastLED.addLeds<LED_TYPE,  DATA_PIN , CLOCK_PIN>(leds, NUMBER_PIXELS);

  attachInterrupt(0, anemo, RISING); // Interrupt 0 => Pin 2.

  anemoCounter = 0;
  patternIndex = 0;

  //Serial.println("HEY!");
}

//////////////////////////////////////////////////////////////////

void anemo()
{
  anemoCounter++;
  increment();
}

//////////////////////////////////////////////////////////////////

void animate()
{
  for (int j = 0; j <= PATTERN_LENGTH; j++)
  {
    leds[patternIndex + j] = CRGB::Red;
    leds[(patternIndex + PATTERN_LENGTH) + j] = CRGB::Black;
      Serial.println("he");
  }
  FastLED.show();
}

void increment()
{
  if (patternIndex <= 0)
  {
    patternIndex = NUMBER_PIXELS + PATTERN_LENGTH;
    Serial.println("no");
    FastLED.clear();
  }
  else
  {
    Serial.println("yo");
    patternIndex -= PATTERN_LENGTH;
    animate();
  }
}
