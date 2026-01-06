#include "MenuManager.h"
#include "../screen/ScreenMenu.h"

extern ScreenMenu screenMenu;

MenuManager::MenuManager() {
  active = false;
  cursor = 0;
}

void MenuManager::open(MenuItem* items, uint8_t count) {
  menuItems = items;
  itemCount = count;
  cursor = 0;
  active = true;
  lastInteraction = millis();
}

void MenuManager::close() {
  active = false;
}

bool MenuManager::isOpen() {
  return active;
}

void MenuManager::onButtonUp() {
  if (!active) return;
  cursor = (cursor + 1) % itemCount;
  lastInteraction = millis();
}

void MenuManager::onButtonSelect() {
  if (!active) return;
  lastInteraction = millis();
  if (menuItems[cursor].action)
    menuItems[cursor].action();
}

void MenuManager::onButtonBack() {
  close();
}

void MenuManager::update() {
  if (!active) return;
  if (millis() - lastInteraction > MENU_TIMEOUT_MS) {
    close();
  }
}

void MenuManager::draw() {
  if (!active) return;
  screenMenu.draw(menuItems, itemCount, cursor);
}
