
Index update_index(Index index_in)
{
  Index index_out;

  static int length_in;
  int length_serial;
  int delta;
  int h;
  int t;

  /********************************************/

  if ( index_in.plength > 0 )
  {
    length_in = abs((index_in.tail - NUMPIXELS) - index_in.head);
  }
  else
  {
    length_in = abs(index_in.tail - index_in.head);
  }
  
  /********************************************/
  
  if (wind_f == 0)
  {
    return index_in;
  }
  else
  {

    /********************************************/

    length_serial = get_Length_C(length_in);

    /********************************************/

    delta = abs(length_serial - length_in);

    /********************************************/

    if (delta != 0)
    {
      

      if (length_serial > length_in)
      {
        for (h = 0; h <= delta; ++h)
        {
          if (--index_in.tail >= NUMPIXELS)
          {
            index_in.tail = 0;
          }
          strip.setPixelColor(index_in.head, ON);
          strip.show();
        }
        ++index_in.head;
      }


      if (length_serial < length_in)
      {
        for (t = 0; t <= delta; ++t)
        {
          if (++index_in.tail >= NUMPIXELS)
          {
            index_in.tail = 0;
          }
          strip.setPixelColor(index_in.tail, OFF);
          strip.show();
        }
        ++index_in.head;
      }


      /********************************************/
    }
    else
    {
      /********************************************/

      if (++index_in.head >= NUMPIXELS)
      {
        index_in.head = 0;
      }

      if ( ++index_in.tail >= NUMPIXELS)
      {
        index_in.tail = 0;
      }

    }

    /********************************************/

    index_out.plength = index_in.tail - index_in.head;

    index_out.head = index_in.head;
    index_out.tail = index_in.tail;

    return index_out;
  }
}


