#pragma once
#include "ScreenBase.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_BME280.h>

class ScreenMeteo : public ScreenBase {
public:
  ScreenMeteo(Adafruit_SSD1306* d, Adafruit_BME280* b)
    : display(d), bme(b) {}

  void draw() override {
    display->clearDisplay();
    display->setTextSize(2);
    display->setCursor(0, 0);
    display->print(bme->readTemperature(), 1);
    display->println("C");

    display->setTextSize(1);
    display->print("Hum: ");
    display->print(bme->readHumidity(), 1);
    display->println("%");

    display->print("Pres: ");
    display->print(bme->readPressure() / 100.0F, 0);
    display->println("hPa");

    display->display();
  }

private:
  Adafruit_SSD1306* display;
  Adafruit_BME280* bme;
};
