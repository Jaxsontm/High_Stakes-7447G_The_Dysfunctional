#include "subsystemsHeaders/Lift.hpp"

///////// global
Motor lift(-7, MotorGearset::green, MotorEncoderUnits::degrees);

Rotation rotFinder(8);

adi::Button liftLimit('G');
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
        while (lift.get_position() < 138 && timeout > 0) {
          lift.move(127);
          timeout--;
          delay(10);
        }
        lift.set_brake_mode(MotorBrake::hold);
        lift.brake();
        delay(150);
        basketMove(StateBasket::LOAD);
        currentPos = liftPos::STOP;
      break;
      case liftPos::SCORE:
        timeout = 85;
        while (lift.get_position() < 400 && timeout > 0) {
          lift.move(127);
          timeout--;
          delay(10);
        }
        lift.set_brake_mode(MotorBrake::hold);
        currentPos = liftPos::STOP;
      break;
      case liftPos::RESET:
        while (liftLimit.get_value() == 0) lift.move(-60);
        lift.set_brake_mode(MotorBrake::brake);
        lift.brake();
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

  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) setLiftPos(liftPos::RESET);

}