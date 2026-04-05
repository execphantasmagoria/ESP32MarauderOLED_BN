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