#include "MenuManager.h"
#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display;

void MenuManager::open(MenuItem* items, uint8_t count) {
  menuItems = items;
  itemCount = count;
  cursor = 0;
  active = true;
}

void MenuManager::close() {
  active = false;
}

bool MenuManager::isOpen() {
  return active;
}

void MenuManager::moveDown() {
  cursor = (cursor + 1) % itemCount;
}

void MenuManager::select() {
  if (menuItems[cursor].action)
    menuItems[cursor].action();
}

void MenuManager::back() {
  close();
}

void MenuManager::draw() {
  if (!active) return;

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("MENU");
  display.println("------------");

  for (uint8_t i = 0; i < itemCount; i++) {
    display.print(i == cursor ? "> " : "  ");
    display.println(menuItems[i].label);
  }

  display.display();
}
