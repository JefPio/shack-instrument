#pragma once
#include <Adafruit_SSD1306.h>
#include "../core/MenuItem.h"

class ScreenMenu {
public:
  ScreenMenu(Adafruit_SSD1306* d) : display(d) {}

  void draw(MenuItem* items, uint8_t count, uint8_t cursor) {
    display->clearDisplay();
    display->setTextSize(1);
    display->setCursor(0, 0);
    display->println("MENU");
    display->println("----------------");

    for (uint8_t i = 0; i < count; i++) {
      display->print(i == cursor ? "> " : "  ");
      display->println(items[i].label);
    }

    display->display();
  }

private:
  Adafruit_SSD1306* display;
};
