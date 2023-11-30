#ifndef SERVO_H
#define SERVO_H
#include "mbed.h"

#define FREE 1000
#define constrain(n, min, max) ( (n<min)? (min) : (n>max)? (max) : (n) )

class Servo{

public:
  typedef enum ServoType{
    DS3218,
    DS238,
    RB995,
    RBS581,
    RS306MD,
    SG90,//SG92も同じ
    MG90D,
  }ServoType;

  Servo(PinName pin, int max_degree, int min_pulse, int max_pulse, int initial_value = 0, int period_us = 50000);
  Servo(PinName pin, ServoType servotype, int initial_value = 0, int period_us = 50000);

  void setDegree(int degree);
  void setDegree(float degree);
  void setType(ServoType servotype);
  ServoType getType(){return _servo;}


protected:
  PwmOut _pwm;
  int _maxPulse, _minPulse, _max, _min;
  ServoType _servo;
};

#endif
