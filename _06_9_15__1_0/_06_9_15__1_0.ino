#include <Adafruit_DotStar.h>
#include "FastLED.h"
#include <SPI.h>
#include "DHT.h"

#define   _NUMPIXELS     160
#define   NUMPIXELS      240
#define   OFF            0x000000
#define   ON	         0x010101
#define   BAUDRATE       9600

#define   DHTTYPE        DHT22
#define   DHTPIN         7

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BGR);
DHT dht(DHTPIN, DHTTYPE);

CRGB Color;
CRGBPalette16 currentPalette;
extern const TProgmemPalette16 Colors_p PROGMEM;

volatile byte anemo_counter;
volatile int M;
static uint8_t startIndex;

float t_f;
int t;

int A = 100;

void setup()
{
  systemSetup();
}


void loop()
{

}

