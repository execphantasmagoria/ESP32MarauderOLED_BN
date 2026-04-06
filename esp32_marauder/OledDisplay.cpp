#include "OledDisplay.h"

OledDisplay::OledDisplay() {}

void OledDisplay::begin() {
    Wire.begin(SDA_PIN, SCL_PIN);
    u8g2.begin();
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 12, "OLED init OK");
    u8g2.sendBuffer();
}

void OledDisplay::showTextAtPos(String text, int x, int y)
{
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(x, y, text.c_str());
    u8g2.sendBuffer();
}

void OledDisplay::showMainMenu()
{
  // Screen: MainMenu
  u8g2.clearBuffer(); // Clear internal buffer

  // Draw bitmap
  u8g2.drawXBM(0, 2, bitmap_screen_mainmenu_0_width, bitmap_screen_mainmenu_0_height, bitmap_screen_mainmenu_0_bits);

  // Draw vector elements
  // Element ID: 0 (text)
  // Text element with size 10pt (default: 8pt)
  // Note: For additional fonts, visit:
  // - U8g2 Font List: https://github.com/olikraus/u8g2/wiki/fntlistall
  // Font family: monospace, Style: Bold
  // Note: U8g2 uses pixel height for fonts. Mapping pt to px height appropriately.
  u8g2.setFont(u8g2_font_profont12_tf); // Selected: profont12
  u8g2.setFontDirection(0); // Normal orientation
  u8g2.drawStr(13, 7, "Marauder Extended");
  // Element ID: 2 (text)
  // Text element with size 6pt (default: 8pt)
  // Note: For additional fonts, visit:
  // - U8g2 Font List: https://github.com/olikraus/u8g2/wiki/fntlistall
  // Font family: monospace, Style: Regular, Italic
  // Note: U8g2 uses pixel height for fonts. Mapping pt to px height appropriately.
  u8g2.setFont(u8g2_font_profont10_tf); // Selected: profont10
  u8g2.setFontDirection(0); // Normal orientation
  if (currentMenuIndex == 0) { // Placeholder for menu selection logic
    u8g2.drawStr(9, 29, "o WiFi Menu");
  } else {
    u8g2.drawStr(9, 29, "> WiFi Menu");
  }
  // Element ID: 3 (text)
  // Text element with size 6pt (default: 8pt)
  // Note: For additional fonts, visit:
  // - U8g2 Font List: https://github.com/olikraus/u8g2/wiki/fntlistall
  // Font family: monospace, Style: Regular
  // Note: U8g2 uses pixel height for fonts. Mapping pt to px height appropriately.
  u8g2.setFont(u8g2_font_profont10_tf); // Selected: profont10
  u8g2.setFontDirection(0); // Normal orientation
  if (currentMenuIndex == 1) {
    u8g2.drawStr(9, 37, "o RF Menu");
  } else {
    u8g2.drawStr(9, 37, "> RF Menu");
  }
  // Element ID: 4 (text)
  // Text element with size 6pt (default: 8pt)
  // Note: For additional fonts, visit:
  // - U8g2 Font List: https://github.com/olikraus/u8g2/wiki/fntlistall
  // Font family: monospace, Style: Regular
  // Note: U8g2 uses pixel height for fonts. Mapping pt to px height appropriately.
  u8g2.setFont(u8g2_font_profont10_tf); // Selected: profont10
  u8g2.setFontDirection(0); // Normal orientation
  if (currentMenuIndex == 2) {
    u8g2.drawStr(9, 45, "o Shutdown");
  } else {
    u8g2.drawStr(9, 45, "> Shutdown");
  }
  // Element ID: 5 (rectangle)
  //u8g2.drawFrame(7, 27, 50, 10);

  u8g2.sendBuffer(); // Transfer internal memory to the display
}

void OledDisplay::navigateMenu(String direction)
{
    
    if (direction == "up") {
        if (currentMenuIndex > 0) {
        currentMenuIndex--;
        }
        else
        {
          currentMenuIndex = 2; // Wrap around to the last menu item
        }
    } else if (direction == "down") {
        if (currentMenuIndex < 2) { // Assuming 3 menu items
        currentMenuIndex++;
        }
        else
        {
          currentMenuIndex = 0; // Wrap around to the first menu item
        }
    }
    this->showMainMenu(); // Refresh menu display after navigation
}
