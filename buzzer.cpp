#include <Arduino.h>

#include "buzzer.hpp"

#include "utility.hpp"

static const int BUZZER_ON_VALUE = 60;
static const int BUZZER_OFF_VALUE = 0;

buzzer::buzzer(const int pin)
  : buzzer_pin(pin) {
  pinMode(buzzer_pin, OUTPUT);
}

Result buzzer::start() {
  analogWrite(buzzer_pin, BUZZER_ON_VALUE);
}

Result buzzer::stop() {
  analogWrite(buzzer_pin, BUZZER_OFF_VALUE);
}

Result buzzer::test() {
  start();
  delay(1000);
  stop();
  delay(1000);
}