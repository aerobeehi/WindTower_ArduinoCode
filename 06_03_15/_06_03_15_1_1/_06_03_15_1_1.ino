#include <Adafruit_DotStar.h>
#include <FastLED.h>
#include <SPI.h>
#include "TimerOne.h"


#define   NUMPIXELS      240
#define   OFF            0x000000
#define   ON	         0x030303
#define   TIMER          1000000
#define   BAUDRATE       9600

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_GRB);

int A = 8;
int B = 10;
int wind_i;
int wind_f;
boolean time;

void setup()
{
  systemSetup();
}


void loop()
{
  systemUpdate();
}

