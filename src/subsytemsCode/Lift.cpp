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

void liftMachine() {
  int timeout;
  while (true) {
    switch (currentPos) {
      case liftPos::LOAD:
        timeout = 25;
        while (lift.get_position() < 125 && timeout > 0) {
          lift.move(127);
          timeout--;
          delay(10);
        }
        lift.brake();
        delay(250);
        basketMove(StateBasket::SCORE);
      break;
      case liftPos::SCORE:
        timeout = 100;
        while (lift.get_position() < 385 && timeout > 0) {
          lift.move(127);
          timeout--;
          delay(10);
        }
        delay(500);
        currentPos = liftPos::RESET;
      break;
      case liftPos::RESET:
        timeout = 100;
        while (lift.get_position() > 0 && timeout > 0) {
          lift.move(-127);
          timeout--;
          delay(10);
        }
        lift.set_brake_mode(MotorBrake::brake);
        currentPos = liftPos::STOP;
      break;
      case liftPos::STOP:
        lift.brake();
        lift.tare_position();
      break;
      }
    delay(10);
  }
}
//////// Driver Control
void liftDriver() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) setLiftPos(liftPos::LOAD);
  
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) setLiftPos(liftPos::SCORE);
}