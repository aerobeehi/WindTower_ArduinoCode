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

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS);
DHT dht(DHTPIN, DHTTYPE);

CRGB Color;
CRGBPalette16 currentPalette;
extern const TProgmemPalette16 Colors_p PROGMEM;

volatile byte anemo_counter;
volatile int M;
static uint8_t startIndex;

float t_f;
float h;
int t;
uint8_t y;

int A = 8;

void setup()
{
  systemSetup();
}


void loop()
{
    Serial.print("R - ");
    Serial.print(Color.red, HEX);
    Serial.print("\t");
    Serial.print("G - ");
    Serial.print(Color.green, HEX);
    Serial.print("\t");
    Serial.print("B - ");
    Serial.print(Color.blue, HEX);
    Serial.print("\t");
    Serial.print("Index - ");
    Serial.print(startIndex, BIN);
    Serial.print("\t");
    Serial.println(y);
}

