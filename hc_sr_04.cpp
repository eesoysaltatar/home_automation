#include <Arduino.h>

#include "hc_sr_04.hpp"

#include "utility.hpp"

hc_sr_04::hc_sr_04(const int trig, const int echo)
  : trigger_pin(trig), echo_pin(echo) {
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

float hc_sr_04::calculate_distance() {
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger_pin, LOW);

  unsigned long time = pulseIn(echo_pin, HIGH);
  return (time / 2) / 29.1;  // v = x/t
}

DetectionLevel hc_sr_04::isDetected() {
  const int DETECTION_DISTANCE_IN_CM = 40;
  DetectionLevel retVal{ DetectionLevel::UNKNOWN };

  float distance = this->calculate_distance();

  if (distance <= DETECTION_DISTANCE_IN_CM) {
    retVal = DetectionLevel::DETECTED;
  } else {
    retVal = DetectionLevel::CLEAR;
  }
  return retVal;
}

int hc_sr_04::batteryLevel() {
  //TODO
  return -1;
}