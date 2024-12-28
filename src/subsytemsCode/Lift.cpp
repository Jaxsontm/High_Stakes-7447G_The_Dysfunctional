#include "subsystemsHeaders/Lift.hpp"

///////// global
Motor lift(7, MotorGearset::green, MotorEncoderUnits::degrees);
////////Macro
void setLiftPos(int targetPos) {
  lift.move_absolute(targetPos, 127);
}

void liftLoad() {
  while (true) {
    while (lift.get_position() < 28) {
      lift.move(100);
    }
    lift.brake();
    delay(5);

    basket.move(38);
    int timeout = 70;
    for (int t = 0; t < timeout; t++) {
      if (basket.get_position() > 195) {
        t = timeout;
      }
      delay(10);
    }

    while (basketLimit.get_value() == 0) {
      basket.move(-127);
      delay(5);
    }
    basket.brake();
  }
}

void liftScore() {
  while (true) {
    lift.move(127);
    int timeout = 100;
    for (int t = 0; t < timeout; t++) {
      if (lift.get_position() > 195) {
        t = timeout;
      }
      delay(10);
    }
    lift.brake();
    delay(250);
    lift.move(-127);
    for (int t = 0; t < timeout; t++) {
      if (lift.get_position() < 2) {
        t = timeout;
      }
      delay(10);
    }
  }
}
//////// Driver Control
void liftDriver() {
  if (manual) {
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) 
      liftLoad();
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L2))
      liftScore();
  } else {
    if (controller.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) 
      lift.move(127);
    else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2))
      lift.move(127);
    else lift.brake();
  }
}