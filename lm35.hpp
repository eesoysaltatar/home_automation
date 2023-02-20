#ifndef LM35_HPP
#define LM35_HPP

#include "temperature.hpp"

#include "utility.hpp"

class lm35 : public Temperature {
private:
  int sensor_pin;
public:
  lm35(const int);
  int getTemperature();
};

#endif