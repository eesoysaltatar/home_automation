#ifndef HC_SR_501_HPP
#define HC_SR_501_HPP

#include "detection.hpp"

class hc_sr_501 : public Detection {
private:
  int output_pin;
public:
  hc_sr_501(const int);
  DetectionLevel isDetected();
  int batteryLevel();
};

#endif