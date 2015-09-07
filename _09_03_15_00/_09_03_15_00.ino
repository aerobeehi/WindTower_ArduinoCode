/* 
This is the revised block code. 
It allows the block length as input instead of the start and end.

This code is an unusually sucessful first attempt at making blocks of different sizes.
block class is a doubly linked list which turns a section of the FastLED array on or 
off with the anoemometer uinterrupt.

Using Neopixels. 
*/

#include <SPI.h>
#include "FastLED.h"
#include "blocks.h"

#define BAUD_RATE        9600

#define DATA_PIN         7
#define CLOCK_PIN        6

#define LED_TYPE         DOTSTAR
#define COLOR_ORDER      GRB

#define BRIGHTNESS       100

#define NUMBER_PIXELS    30

CRGB testLeds[NUMBER_PIXELS];

volatile byte anemoCounter;

Block* c = NULL;
Block* b1 = NULL;
Block* b2 = NULL;
Block* b3 = NULL;
Block* b4 = NULL;
Block* b5 = NULL;
Block* b6 = NULL;

//////////////////////////////////

void setup()
{
  systemSetup();

  b1 = new Block(testLeds, true, 5, CRGB::Red);
  b2 = new Block(testLeds, false, 5, CRGB::Yellow);
  b3 = new Block(testLeds, false, 5, CRGB::Blue);
  b4 = new Block(testLeds, false, 5, CRGB::Green);
  b5 = new Block(testLeds, false, 3);
  b6 = new Block(testLeds, false, 7);
  
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

}

//////////////////////////////////////////////////////////////////

void systemSetup()
{
  Serial.begin(BAUD_RATE);

  FastLED.addLeds<LED_TYPE,  DATA_PIN, CLOCK_PIN>(testLeds, NUMBER_PIXELS);
 // FastLED.setBrightness( BRIGHTNESS );

  attachInterrupt(0, anemo, RISING); // Interrupt 0 => Pin 2.

  anemoCounter = 0;
  
  Serial.println("whee");
  
  FastLED.clear();
}




