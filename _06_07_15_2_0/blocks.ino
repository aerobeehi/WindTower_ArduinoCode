

void systemSetup()
{
  Serial.end();
  Serial.begin(BAUDRATE);

  strip.begin();
  strip.clear();
  strip.show();

}


void GetPaletteColor( uint8_t colorIndex)
{
  uint8_t brightness = 10;

  Color = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
}


//void fill_Palettes()
//{
//    Palettes[0] = VB_Palette;
//    Palettes[1] = BG_Palette;
//    Palettes[2] = GY_Palette;
//    Palettes[3] = YO_Palette;
//    Palettes[4] = OR_Palette;
//}
