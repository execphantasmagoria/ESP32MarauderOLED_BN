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

void OledDisplay::drawBanner(String text)
{
    int centeredX = (128 - ((text.length() * 12) / 2)); // Assuming 12 pixels per character for the chosen font
    u8g2.setFont(u8g2_font_profont12_tf);
    u8g2.drawStr(centeredX, 7, text.c_str());
}

void OledDisplay::drawMenuItem(String text, int index, bool isSelected)
{
    int yPos = 29 + (index * 8); // Calculate y position based on index
    u8g2.setFont(u8g2_font_profont10_tf);
    if (isSelected) {
        text = "o " + text; // Add selection indicator
        u8g2.drawStr(9, yPos, text.c_str());
    } else {
        text = "> " + text; // Add non-selection indicator
        u8g2.drawStr(9, yPos, text.c_str());
    }
}

void OledDisplay::drawLogo(int x, int y)
{
    u8g2.drawXBMP(x, y, bitmap_logo_width, bitmap_logo_height, bitmap_logo_bits);
}

// void OledDisplay::drawBitmap(const uint8_t *bitmap, int x, int y, int width, int height)
// {
//     u8g2.drawXBM(x, y, width, height, bitmap);
// }

void OledDisplay::show()
{
    u8g2.sendBuffer();
}

void OledDisplay::clear()
{
    u8g2.clearBuffer();
}

void OledDisplay::navigateMenu(String direction, int menuSize)
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
        if (currentMenuIndex < menuSize - 1) { // Assuming 3 menu items
        currentMenuIndex++;
        }
        else
        {
          currentMenuIndex = 0; // Wrap around to the first menu item
        }
    }
}
