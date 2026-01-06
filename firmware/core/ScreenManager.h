#pragma once
#include <Arduino.h>
#include "../screen/ScreenBase.h"
#include "../config/constants.h"

enum SystemState {
  STATE_MAIN_SCREEN,
  STATE_SCREENSAVER
};

class ScreenManager {
public:
  ScreenManager();

  void update();
  void draw();

  void registerMain(ScreenBase* s);
  void registerScreensaver(ScreenBase** list, uint8_t count);

  void notifyActivity();

private:
  SystemState state;
  unsigned long lastActivity;
  unsigned long lastSwitch;
  uint8_t currentIndex;

  ScreenBase* mainScreen;
  ScreenBase** screens;
  uint8_t screenCount;
};
