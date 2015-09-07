#include <Adafruit_DotStar.h>
#include <SPI.h>
#include "FastLED.h"
#include "DHT.h"

#define   _NUMPIXELS     60
#define   NUMPIXELS      240
#define   OFF            0x000000
#define   ON	         0x010101
#define   BAUDRATE       9600

#define   DHTTYPE        DHT22
#define   DHTPIN         8

Adafruit_DotStar strip_A = Adafruit_DotStar(NUMPIXELS, 4, 5, DOTSTAR_BGR);
Adafruit_DotStar strip_B = Adafruit_DotStar(NUMPIXELS, 6, 7, DOTSTAR_BGR);

DHT dht(DHTPIN, DHTTYPE);

CRGB Color;
CRGBPalette16 Palette;
extern const TProgmemPalette16 Colors_p PROGMEM;

volatile byte anemo_counter;
volatile int M;
static uint8_t paletteIndex;

float t_f;
int t;

int A = 10;

void setup()
{
  systemSetup();
}


void loop()
{

}

