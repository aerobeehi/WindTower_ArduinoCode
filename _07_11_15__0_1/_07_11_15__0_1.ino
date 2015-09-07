#include <SPI.h>
#include "FastLED.h"
#include "DHT.h"

#define   NUMBER_PIXELS      149
#define   OFF            0x000000
#define   ON	         0x010101
#define   BAUD_RATE       9600

#define   DHT_TYPE        DHT22
#define   DHT_PIN         8

#define DATA_PIN_A    6
#define CLOCK_PIN_A   7

#define DATA_PIN_B    4
#define CLOCK_PIN_B   5

DHT dht(DHT_PIN, DHT_TYPE);

CRGB leds[NUMBER_PIXELS];
CRGB currentColor;
CRGBPalette16 currentPalette;
extern const TProgmemPalette16 temperaturePalette PROGMEM;

volatile byte anemoCounter;
int patternIndex;
int patternLength = 11;


static uint8_t paletteIndex;
float temperatureFarenheit;
int temperature;



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

