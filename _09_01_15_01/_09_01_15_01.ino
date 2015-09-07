/* 
This code is the dotstar implementations of the fixed block code.
The block code allows the length of the block as input instead of 
the start and end.
It contains the color palette.

//
This code is an unusually sucessful first attempt at making blocks of different sizes.
block class is a doubly linked list which turns a section of the FastLED array on or 
off with the anoemometer uinterrupt.

Using Neopixels. 
*/

#include <SPI.h>
#include "FastLED.h"
#include "DHT.h"
#include "blocks.h"

#define BAUD_RATE        9600

#define DHT_TYPE         DHT22
#define DHT_PIN          3

#define DATA_PIN         6
#define CLOCK_PIN        7

#define LED_TYPE         APA102
#define COLOR_ORDER      GRB

#define BRIGHTNESS       255

#define NUMBER_PIXELS    140

#define BLOCK_1
#define BLOCK_2
#define BLOCK_3
#define BLOCK_4
#define BLOCK_5
#define BLOCK_6
#define BLOCK_7


/////

CRGB testLeds[NUMBER_PIXELS];
DHT dht(DHT_PIN, DHT_TYPE);

float temperatureFarenheit;
int temperature;

CRGB currentColor;
CRGBPalette16 currentPalette;
extern const TProgmemPalette16 temperaturePalette PROGMEM;
static uint8_t paletteIndex;

volatile byte anemoCounter;


///////////////////
/////////////////////////////////




Block* c = NULL;
Block* b1 = NULL;
Block* b2 = NULL;
Block* b3 = NULL;
Block* b4 = NULL;
Block* b5 = NULL;
Block* b6 = NULL;
//Block* b7 = NULL;
//Block* b8 = NULL;
//Block* b9 = NULL;
//Block* b10 = NULL;
//Block* b11 = NULL;
//Block* b12 = NULL;
//Block* b13 = NULL;
//Block* b14 = NULL;
//Block* b15 = NULL;
//Block* b16 = NULL;

//////////////////////////////////

void setup()
{
  systemSetup();

  b1 = new Block(testLeds, 5, true);//, CRGB::Red);
  b2 = new Block(testLeds, 5);
  b3 = new Block(testLeds, 5);
  b4 = new Block(testLeds, 5);
  b5 = new Block(testLeds, 3);
  b6 = new Block(testLeds, 7);
  
  c = b1;

  b1->setSides(b6, b2);
  b2->setSides(b1, b3);
  b3->setSides(b2, b4);
  b4->setSides(b3, b5);
  b5->setSides(b4, b6); 
  b6->setSides(b5, b1); 
}

void loop()
{
  temperatureFarenheit = dht.readTemperature(true);
  paletteIndex = map((int)temperatureFarenheit, 0, 110, 0, 255);
  getPaletteColor(paletteIndex);
}

//////////////////////////////////////////////////////////////////

void systemSetup()
{
  Serial.begin(BAUD_RATE);

  FastLED.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN>(testLeds, NUMBER_PIXELS);
  FastLED.setBrightness(BRIGHTNESS);

  attachInterrupt(0, anemo, RISING); // Interrupt 0 => Pin 2.

  anemoCounter = 0;
  currentPalette = temperaturePalette;
  
  FastLED.clear();
}


///////////////////////////////////////////////////



