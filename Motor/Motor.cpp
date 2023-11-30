#include "Motor.h"

// Motor::Motor(PinName dirpin1, PinName pwmpin, PinName dirpin2) : _dir1(dirpin1), _pwm(pwmpin), _dir2(dirpin2) {
//   _dir1 = 0;
//   _pwm = 0;
//   _pwm.period_us(50);
//   if (dirpin2 == NC) _md_kind = 1;
//   else _md_kind = 0;
//   // _dirpin1 = dirpin1;
//   // _pwmpin = pwmpin;
//   // _dirpin2 = dirpin2;
// }

Motor::Motor(PinName dirpin1, PinName pwmpin, bool flagLAP) : _dir1(dirpin1), _pwm(pwmpin) {
  _dir1 = 0;
  _flagLAP = flagLAP;
  if (flagLAP) _pwm = 0.5;
  else _pwm = 0;
  _pwm.period_us(1000);
}

// void Motor::setSpeed(double duty) {
//   duty = (duty<min)? min : ((duty>max)? max : duty);
//   if(_md_kind){
//     _dir1=(duty>0);
//     _pwm = abs(duty);
//   }else{
//     _dir1=(duty>0);
//     _pwm = abs(duty);
//     _dir2=(duty<0);
//   }
// }

void Motor::setSpeed(double duty) {
  duty = (duty < min) ? min : ((duty > max) ? max : duty);
  // if (!_flagLAP) {
  _dir1 = (duty > 0);
  _pwm  = abs(duty);
  // } else {
  //   _dir1 = 1;
  //   _dir1 = !!duty;
  //   _pwm  = duty / 2. + 0.5;
  // }
}
