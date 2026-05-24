#pragma once

#ifndef DisplayNoTouch_h
#define DisplayNoTouch_h
#include "configs.h"

#ifdef HAS_TFT_DISPLAY

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <FS.h>
#include "SDInterface.h"

// Forward declare to avoid requiring the full SDInterface definition here
// which can introduce circular includes.
class SDInterface;
extern SDInterface sd_obj;

// #define TFT_CS     5
// #define TFT_DC     2
// #define TFT_RST    4
// #define TFT_SCLK  18
// #define TFT_MOSI  23
// #define TFT_MISO  -1
// #define TFT_BL    17

// SD_CS 15
// SD_MOSI 25
// SD_MISO 26
// SD_SCK 27

#define TFT_BLACK   0x0000
#define TFT_WHITE   0xFFFF
#define TFT_RED     0x001F  
#define TFT_BLUE    0xF800  
#define TFT_GREEN   0x07E0  
#define TFT_YELLOW  0x07FF  
#define TFT_CYAN    0xFFE0  

class TftDisplay
{
  private:
    void logToTFT(int x, int y, const char* message);
    void errorToTFT(int x, int y, const char* message);
    void warningToTFT(int x, int y, const char* message);
    void successToTFT(int x, int y, const char* message);
  public:
    TftDisplay();
    Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

    void init();
    void testDraw();

    ~TftDisplay();
};
#endif

#endif