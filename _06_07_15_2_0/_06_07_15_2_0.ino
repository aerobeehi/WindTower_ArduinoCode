#include <Adafruit_DotStar.h>
#include "FastLED.h"
#include <SPI.h>

#define   NUMPIXELS      160
#define   OFF            0x000000
#define   ON	         0x010101
#define   TIMER          1000000
#define   BAUDRATE       9600

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS);

CRGB Color;

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern const TProgmemPalette16 VB_Palette PROGMEM;
extern const TProgmemPalette16 BG_Palette PROGMEM;
extern const TProgmemPalette16 GY_Palette PROGMEM;
extern const TProgmemPalette16 YO_Palette PROGMEM;
extern const TProgmemPalette16 OR_Palette PROGMEM;
TProgmemPalette16 Palettes[5];
 
int B = 10;
int D;
static uint8_t startIndex;

void setup()
{
  systemSetup();
  delay(1000);

  currentPalette = VB_Palette;
  currentBlending = BLEND;
}


void loop()
{
  if (++startIndex < 16)
  {
    GetPaletteColor(startIndex);
    D = 100;
    animate();

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
    Serial.println(startIndex, BIN);
  }
  else
  {
    startIndex = 0;
  }
}

