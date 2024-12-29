#include "subsystemsHeaders/Lift.hpp"

///////// global
Motor lift(-7, MotorGearset::green, MotorEncoderUnits::degrees);

int liftPosition = 2;
////////Macro
void setLiftPos(int targetPos) {
  if (targetPos != liftPosition) {
    liftPosition = targetPos;
  }
}

/*void liftLoad() {
  while (true) {
    switch (liftPosition) {
      case 0: {
        int timeout = 20;
          lift.move(127);
          while (lift.get_position() > 125 && timeout != 0) {
            lift.move(127);
            timeout--;
            delay(10);
          }
          lift.brake();
          delay(35);

          basket.move(83);
          timeout = 150;
          for (int t = 0; t < timeout; t++) {
            if (basket.get_position() > 205) {
              t = timeout;
            }
            delay(10);
          }

          while (basketLimit.get_value() == 0) {
            basket.move(-127);
            delay(5);
          }
          liftPosition = 2;
          break;
      }
      case 1: {
        lift.move(127);
        int timeout = 70;
        for (int t = 0; t < timeout; t++) {
          if (fabs(lift.get_position()) > 365) {
            t = timeout;
          }
        }
          delay(10);
        lift.brake();
        delay(50);
        lift.move(-127);
        for (int t = 0; t < timeout; t++) {
          if (fabs(lift.get_position()) > 2) {
            t = timeout;
          }
        }
        delay(10);
        liftPosition = 2;
        break;
      }
      case 2: {
        basket.brake();
        lift.brake();
        break;
      }
    }
  }
}*/
//////// Driver Control
/*void liftDriver() {
  if (manual) {
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) {
      setLiftPos(0);
    }
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) {
      setLiftPos(1);
    }
  } else {
    if (controller.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) 
      lift.move(127);
    else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2))
      lift.move(127);
    else lift.brake();
  }
}*/