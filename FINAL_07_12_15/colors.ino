void getPaletteColor( uint8_t colorIndex)
{
  currentColor = ColorFromPalette(currentPalette, 167, 50, BLEND);
}



extern const TProgmemRGBPalette16 temperaturePalette PROGMEM =
{
  0x5500AB, 0x2A00D5, 0x0000FF, 0x0056AA, 
  0x008B55, 0x00AF59, 0x00D52A, 0x00FF00, 
  0x56D500, 0xABAB00, 0xEFEF00, 0xAB7F00,
  0xAB5500, 0xD52A00, 0xFE2200, 0xFF0000
};


