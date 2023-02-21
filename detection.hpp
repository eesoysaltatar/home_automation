#ifndef DETECTION_HPP
#define DETECTION_HPP

#include "utility.hpp"

class Detection {
public:
  virtual DetectionLevel isDetected() = 0;
  virtual int batteryLevel() = 0;
};

#endif