#include "Servo.h"

Servo::Servo(PinName pin, int max_degree, int min_pulse, int max_pulse, int initial_value, int period_us) : _pwm(pin) {
  _max = max_degree;
  _min = 0;
  _minPulse = min_pulse;
  _maxPulse = max_pulse;
  period_us = (period_us < _maxPulse)? _maxPulse : period_us;
  _pwm.period_us(period_us);
  setDegree(initial_value);
}

Servo::Servo(PinName pin, ServoType servotype, int initial_value, int period_us) : _pwm(pin) {
  _min = 0;
  period_us = (period_us < _maxPulse)? _maxPulse : period_us;
  _pwm.period_us(period_us);
  setType(servotype);
  setDegree(initial_value);
}


void Servo::setDegree(int degree) {
  if(degree == FREE){
    _pwm = 0;
  }else {
    // _pwm.pulsewidth_us((_minPulse+(clamp(degree) / (double)_max) * (_maxPulse-_minPulse)));
    _pwm.pulsewidth_us( (int)(_minPulse+( ( constrain(degree, _min, _max) ) / (float)_max) * (_maxPulse-_minPulse)) );
  }
}

void Servo::setDegree(float degree) {
  if(degree == FREE){
    _pwm = 1;
  }else {
    // _pwm.pulsewidth_us((_minPulse+(clamp(degree) / (double)_max) * (_maxPulse-_minPulse)));
    _pwm.pulsewidth_us( (_minPulse + ( constrain(degree, _min, _max) / (float)_max ) * ( _maxPulse - _minPulse ) ) );
  }
}

void Servo::setType(ServoType servotype){
  _min = 0;
  _servo = servotype;
  switch(servotype){
    case DS238:
    _max = 135;
    _minPulse = 900;
    _maxPulse = 2100;
    break;

    case DS3218:
    _max = 270;
    _minPulse = 500;
    _maxPulse = 2500;
    break;

    case RB995:
    _max = 180;
    _minPulse = 500;
    _maxPulse = 1667;
    break;

    case RBS581:
    _max = 180;
    _minPulse = 1000;
    _maxPulse = 2000;
    break;
    
    case RS306MD:
    _max = 288;
    _minPulse = 560;
    _maxPulse = 2480;
    break;

    case SG90:
    _max = 180;
    _minPulse = 500;
    _maxPulse = 2400;
    break;

    case MG90D:
      _max = 120;
      _minPulse = 750;
      _maxPulse = 2250;
  }
}
