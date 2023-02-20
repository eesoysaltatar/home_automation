#include <Arduino.h>

#include "lcd5110.hpp"

#include "nokia5110.hpp"

#include "utility.hpp"

nokia5110::nokia5110(const int clk,
                     const int din,
                     const int dc,
                     const int rst,
                     const int ce,
                     const int bl)
  : device(clk, din, dc, rst, ce), backlight_pin(bl) {
  pinMode(backlight_pin, OUTPUT);
  this->setBrightness(1);
  device.InitLCD();
  device.setContrast(65);
  device.clrScr();

  extern uint8_t SmallFont[];
  device.setFont(SmallFont);
}

Result nokia5110::setBrightness(const int value) {
  const int BRIGHTNESS_LIMIT = 0;
  if (value > BRIGHTNESS_LIMIT) {
    digitalWrite(backlight_pin, HIGH);
  } else {
    digitalWrite(backlight_pin, LOW);
  }
  return Result::SUCCESS;  //TODO if possible try to cover failure mode
}

Result nokia5110::setContrast(const int value) {
  device.setContrast(value);
  return Result::SUCCESS;  //TODO if possible try to cover failure mode
}


Result nokia5110::write(const String& text) {
  device.clrScr();
  //TODO new line support can be added
  device.print(text, 0, 0);
  return Result::SUCCESS;  //TODO if possible try to cover failure mode
}

Result nokia5110::clear() {
  device.clrScr();
  return Result::SUCCESS;  //TODO if possible try to cover failure mode
}