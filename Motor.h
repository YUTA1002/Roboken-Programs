#ifndef MOTOR_H
#define MOTOR_H

#include "mbed.h"

#define min -1
#define max  1

class Motor {
  protected:
    // PinName _dirpin1, _dirpin2, _pwmpin;
    // Motor(const Motor& m);
    // Motor& operator=(const Motor& m) {
    //   return *this;
    // }
  
  public:
    // Motor(PinName dirpin1, PinName pwmpin, PinName dirpin2 = NC);
    Motor(PinName dirpin1, PinName pwmpin, bool flagLAP = 0);
    void setSpeed(double duty = 0);
  
  private:
    DigitalOut _dir1;
    PwmOut _pwm;
    // DigitalOut _dir2;
    bool _md_kind;
    bool _flagLAP;
};

#endif
