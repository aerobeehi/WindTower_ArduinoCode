#include <Adafruit_NeoPixel.h>


#define   NUMBER_PIXELS      30
#define   LENGTH             4
#define   OFF            0x000000
#define   ON	         0x010101
#define   BAUD_RATE       9600

volatile byte anemoCounter;
int patternIndex;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, 6, NEO_GRB + NEO_KHZ800);
  

void setup()
{
  systemSetup();
}


void loop()
{

}

