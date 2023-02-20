#ifndef DETECTION_HPP
#define DETECTION_HPP

enum class DetectionLevel {
  UNKNOWN,
  DETECTED,
  CLEAR
};

class Detection {
public:
  virtual DetectionLevel isDetected() = 0;
  virtual int batteryLevel() = 0;
};

#endif