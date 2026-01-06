#pragma once
#include <Arduino.h>
#include "MenuItem.h"

class MenuManager {
public:
  void open(MenuItem* items, uint8_t count);
  void close();
  bool isOpen();

  void moveDown();
  void select();
  void back();

  void draw();

private:
  MenuItem* menuItems;
  uint8_t itemCount;
  uint8_t cursor = 0;
  bool active = false;
};
