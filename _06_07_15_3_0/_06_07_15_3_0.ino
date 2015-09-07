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

extern const TProgmemPalette16 Colors_p PROGMEM;

 
int B = 10;
int D;
static uint8_t startIndex;

void setup()
{
  systemSetup();
  delay(1000);

  currentPalette = Colors_p;
  currentBlending = BLEND;
  startIndex = 256;
}


void loop()
{
  if ((startIndex -=3) > 0)
  {
    GetPaletteColor(startIndex);
    D = 20;
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
    
   // delay(100);
  }
  else
  {
    startIndex = 256;
  }
}

