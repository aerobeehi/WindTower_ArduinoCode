#include <Adafruit_DotStar.h>
#include <FastLED.h>
#include <SPI.h>
#include "TimerOne.h"


#define   NUMPIXELS      60
#define   OFF            0x000000
#define   ON	         0x010101
#define   TIMER          1000000
#define   BAUDRATE       9600

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BGR);

int A = 4;
int B = 6;

byte r, g, b;
int wind_i, wind_f;
int temp_i, temp_f;



boolean time;

void setup()
{
  systemSetup();
}


void loop()
{
  systemUpdate();
}

