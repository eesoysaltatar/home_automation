#ifndef NOKIA5110_HPP
#define NOKIA5110_HPP

#include <Arduino.h>

#include "lcd5110.hpp"

#include "display.hpp"

#include "utility.hpp"

class nokia5110 : public Display {
private:
  LCD5110 device;
  int backlight_pin;

public:
  nokia5110(const int, const int, const int, const int, const int, const int);
  Result setBrightness(const int);
  Result setContrast(const int);
  Result write(const String&);
  Result clear();
};

#endif