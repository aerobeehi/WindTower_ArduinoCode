#include <SPI.h>
#include "FastLED.h"
#include "DHT.h"

#define NUMBER_PIXELS    140
#define BAUD_RATE        9600

#define DHT_TYPE         DHT22
#define DHT_PIN          8

#define DATA_PIN_A       6
#define CLOCK_PIN_A      7

#define DATA_PIN_B       4
#define CLOCK_PIN_B      5

#define PATTERN_LENGTH   7


DHT dht(DHT_PIN, DHT_TYPE);

float temperatureFarenheit;
int temperature;

CRGB leds[NUMBER_PIXELS];

volatile byte anemoCounter;
int patternIndex;

CRGB currentColor;
CRGBPalette16 currentPalette;
extern const TProgmemPalette16 temperaturePalette PROGMEM;
static uint8_t paletteIndex;

//////////////////////////////////////////////////////////////////

void setup()
{
  systemSetup();
}


void loop()
{
  temperatureFarenheit = dht.readTemperature(true);
  paletteIndex = map((int)temperatureFarenheit, 0, 110, 0, 255);
  getPaletteColor(paletteIndex);
}

