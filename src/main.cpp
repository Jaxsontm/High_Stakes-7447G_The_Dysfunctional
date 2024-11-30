#include "nah/main.h"
#include "auton.h"
#include "auton_selector.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/rtos.hpp"
#include "subsystemsHeaders/Lift.hpp"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "subsystemsHeaders/intake.hpp"
#include "subsystemsHeaders/mogo.hpp"

void initialize() {
  chassis.calibrate();
  basketReset();
  autonSelection = 0;
  Intake.set_brake_mode(pros::MotorBrake::coast);
  basket.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  basket.set_brake_mode(MotorBrake::hold);
  pros::Task auton_selector_task(selector);
}

void disabled() {}

void competition_initialize() { selector(); }

void autonomous() {
  switch (autonSelection) {
    case 0: Skills(); break;
    case 1: redRight(); break;
    case 2: redLeft(); break;
    case 3: redSolo(); break;
    case 4: redRightElim(); break;
    case 5: redLeftElim(); break;
    case 6: blueRight(); break;
    case 7: blueLeft(); break;
    case 8: blueSolo(); break;
    case 9: blueRightElim(); break;
    case 10: blueLeftElim(); break;
    default: break;
  }
}

void opcontrol() {
  Intake.set_brake_mode(pros::MotorBrake::coast);
  while (true) {
    intakeControl();
    mogoToggle();
    liftPTOToggle();
    liftDriver();
    basketDriver();
    basketResetDriver();
    tank();
  
    // delay to save resources
    pros::delay(10);
  }
}