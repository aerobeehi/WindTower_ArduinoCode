#include <Adafruit_DotStar.h>
#include "FastLED.h"
#include <SPI.h>
#include "color.h"


#define   NUMPIXELS      160
#define   OFF            0x000000
#define   ON	         0x010101
#define   TIMER          1000000
#define   BAUDRATE       9600

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BGR);

CRGBPalette16 VB_Palette(CRGB::DarkViolet, CRGB::Blue);
CRGBPalette16 BG_Palette(CRGB::DarkBlue, CRGB::Green);
CRGBPalette16 GY_Palette(CRGB::Green, CRGB::Yellow);
CRGBPalette16 YO_Palette(CRGB::Yellow, CRGB::OrangeRed);
CRGBPalette16 OR_Palette(CRGB::OrangeRed, CRGB::Red);


int B = 10;
int D;
byte index;

void setup()
{
  systemSetup();
  D = 1000;
  delay(1000);
  index = 0;
}


void loop()
{
   D = 300;
   
    animate_B();
}

