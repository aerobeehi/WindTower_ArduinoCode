#include <Adafruit_DotStar.h>
#include <SPI.h>
#include "TimerOne.h"
#include "index.h"

#define   NUMPIXELS      60 //240 ////
#define   OFF            0x000000
#define   ON	         0x010101
#define   TIMER          2000000000000
#define   BAUDRATE       9600

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS);

Index index_i;
Index index_f;
int wind_i;
int wind_f;
int anemo_counter;
int pulses;
boolean time;
boolean stopped;



void setup()
{
  systemSetup();

  wind_i = 0;
}


void loop()
{
  wind_f = get_WindSpeed(wind_i);
//  Serial.println(wind_f);
  index_f = update_index(index_i);

  animate();

  index_i = index_f;
  wind_i = wind_f;
}

