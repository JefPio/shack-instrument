#include "buttons.h"

// ===== CONFIG =====
#define BTN_A_PIN  32
#define BTN_B_PIN  33

#define LONG_PRESS_MS 800

// ===== ESTADO INTERNO =====
static unsigned long aPressTime = 0;
static unsigned long bPressTime = 0;

static bool aPressed = false;
static bool bPressed = false;

// =============================
void buttonsInit() {
  pinMode(BTN_A_PIN, INPUT_PULLUP);
  pinMode(BTN_B_PIN, INPUT_PULLUP);
}

// =============================
ButtonEvent buttonsUpdate() {
  unsigned long now = millis();

  // -------- BOTÃO A --------
  if (!digitalRead(BTN_A_PIN)) {
    if (!aPressed) {
      aPressed = true;
      aPressTime = now;
    }
  } else if (aPressed) {
    aPressed = false;
    return (now - aPressTime > LONG_PRESS_MS) ? BTN_A_LONG : BTN_A_SHORT;
  }

  // -------- BOTÃO B --------
  if (!digitalRead(BTN_B_PIN)) {
    if (!bPressed) {
      bPressed = true;
      bPressTime = now;
    }
  } else if (bPressed) {
    bPressed = false;
    return (now - bPressTime > LONG_PRESS_MS) ? BTN_B_LONG : BTN_B_SHORT;
  }

  return BTN_NONE;
}
