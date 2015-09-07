// Testing setBrightness and temperature threshold.
// Brightness is assumed to be betwen 0 and 256.
// Not actually testing setBrightness since getColor already sets it.

#include <SPI.h>
#include "FastLED.h"
#include "DHT.h"

#define BAUD_RATE        9600

#define DHT_TYPE         DHT22
#define DHT_PIN          3
#define TEMP_THRESHOLD   75

#define DATA_PIN         6
#define CLOCK_PIN        7

#define LED_TYPE         APA102
#define COLOR_ORDER      GRB
//#define BRIGHTNESS       255

#define PATTERN_LENGTH   7

#define NUMBER_PIXELS    140


CRGB leds[NUMBER_PIXELS + 2 * PATTERN_LENGTH];

DHT dht(DHT_PIN, DHT_TYPE);

float temperatureFarenheit;
int temperature;

CRGB currentColor;
CRGBPalette16 currentPalette;
extern const TProgmemPalette16 temperaturePalette PROGMEM;
static uint8_t paletteIndex;

volatile byte anemoCounter;
int patternIndex;

//////////////////////////////////////////////////////////////////

void setup()
{
  systemSetup();
}

void loop()
{
  temperatureFarenheit = dht.readTemperature(true);
  
  if(temperatureFarenheit < TEMP_THRESHOLD)
  {
      paletteIndex = map((int)temperatureFarenheit, 0, 110, 0, 255);
      getPaletteColor(paletteIndex);
  }
  else
  {
    currentColor = CRGB::Black;
  }
}

//////////////////////////////////////////////////////////////////

void systemSetup()
{
  Serial.begin(BAUD_RATE);
  dht.begin(); 
  
  FastLED.addLeds<LED_TYPE,  DATA_PIN , CLOCK_PIN>(leds, NUMBER_PIXELS);
 // FastLED.setBrightness(BRIGHTNESS);

  attachInterrupt(0, anemo, RISING); // Interrupt 0 => Pin 2.

  anemoCounter = 0;
  patternIndex = 0;
  currentPalette = temperaturePalette;
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
    leds[patternIndex + j] = currentColor; //ColorFromPalette(currentPalette, paletteIndex, 255, BLEND);
    leds[(patternIndex + PATTERN_LENGTH) + j] = CRGB::Black;
  }
  FastLED.show();
}

void increment()
{
  if (patternIndex <= 0)
  {
    patternIndex = NUMBER_PIXELS + PATTERN_LENGTH;
    FastLED.clear();
  }
  else
  {
    patternIndex -= PATTERN_LENGTH;
    animate();
  }
}


//////////////////////////////////////////////////////////////////

void getPaletteColor( uint8_t colorIndex)
{
  currentColor = ColorFromPalette(currentPalette, colorIndex, 255, BLEND);
}

extern const TProgmemRGBPalette16 temperaturePalette PROGMEM =
{
  0x5500AB, 0x2A00D5, 0x0000FF, 0x0056AA, 
  0x008B55, 0x00AF59, 0x00D52A, 0x00FF00, 
  0x56D500, 0xABAB00, 0xEFEF00, 0xAB7F00,
  0xAB5500, 0xD52A00, 0xFE2200, 0xFF0000
};


