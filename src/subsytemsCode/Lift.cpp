#include "subsystemsHeaders/Lift.hpp"

///////// global
Motor lift(-7, MotorGearset::green, MotorEncoderUnits::degrees);

IMU rotFinder(4);

adi::Button liftLimit('G');
////////Macro
liftPos currentPos = liftPos::STOP;

void setLiftPos(liftPos requestedPos) {
  if (requestedPos != currentPos) {
    currentPos = requestedPos;
  }
}

void liftController(float target, int timeout) {
  const float kP = 50;
  const float kI = 0.02;
  const float kD = 0;
  float error = target;
  float prevError = 0;
  float integral = 0;
  float prevTime = 0;
  timeout /= 10;
  while (fabs(error) > 2 && timeout > 0) {
    double currTime = pros::millis() / 1000.0;
    double Δt = currTime - prevTime;
    prevTime = currTime;

    error = target - lift.get_position();
    double pTerm = kP * error;

    integral += error * Δt;
    double iTerm = kI * integral;

    double dTerm = kD * (error - prevError) / Δt;
    prevError = error;

    float output = pTerm + iTerm + dTerm;

    lift.move_voltage(output);

    timeout --;
    delay(10);
  }
  lift.brake();
}

void liftMachine() {
  while (true) {
    switch (currentPos) {
      case liftPos::autoLOAD:
        liftPosition = 1;
        liftController(165, 350);
        delay(250);
        basketMove(StateBasket::LOAD);
        delay(500);
        liftController(485, 600);
        delay(250);
        currentPos = liftPos::RESET;
      break;
      case liftPos::LOAD:
        liftPosition = 1;
        liftController(165, 350);
        delay(250);
        basketMove(StateBasket::LOAD);
        currentPos = liftPos::STOP;
      break;
      case liftPos::SCORE:
        liftPosition = 2;
        liftController(485, 600);
        lift.set_brake_mode(MotorBrake::hold);
        currentPos = liftPos::STOP;
      break;
      case liftPos::RESET:
        liftPosition = 3;
        while (liftLimit.get_value() == 0) lift.move(-60);
        lift.set_brake_mode(MotorBrake::brake);
        lift.brake();
        lift.tare_position();
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