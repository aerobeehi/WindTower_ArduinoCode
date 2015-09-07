int get_WindSpeed(int WindSpeed_in)
{
  int WindSpeed_out;

  if (time == true)
  {
    WindSpeed_out = ceil(calculate_WindSpeed(pulses));
    time = false;
    return WindSpeed_out;
  }
  else
  {
    WindSpeed_out = WindSpeed_in;
    return WindSpeed_out;
  }

}

// Every time there is a rising edge on pin 2,
// the value of i increases by one until it reaches 100,000.
void anemo()
{
  anemo_counter++;
  increment();
}


// Every time that the timer reaches 1 second,
// time becomes true and the counter value from anemo
// used for calculateing windspeed is updated.
//
void timer_Period()
{
  time = true;
  pulses = anemo_counter;
  anemo_counter = 0;
}


// Calculate the windspeed based on number of revolutions
// completed in 1 second. There are 8 pulses to each revolution.
// 25 mph  = 10 rotations = 80 pulses

float calculate_WindSpeed(int i)
{
  float Rotations =  (float) i / 8;

  float WindSpeed = Rotations * 2.5;

  i = 0;

  return WindSpeed;
}



