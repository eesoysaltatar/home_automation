#ifndef ALARM_HPP
#define ALARM_HPP

#include "utility.hpp"

class Alarm {
public:
  virtual Result start() = 0;
  virtual Result stop() = 0;
  virtual Result test() = 0;
};

#endif