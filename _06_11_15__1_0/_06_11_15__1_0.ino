#include <Adafruit_DotStar.h>
#include <SPI.h>
#include "FastLED.h"
#include "DHT.h"

#define   _NUMPIXELS     60
#define   NUMPIXELS      240
#define   OFF            0x000000
#define   ON	         0x010101
#define   BAUDRATE       115200

#define   DHTTYPE        DHT22
#define   DHTPIN         8

#define DATAPIN_A    6
#define CLOCKPIN_A   7
#define DATAPIN_B    4
#define CLOCKPIN_B   5

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN_A, CLOCKPIN_A, DOTSTAR_BRG);
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN_B, CLOCKPIN_B, DOTSTAR_BRG);

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
//  Serial.println(M);
}

