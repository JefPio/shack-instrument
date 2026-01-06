#pragma once
#include "ScreenBase.h"
#include <Adafruit_SSD1306.h>
#include <TinyGPS++.h>

class ScreenGPS : public ScreenBase {
public:
  ScreenGPS(Adafruit_SSD1306* d, TinyGPSPlus* g)
    : display(d), gps(g) {}

  void draw() override {
    display->clearDisplay();
    display->setTextSize(2);
    display->setCursor(0, 0);

    if (gps->time.isValid()) {
      display->printf("%02d:%02d\n",
        gps->time.hour(),
        gps->time.minute()
      );
    } else {
      display->println("--:--");
    }

    display->setTextSize(1);
    display->print("Sat: ");
    display->println(gps->satellites.value());

    display->display();
  }

private:
  Adafruit_SSD1306* display;
  TinyGPSPlus* gps;
};
