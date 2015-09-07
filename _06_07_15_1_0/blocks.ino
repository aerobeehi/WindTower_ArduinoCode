

void systemSetup()
{
  Serial.end();
  Serial.begin(BAUDRATE);

  strip.begin();
  strip.clear();
  strip.show();

}




