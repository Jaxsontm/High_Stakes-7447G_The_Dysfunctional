#include "subsystemsHeaders/Lift.hpp"

///////// global
Motor lift(-7, MotorGearset::green, MotorEncoderUnits::degrees);
////////Macro
liftPos currentPos = liftPos::STOP;

void setLiftPos(liftPos requestedPos) {
  if (requestedPos != currentPos) {
    currentPos = requestedPos;
  }
}

//LOAD lift.get_position() > 125; basket.get_position() > 205; while (basketLimit.get_value() == 0) { basket.move(-127); delay(5);}
//SCORE lift.get_position() > 385
void liftMachine() {
  int timeout;
  while (true) {
    switch (currentPos) {
      case liftPos::LOAD:
        timeout = 30;
        while (lift.get_position() < 125 && timeout > 0) {
          lift.move(127);
          timeout--;
          delay(10);
        }
        lift.brake();
        timeout = 90;
        basket.move(127);
        for (int t = 0; t < timeout; t++) {
          if (basket.get_position() > 205) {
            t = timeout;
          }
          delay(10);
        }
        delay(350);
        while (basketLimit.get_value() == 0) basket.move(-127);
        currentPos = liftPos::STOP;
      break;
      case liftPos::SCORE:
        timeout = 60;
        while (lift.get_position() < 385 && timeout > 0) {
          lift.move(127);
          timeout--;
          delay(10);
        }
        delay(500);
        currentPos = liftPos::RESET;
        break;
      case liftPos::RESET:
        timeout = 70;
        while (lift.get_position() > 0 && timeout > 0) {
          lift.move(-127);
          timeout--;
          delay(10);
        }
        currentPos = liftPos::STOP;
        break;
      case liftPos::STOP:
        lift.brake();
        lift.tare_position();
        basket.brake();
        basket.tare_position();
        break;
      }
  }
}
//////// Driver Control
void liftDriver() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) {
    setLiftPos(liftPos::LOAD);
  }
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) {
    setLiftPos(liftPos::SCORE);
  }
}