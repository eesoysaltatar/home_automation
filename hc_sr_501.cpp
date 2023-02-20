#include "Arduino.h"

#include "hc_sr_501.hpp"

#include "detection.hpp"


hc_sr_501::hc_sr_501(const int output) : output_pin(output){
  pinMode(output_pin, INPUT);
}

DetectionLevel hc_sr_501::isDetected(){
  DetectionLevel retVal{DetectionLevel::UNKNOWN};
  if(digitalRead(output_pin)){
    retVal = DetectionLevel::DETECTED;
  }
  else{
    retVal = DetectionLevel::CLEAR;
  }
  return retVal;
}

int hc_sr_501::batteryLevel(){
  //TODO
  return -1;
}