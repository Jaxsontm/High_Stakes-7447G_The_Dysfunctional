#include "subsystemsHeaders/intake.hpp"
#include "subsystemsHeaders/basket.hpp"

/////// globals
Motor Intake(-11, MotorGearset::green);

Distance basketCheck(9);

bool first = true;
//////// state machine
StateIntake current_number = StateIntake::BRAKE;

void spinFor(StateIntake request_number) {
	if (request_number != current_number) {
		current_number = request_number;
	}
}

void state_machine_intake() {
	while (true) {
		switch (current_number) {
      case StateIntake::ONE:
        intakeState = 1;
        if (basketCheck.get_distance() >= 190 && basketCheck.get_distance() <= 140) {
          while (basketCheck.get() >= 205 && basketCheck.get_distance() <= 100 && basketLimit.get_value() == 1) {
            Intake.move(127);
          }
          delay(500);
          current_number = StateIntake::BRAKE;
        } else {
          while (basketCheck.get() >= 80 && basketLimit.get_value() == 1) {
            Intake.move(127);
          }
          delay(500);
          current_number = StateIntake::BRAKE;
        }
      break;
      case StateIntake::TWO:
        intakeState = 2;
        if (basketCheck.get() >= 190) {
          while ((basketCheck.get() >= 205 || basketCheck.get() < 100) && basketLimit.get_value() == 1) {
            Intake.move(127);
          }
          current_number = StateIntake::CHECK;
        } else {
          while (basketCheck.get() > 80 && basketLimit.get_value() == 1) {
            Intake.move(127);
          }
          current_number = StateIntake::CHECK;
        }
      break;
      case StateIntake::CHECK:
        intakeState = 3;
        if (basketLimit.get_value() == 0) {
          current_number = StateIntake::BRAKE;
        } else {
          delay(350);
          if (first) {
            first = !first;
            current_number = StateIntake::TWO;
          } else {
            delay(350);
            first = !first;
            current_number = StateIntake::BRAKE;
          }
        }
      break;
      case StateIntake::REV:
        Intake.move(-127);
      break;
      case StateIntake::BRAKE:
        intakeState = 0;
        Intake.brake();
      break;
      case StateIntake::FWD:
        Intake.move(127);
      break;
      }
    delay(10);
	}
}

////// Driver Control
void intakeControl() {
  if (controller.get_digital(E_CONTROLLER_DIGITAL_R1) /*&& basketLimit.get_value() == 1*/){
    spinFor(StateIntake::FWD);
  } else if (controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
    spinFor(StateIntake::REV);
  } else {
    spinFor(StateIntake::BRAKE);
  }
}