#ifndef PINS_HPP
#define PINS_HPP

enum PIN {
  //reserved 0
  //reserved 1
  HC_SR_04_TRIG = 2,
  HC_SR_04_ECHO = 3,
  HC_SR_501_OUTPUT = 4,
  //reserved 5
  BUZZER = 6,
  SCREEN_BL = 7,
  SCREEN_CLK = 8,  //SPI_SCK
  SCREEN_DIN = 9,  //SPI_MOSI
  SCREEN_DC = 10,
  SCREEN_RST = 11,
  SCREEN_CE = 12,  //SPI_CS
  // other digital pins
  LM35_OUTPUT = A0
};

#endif