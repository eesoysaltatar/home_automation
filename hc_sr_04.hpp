#ifndef HC_SR_04_HPP
#define HC_SR_04_HPP

#include "detection.hpp"

class hc_sr_04 : public Detection {
private:
  int trigger_pin;
  int echo_pin;
  float calculate_distance();
public:
  hc_sr_04(const int, const int);
  DetectionLevel isDetected();
  int batteryLevel();
};

#endif