#pragma once

#ifndef OledMenuFunctions_h
#define OledMenuFunctions_h

#include "configs.h"

#ifdef HAS_OLED_DISPLAY
#include "OledDisplay.h"

extern OledDisplay oled_display_obj;

struct MenuItem {
  String name;
  bool selected;
  std::function<void()> callable;
};

struct Menu {
  String name;
  LinkedList<MenuItem>* items;
  Menu* parentMenu;
};

// Main menu

class OledMenuFunctions {
public:
  OledMenuFunctions();
  void setupMenus();
  void changeMenu(Menu* menu);
  void displayMenu(Menu* menu, int starting_index = 0);
  void serialNavigateMenu(String direction);
  Menu* getCurrentMenu();
  ~OledMenuFunctions();

  Menu* currentMenu;
  Menu mainMenu;
  Menu wifiMenu;
  Menu scanAPsMenu;
};

#endif // HAS_OLED_DISPLAY

#endif // OledMenuFunctions_h