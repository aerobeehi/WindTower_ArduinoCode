//HSB mix(HSB color_1, HSB color_2, uint8_t step)
//{
//  float perc = (float)step / 255;
//
//  HSB newCol = {(uint8_t)((1 - perc)*color_1.hue)	+ (uint8_t)((perc)*color_2.hue),
//                (uint8_t)((1 - perc)*color_1.sat)	+ (uint8_t)((perc)*color_2.sat),
//                (uint8_t)((1 - perc)*color_1.bri)	+ (uint8_t)((perc)*color_2.bri)
//               };
//
//  return newCol;
//}
//
//RGB HSBtoRGB(HSB from_color)
//{
//  /*
//   * Hue: 0..359
//   * Sat: 0..255
//   * bri: 0..255
//   */
//
//  RGB result;
//  from_color.bri = pgm_read_byte(&dim_curve[from_color.bri]);
//  from_color.sat = 255 - pgm_read_byte(&dim_curve[255 - from_color.sat]);
//
//  uint8_t r, b, g, base;
//
//  if (from_color.sat == 0) //Acromatic, from_color.hue not needed
//  {
//    result.red = from_color.bri;
//    result.green = from_color.bri;
//    result.blue = from_color.bri;
//  }
//  else
//  {
//    base = ((255 - from_color.sat) * from_color.bri) >> 8;
//
//    switch (from_color.hue / hstep)
//    {
//      case 0://red
//        {
//          result.red = from_color.bri;
//          result.green = (((from_color.bri - base) * from_color.hue) / hstep) + base;
//          result.blue = base;
//          break;
//        }
//
//      case 1://yellow
//        {
//          result.red = (((from_color.bri - base) * (hstep - (from_color.hue % hstep))) / hstep) + base;
//          result.green = from_color.bri;
//          result.blue = base;
//          break;
//        }
//
//      case 2://green
//        {
//          result.red = base;
//          result.green = from_color.bri;
//          result.blue = (((from_color.bri - base) * (from_color.hue % hstep)) / hstep) + base;
//          break;
//        }
//
//      case 3://cyan
//        {
//          result.red = base;
//          result.green = (((from_color.bri - base) * (hstep - (from_color.hue % hstep))) / hstep) + base;
//          result.blue = from_color.bri;
//          break;
//        }
//
//      case 4://blue
//        {
//          result.red = (((from_color.bri - base) * (from_color.hue % hstep)) / hstep) + base;
//          result.green = base;
//          result.blue = from_color.bri;
//          break;
//        }
//
//      case 5://magenta
//        {
//          result.red = from_color.bri;
//          result.green = base;
//          result.blue = (((from_color.bri - base) * (hstep - (from_color.hue % hstep))) / hstep) + base;
//          break;
//        }
//    }
//  }
//  return result;
//}
//
//RGB HextoRGB(int hexValue)
//{
//  RGB result;
//  result.red = ((hexValue >> 16) & 0xFF);  // Extract the RR byte
//  result.green = ((hexValue >> 8) & 0xFF);   // Extract the GG byte
//  result.blue = ((hexValue) & 0xFF);        // Extract the BB byte
//
//  return result;
//}
