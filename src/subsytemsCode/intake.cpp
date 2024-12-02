#include "subsystemsHeaders/intake.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/drive.hpp"

using namespace pros;

/////// globals
Motor Intake(-11, MotorGearset::blue);

Distance basketCheck(19);

//////// state machine
StateIntake current_state_intake = StateIntake::BRAKE;

void state_machine_intake(bool two_rings) {
  while (true) {
    switch (current_state_intake) {
    case StateIntake::LOAD:
      if (two_rings == true) {
        if (basketCheck.get() > 120) {
          while (basketCheck.get() > 120 && basketLimit.get_value() == 1) {
            Intake.move(127);
          }
          current_state_intake = StateIntake::CHECK;
        } else if (basketCheck.get() > 70) {
          while (basketCheck.get() > 70 && basketLimit.get_value() == 1) {
            Intake.move(127);
          }
       current_state_intake = StateIntake::CHECK;
        }
      } else {
        while (basketCheck.get() > 70 && basketLimit.get_value() == 1 ||
               basketCheck.get() > 120 && basketLimit.get_value() == 1) {
          Intake.move(127);
        }
        current_state_intake = StateIntake::CHECK;
      }
      break;
    case StateIntake::CHECK:
      if (basketLimit.get_value() == 0) {
        current_state_intake = StateIntake::BRAKE;
      } else {
        if (two_rings == true) {
         if (basketCheck.get() < 120) {
            current_state_intake = StateIntake::LOAD;
          } else if (basketCheck.get() < 70) {
            current_state_intake = StateIntake::BRAKE;
          }
        } else {
          current_state_intake = StateIntake::BRAKE;
        }
      }
      break;
    case StateIntake::BRAKE:
      Intake.brake();

      break;
    }
    delay(10);
  }
}

////// Driver Control
void intakeControl() {
  if (controller.get_digital(E_CONTROLLER_DIGITAL_R1) && (basketLimit.get_value() == 1) /*&& basketCheck.get() < 120*/) {
    Intake.move(127);
  } else if (controller.get_digital(E_CONTROLLER_DIGITAL_A)) {
    Intake.move(-127);
  } else {
    Intake.brake();
  }
}