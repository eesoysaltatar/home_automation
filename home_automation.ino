/*
TODO-1: Can we use smart pointers in Arduino?
TODO-X: Battery level how to detect?
*/

#include "detection.hpp"
#include "hc_sr_501.hpp"
#include "hc_sr_04.hpp"

#include "display.hpp"
#include "nokia5110.hpp"

#include "temperature.hpp"
#include "lm35.hpp"

#include "alarm.hpp"
#include "buzzer.hpp"

#include "utility.hpp"
#include "pins.hpp"

Detection* pirSensor = nullptr;
Detection* ultraSonicSensor = nullptr;
Display* screen = nullptr;
Alarm* blackBuzzer = nullptr;
Temperature* tempSensor = nullptr;

void setup() {
  //create detection modules
  pirSensor = new hc_sr_501(HC_SR_501_OUTPUT);
  ultraSonicSensor = new hc_sr_04(HC_SR_04_TRIG, HC_SR_04_ECHO);

  //create display module
  screen = new nokia5110(SCREEN_CLK, SCREEN_DIN, SCREEN_DC, SCREEN_RST, SCREEN_CE, SCREEN_BL);

  //create temperature sensor
  tempSensor = new lm35(LM35_OUTPUT);

  //create alarm module
  blackBuzzer = new buzzer(BUZZER);
  blackBuzzer->test();
}

void loop() {
  if ((pirSensor->isDetected() == DetectionLevel::DETECTED) || (ultraSonicSensor->isDetected() == DetectionLevel::DETECTED)) {
    blackBuzzer->start();
    screen->write("Motion detected!");
    delay(5000);
    blackBuzzer->stop();
    screen->clear();
  } else {
    screen->write(String(tempSensor->getTemperature()));
    delay(1000);
  }
}
