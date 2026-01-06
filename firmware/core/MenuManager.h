#pragma once
#include <Arduino.h>
#include "MenuItem.h"

#define MENU_TIMEOUT_MS 10000

class MenuManager {
public:
  MenuManager();

  void open(MenuItem* items, uint8_t count);
  void close();
  bool isOpen();

  void onButtonUp();
  void onButtonSelect();
  void onButtonBack();

  void update();
  void draw();

private:
  MenuItem* menuItems;
  uint8_t itemCount;
  uint8_t cursor;

  unsigned long lastInteraction;
  bool active;
};
