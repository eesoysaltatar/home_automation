#include <Arduino.h>

#include "lm35.hpp"

#include "utility.hpp"

static const float CELCIUS_MULTIPLIER = 0.4882815;

lm35::lm35(const int pin) : sensor_pin(pin){
  // no pin mode for analog input pins.
}
int lm35::getTemperature(){
  float temperature = analogRead(sensor_pin);
  return temperature*CELCIUS_MULTIPLIER;
}