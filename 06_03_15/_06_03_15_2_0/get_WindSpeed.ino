// Gets the current windspeed, which is updated
// every second.

int get_WindSpeed(int WindSpeed_in)
{

  static int WindSpeed_out;

  if (time == true)
  {
    if (++WindSpeed_in < 25)
    {
      WindSpeed_out = WindSpeed_in + 1;
      time = false;
    }
  }
  else
  {
    WindSpeed_out = WindSpeed_in;
  }

  return WindSpeed_out;
}



void timer_Period()
{
  time = true;
}
