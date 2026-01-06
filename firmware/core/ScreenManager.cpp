#include "ScreenManager.h"

ScreenManager::ScreenManager() {
  state = STATE_MAIN_SCREEN;
  lastActivity = millis();
  lastSwitch = millis();
  currentIndex = 0;
}

void ScreenManager::registerMain(ScreenBase* s) {
  mainScreen = s;
}

void ScreenManager::registerScreensaver(ScreenBase** list, uint8_t count) {
  screens = list;
  screenCount = count;
}

void ScreenManager::notifyActivity() {
  lastActivity = millis();
  state = STATE_MAIN_SCREEN;
}

void ScreenManager::update() {
  unsigned long now = millis();

  if (state == STATE_MAIN_SCREEN) {
    if (now - lastActivity > IDLE_TIMEOUT_MS) {
      state = STATE_SCREENSAVER;
      currentIndex = 0;
      lastSwitch = now;
    }
  } else {
    if (now - lastSwitch > SCREENSAVER_TIME_MS) {
      currentIndex = (currentIndex + 1) % screenCount;
      lastSwitch = now;
    }
  }
}

void ScreenManager::draw() {
  if (state == STATE_MAIN_SCREEN) {
    mainScreen->draw();
  } else {
    screens[currentIndex]->draw();
  }
}
