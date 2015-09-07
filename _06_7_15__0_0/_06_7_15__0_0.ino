#include <Adafruit_DotStar.h>
#include <SPI.h>
#include "TimerOne.h"
#include "DHT.h"

#define   _NUMPIXELS     160
#define   NUMPIXELS      240
#define   OFF            0x000000
#define   ON	         0x010101
#define   TIMER          5000000
#define   BAUDRATE       9600

#define   DHTTYPE        DHT22
#define   DHTPIN         7

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS);
DHT dht(DHTPIN, DHTTYPE);


volatile byte anemo_counter;
volatile int M;
volatile byte pulses;
boolean time;

float f;
float h;
int Temp;

int A = 8;

void setup()
{
  systemSetup();
}


void loop()
{
    Temp = f;
    Serial.println("TEMP");
    Serial.println(Temp);
}

