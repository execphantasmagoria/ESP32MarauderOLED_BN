#include "DisplayNoTouch.h"

void TftDisplay::logToTFT(int x, int y, const char *message)
{
    tft.setCursor(x, y);
    tft.setTextColor(TFT_CYAN);
    tft.print("[INF] ");
    tft.setTextColor(TFT_WHITE);
    tft.println(message);
}

void TftDisplay::errorToTFT(int x, int y, const char *message)
{
    tft.setCursor(x, y);
    tft.setTextColor(TFT_RED);
    tft.print("[ERR] ");
    tft.setTextColor(TFT_WHITE);
    tft.println(message);
}

void TftDisplay::warningToTFT(int x, int y, const char *message)
{
    tft.setCursor(x, y);
    tft.setTextColor(TFT_YELLOW);
    tft.print("[WRN] ");
    tft.setTextColor(TFT_WHITE);
    tft.println(message);
}

void TftDisplay::successToTFT(int x, int y, const char *message)
{
    tft.setCursor(x, y);
    tft.setTextColor(TFT_GREEN);
    tft.print("[SUC] ");
    tft.setTextColor(TFT_WHITE);
    tft.println(message);
}

TftDisplay::TftDisplay()
{
    // Serial.println(F("TftDisplay constructor called"));
}

void TftDisplay::init()
{
    Serial.println(F("Initializing TFT display... (2)"));
    tft.initR(INITR_GREENTAB); 
    Serial.print(F("TFT CS: "));
    Serial.println(TFT_CS);
    Serial.print(F("TFT DC: "));
    Serial.println(TFT_DC);
    Serial.print(F("TFT RST: "));
    Serial.println(TFT_RST);
    Serial.print(F("TFT SCLK: "));
    Serial.println(TFT_SCLK);
    Serial.print(F("TFT MOSI: "));
    Serial.println(TFT_MOSI);
    Serial.println(F("Setting TFT rotation..."));
    tft.setRotation(0);
}

void TftDisplay::testDraw()
{
    Serial.println(F("Testing TFT display..."));
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(1);
    logToTFT(2, 10, "Initializing");
    logToTFT(2, 20, "Mounting SD");
    if(sd_obj.supported) {
      successToTFT(2, 30, "SD mounted!");
    }
    else {
      errorToTFT(2, 30, "SD not found!");
    }
    logToTFT(2, 40, "Loading modules");
    successToTFT(2, 50, "Modules loaded!");
    logToTFT(2, 60, "Init complete.");

    tft.setCursor(2, 90);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(1);
    tft.println("Starting...");

    delay(2000);

    tft.fillScreen(TFT_BLACK);

    tft.setCursor(2, 2);
    tft.setTextColor(TFT_RED);
    tft.setTextSize(2);
    tft.println("MarauderEX");
    
    tft.setCursor(2, 20);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(1);
    tft.println("version: 1.0");

    tft.setCursor(2, 30);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(1);
    tft.println("@execphantasmagoria");

    tft.drawLine(0, 40, TFT_WIDTH, 40, TFT_WHITE);

    tft.setCursor(10, 50);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(1);
    tft.println("1. WiFi Menu");

    tft.setCursor(10, 60);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(1);
    tft.println("2. RF Menu");

    tft.setCursor(10, 70);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(1);
    tft.println("3. BLE Menu");

    tft.setCursor(10, 80);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(1);
    tft.println("4. Exit");

    tft.drawLine(0, 90, TFT_WIDTH, 90, TFT_WHITE);

    tft.setCursor(2, 100);
    tft.setTextColor(TFT_WHITE);    
    tft.setTextSize(1);
    tft.println("Reading SD card...");
    
    tft.setCursor(2, 110);
    tft.setTextColor(TFT_GREEN);
    File testFile = sd_obj.getFile("/display.txt");

    if(testFile) {
    tft.println("display.txt:");
    while(testFile.available()) {
        tft.write(testFile.read());
    }
    testFile.close();
    }
    else {
    tft.setTextColor(TFT_RED);
    tft.println("display.txt not found!");
    }
}

TftDisplay::~TftDisplay()
{
    // Serial.println(F("TftDisplay destructor called"));
}
