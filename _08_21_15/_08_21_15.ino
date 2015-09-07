/* 
This code is an unusually sucessful first attempt at making blocks of different sizes.
block class is a doubly linked list which turns a section of the FastLED array on or 
off with the anoemometer uinterrupt.

Using Neopixels. 
*/

#include <SPI.h>
#include "FastLED.h"
#include "blocks.h"

#define BAUD_RATE        9600

#define DATA_PIN         8

#define LED_TYPE         NEOPIXEL

#define BRIGHTNESS       25

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

  b1 = new Block(testLeds, 0, 2);
  b2 = new Block(testLeds, 3, 5);
  b3 = new Block(testLeds, 6, 15);
  b4 = new Block(testLeds, 16, 18);
  b5 = new Block(testLeds, 19, 25);
  b6 = new Block(testLeds, 26, 30);
  
  c = b1;

  b1->setPrev(b6);
  b1->setNext(b2);
  b2->setPrev(b1);
  b2->setNext(b3);
  b3->setPrev(b2);
  b3->setNext(b4);
  b4->setPrev(b3);
  b4->setNext(b5);
  b5->setPrev(b4);
  b5->setNext(b6);
  b6->setPrev(b5);
  b6->setNext(b1);
}

void loop()
{

}

//////////////////////////////////////////////////////////////////

void systemSetup()
{
  Serial.begin(BAUD_RATE);

  FastLED.addLeds<LED_TYPE,  DATA_PIN>(testLeds, NUMBER_PIXELS);
  FastLED.setBrightness( BRIGHTNESS );

  attachInterrupt(0, anemo, RISING); // Interrupt 0 => Pin 2.

  anemoCounter = 0;
  
  FastLED.clear();
}




