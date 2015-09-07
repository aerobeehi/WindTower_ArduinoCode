#include <Adafruit_DotStar.h>
#include <SPI.h>
#include "TimerOne.h"

#define   _NUMPIXELS     160
#define   NUMPIXELS      240
#define   OFF            0x000000
#define   ON	         0x030303
#define   TIMER          1000000
#define   BAUDRATE       9600

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS);


volatile byte anemo_counter;
volatile int M;
volatile byte pulses;
boolean time;
boolean stopped;
int wind_i, wind_f;

int A = 8;

void setup()
{
  systemSetup();
}


void loop()
{
  wind_f = get_WindSpeed(wind_i);
  Serial.print(wind_f);
  Serial.print("\t");
  Serial.println(pulses);
  wind_i = wind_f;
}

