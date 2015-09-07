#include <SPI.h>
#include "FastLED.h"
#include "DHT.h"

#define   NUMPIXELS      240
#define   OFF            0x000000
#define   ON	         0x010101
#define   BAUDRATE       9600

#define   DHTTYPE        DHT22
#define   DHTPIN         8

#define DATAPIN_A    6
#define CLOCKPIN_A   7
#define DATAPIN_B    4
#define CLOCKPIN_B   5

DHT dht(DHTPIN, DHTTYPE);

CRGB leds[NUMPIXELS];
CRGB Color;
CRGBPalette16 currentPalette;
extern const TProgmemPalette16 Colors_p PROGMEM;

volatile byte anemo_counter;
volatile int M;
static uint8_t paletteIndex;

float t_f;
 int t;

int A = 11;

void setup()
{
  systemSetup();
}


void loop()
{
  t_f = dht.readTemperature(true);
  paletteIndex = map((int)t_f, 0, 110, 0, 255);
  getPaletteColor(paletteIndex);
}

