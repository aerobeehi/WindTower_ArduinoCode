void get_Delay()
{
  double delay_out;
 
  if(wind_f <= 7 && wind_f > 0)
  {
    delay_out = 400 - 50 * wind_f;
    delay(delay_out);
    return;
  }
  else if (wind_f <= 12 && wind_f > 7)
  {
    delay_out = 100 - 19 * (wind_f - 7);
    delay(delay_out);
    return;
  }
  else if (wind_f <= 25 && wind_f > 12)
  {
    delay_out = 5000 - 385 * (wind_f - 12);
    delayMicroseconds(delay_out);
    return;
  } 
}











