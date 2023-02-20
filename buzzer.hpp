#ifndef BUZZER_HPP
#define BUZZER_HPP

#include "alarm.hpp"

#include "utility.hpp"

class buzzer : public Alarm {
private:
  int buzzer_pin;
public:
  buzzer(const int);
  Result start();
  Result stop();
  Result test();
};

#endif