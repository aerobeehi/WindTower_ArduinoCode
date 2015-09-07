int get_Length_A(int length_in)
{
  int length_out;

  if (wind_f != 0)
  {
    if (wind_f == 1)
    {
      length_out = 2;
      return length_out;
    }
    else if (wind_f == 2)
    {
      length_out = 4;
      return length_out;
    }
    else if (wind_f == 3)
    {
      length_out = 8;
      return length_out;
    }
    else if (wind_f > 3)
    {
      length_out = (wind_f - 3) * 4 + 8;
      return length_out;
    }
  }
  else
  {
    return length_in;
  }
}

/********************************************/
/********************************************/

int get_Length_B(int length_in)
{
  int length_out;
  
  if (wind_f != 0)
  {
    if (wind_f > 0 && wind_f > wind_i)
    {
      length_out = length_in + wind_f;
      return length_out;
    }
    else if (wind_f > 0 && wind_f < wind_i)
    {
      length_out = length_in - wind_f;
      return length_out;
    }
  }
  else
  {
    return length_in;
  }
}

/********************************************/
/********************************************/

int get_Length_C(int length_in)
{
  int length_out;
  
  if (wind_f > 0 )
  {
    length_out = wind_f + 2;
    return length_out;
  }
  else
  {
    return length_in;
  }
}









