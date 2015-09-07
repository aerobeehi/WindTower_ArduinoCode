// Dark chase with edited palette. Different palettes for 15 degree increments. 


#include <SPI.h>
#include "FastLED.h"
#include "DHT.h"

#define BAUD_RATE        9600

#define DHT_TYPE         DHT22
#define DHT_PIN          3

#define DATA_PIN         6
#define CLOCK_PIN        7

#define LED_TYPE         APA102
#define COLOR_ORDER      GRB
//#define BRIGHTNESS       255

#define PATTERN_LENGTH   14

#define NUMBER_PIXELS    140


CRGB leds[NUMBER_PIXELS + 2 * PATTERN_LENGTH];

DHT dht(DHT_PIN, DHT_TYPE);



CRGB currentColor;
CRGBPalette16 currentPalette;
extern const TProgmemPalette16 temperaturePalette PROGMEM;
static uint8_t paletteIndex;

volatile byte anemoCounter;

//////////////////////////////////////////////////////////////////

void setup()
{
  systemSetup();
}

void loop()
{
  float* tempF = NULL;
  *tempF = dht.readTemperature(true); 
  getPaletteColor(tempF);
}

//////////////////////////////////////////////////////////////////

void systemSetup()
{
  Serial.begin(BAUD_RATE);
  dht.begin(); 
  
  FastLED.addLeds<LED_TYPE,  DATA_PIN , CLOCK_PIN>(leds, NUMBER_PIXELS);
 // FastLED.setBrightness(BRIGHTNESS);

  attachInterrupt(0, anemo, RISING); // Interrupt 0 => Pin 2.

  anemoCounter = 0;
  patternIndex = 0;


  int* temp = NULL;
  
  int* patternIndex = NULL;
  
  FastLED.clear();
}

//////////////////////////////////////////////////////////////////

void anemo()
{
  anemoCounter++;
  increment();
}

//////////////////////////////////////////////////////////////////

void animate()
{
  Serial.println(patternIndex);
  
  fill_solid(leds, NUMBER_PIXELS, currentColor);
  
  for (int j = 0; j <= PATTERN_LENGTH; j++)
  {
    leds[patternIndex + j] = CRGB::Black; //ColorFromPalette(currentPalette, paletteIndex, 255, BLEND);
  }
  
  FastLED.show();
}

void increment()
{
  if (*patternIndex <= 0)
  {
    *patternIndex = NUMBER_PIXELS + PATTERN_LENGTH;
    FastLED.clear();
  }
  else
  {
    *patternIndex -= PATTERN_LENGTH;
    animate();
  }
}


//////////////////////////////////////////////////////////////////

CRGB* getPaletteColor(float* temperature)
{
  int temp;
  int offsetTemp;
  temp = (int)*temperature;
  
  if(temp <= 15)
  {
    currentColor = 0x5500AB;
  }
  if(temp > 15 && temp <= 30)
  {
    offsetTemp = temp - 15;
    currentColor = ColorFromPalette(
    
  }  
    

}

extern const TProgmemRGBPalette16 temperaturePalette PROGMEM =
{
  0x5500AB, 0x2A00D5, 0x0000FF, 0x0000FF,  
  0x0000FF, 0x00AF5D, 0x00D52A, 0x00FF00, 
  0x56D500, 0x2B6B00, 0xABEF00, 0xAB7F00,
  0xAB5500, 0xD52A00, 0xFE2200, 0xFF0000
};


