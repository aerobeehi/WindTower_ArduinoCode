int get_Color_RGB()
{
  if (wind_f > 0)
  {
    if (temp_f <= 20 && temp_f > 0)
    { 
      r = 0 + 10 * wind_f;
      g = 30 + 10 * wind_f;
      b = 255;
    }
    else if (temp_f <= 50 && temp_f > 20)
    {
      r = 230;
      g = 50 +  5 * wind_f;
      b = 255;
    }
    else if (temp_f <= 70 && temp_f > 50)
    {
      r = 255;
      g = 10 +  5 * wind_f;
      b = 10 +  8 * wind_f;
    }
    else if (temp_f <= 90 && temp_f > 70)
    {
      r = 255;
      g = 160 + wind_f;
      b = 10 +  5 * wind_f;
    }
  }

}
