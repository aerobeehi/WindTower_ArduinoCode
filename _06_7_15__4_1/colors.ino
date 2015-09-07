void getPaletteColor( uint8_t colorIndex)
{
  uint8_t brightness = 255;
  Color = ColorFromPalette( currentPalette, colorIndex, brightness, BLEND);
}



extern const TProgmemRGBPalette16 Colors_p PROGMEM =
{
    0xFF0000, 0xFE2200, 0xD52A00, 0xAB5500, 0xAB7F00,
    0xABAB00, 0x56D500, 0x00FF00, 0x00D52A,
    0x00AB55, 0x0056AA, 0x0000FF, 0x2A00D5,
    0x5500AB, 0x7F0081, 0xAB0055
};
