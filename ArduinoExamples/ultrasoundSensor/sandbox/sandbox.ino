
#include <Wire.h>

Adafruit_PWMServoDriver::Adafruit_PWMServoDriver(uint8_t addr) {
  _i2caddr = addr;
}

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

