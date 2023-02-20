#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <Arduino.h>

#include "utility.hpp"

class Display {
public:
  virtual Result setBrightness(const int) = 0;
  virtual Result setContrast(const int) = 0;
  virtual Result write(const String&) = 0;
  virtual Result clear() = 0;
};

#endif