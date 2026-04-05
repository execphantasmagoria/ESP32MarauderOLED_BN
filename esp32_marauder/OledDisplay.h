#pragma once

#ifndef OledDisplay_h
#define OledDisplay_h

#include "configs.h"

#ifdef HAS_OLED_DISPLAY
#include <U8g2lib.h>
#include <Wire.h>
#include <Arduino.h>

  class OledDisplay
  {
    public:
      OledDisplay();
      U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2 = U8G2_SSD1306_128X64_NONAME_F_HW_I2C(U8G2_R0, U8X8_PIN_NONE);

      void begin();

      // void showCenterText(String text, int y);
      void showTextAtPos(String text, int x, int y);
      // void showASCIITwoPartText(const String& leftText, const String& rightText, int x, int y);
      // void showWrappingText(const String& text, int x, int y, int maxWidth);
      // void displayBuffer(bool do_clear = false);
      // void displayBitmap(const uint8_t* bitmap, int x, int y, int width, int height);
      // void displayIcon(const uint8_t* icon, int x, int y);
      // void clearScreen();
      // void drawASCIIGraph(const String& graphData, int x, int y);
      // void drawASCIIMenuItems(const String& menuData, int x, int y);
      // void updateBanner(String msg);
      // void drawASCIIDivider(int x, int y, int width);
  };
  // OLED Display funcs 
#endif
#endif