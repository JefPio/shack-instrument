#pragma once
#include <Arduino.h>

enum ButtonEvent {
  BTN_NONE,
  BTN_A_SHORT,
  BTN_A_LONG,
  BTN_B_SHORT,
  BTN_B_LONG
};

void buttonsInit();
ButtonEvent buttonsUpdate();
