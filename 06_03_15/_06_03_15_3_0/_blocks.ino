
void systemSetup()
{
  Serial.end();
  Serial.begin(BAUDRATE);

  Timer1.initialize(TIMER);
  Timer1.attachInterrupt(timer_Period);

  strip.begin();
  strip.clear();
  strip.show();

  time = false;
  
  wind_i = 0;
  temp_i = 0;

  delay(1000);
}


void systemUpdate()
{
  wind_f = get_WindSpeed(wind_i);
  temp_f = 15;    //get_Temperature(temp_i);

  if (wind_f > 10)
  {
    animate_B();
  }
  else
  {
    animate_A();
  }
  
  wind_i = wind_f;
  temp_i = temp_f;
}


