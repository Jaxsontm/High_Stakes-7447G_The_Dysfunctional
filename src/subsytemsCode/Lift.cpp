#include "subsystemsHeaders/Lift.hpp"

///////// global
Motor lift(-7, MotorGearset::green, MotorEncoderUnits::degrees);

IMU rotFinder(4);

adi::Button liftLimit('G');
////////Macro
liftPos currentPos = liftPos::STOP;
int slew;

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
        liftPosition = 1;
        timeout = 30;
        slew = 2;
        while (rotFinder.get_roll() < 18 && lift.get_position() < 165 && timeout > 0) { 
          lift.move(100 + slew);
          timeout--;
          slew += 2;
          delay(10);
        }
        lift.move(100);
        lift.set_brake_mode(MotorBrake::hold);
        delay(20);
        lift.brake();
        delay(250);
        basketMove(StateBasket::LOAD);
        currentPos = liftPos::STOP;
      break;
      case liftPos::autoLOAD:
        liftPosition = 1;
        timeout = 30;
        slew = 2;
        while (rotFinder.get_roll() < 18 && lift.get_position() < 165 && timeout > 0) { 
          lift.move(100 + slew);
          timeout--;
          slew ++;
          delay(10);
        }
        lift.move(100);
        lift.set_brake_mode(MotorBrake::hold);
        delay(20);
        lift.brake();
        delay(250);
        basketMove(StateBasket::LOAD);
        delay(500);
        setLiftPos(liftPos::SCORE);
      break;
      case liftPos::SCORE:
        liftPosition = 2;
        timeout = 85;
        while (rotFinder.get_roll() < 112 && lift.get_position() < 485 && timeout > 0) {
          lift.move(127);
          timeout--;
          delay(10);
        }
        lift.set_brake_mode(MotorBrake::hold);
        currentPos = liftPos::STOP;
      break;
      case liftPos::RESET:
        liftPosition = 3;
        while (liftLimit.get_value() == 0) lift.move(-60);
        lift.set_brake_mode(MotorBrake::brake);
        lift.brake();
        currentPos = liftPos::STOP;
      break;
      case liftPos::STOP:
        liftPosition = 0;
        lift.brake();
        rotFinder.tare();
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