#include "subsystemsHeaders/intake.hpp"
#include "subsystemsHeaders/drive.hpp"

/////// globals
Motor Intake(-11, MotorGearset::green);

Distance basketCheck(9);

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
        if (basketCheck.get_distance() >= 220) {
          while (basketCheck.get() >= 210 && basketLimit.get_value() == 1) {
            Intake.move(127);
          }
          current_number = StateIntake::BRAKE;
        } else if (basketCheck.get_distance() <= 200 && basketCheck.get() >= 100) {
          while (basketCheck.get() >= 60 && basketLimit.get_value() == 1) {
            Intake.move(127);
          }
          delay(500);
          current_number = StateIntake::BRAKE;
        }
        break;
      case StateIntake::TWO:
        if (basketCheck.get() >= 210) {
          while (basketCheck.get() >= 210 && basketLimit.get_value() == 1) {
            Intake.move(127);
          }
          current_number = StateIntake::CHECK;
        } else {
          while (basketCheck.get() > 60 && basketLimit.get_value() == 1) {
            Intake.move(127);
          }
          current_number = StateIntake::CHECK;
        }
        break;
      case StateIntake::CHECK:
        if (basketLimit.get_value() == 0) {
          current_number = StateIntake::BRAKE;
        } else {
          delay(350);
          if (basketCheck.get() <= 210) {
            current_number = StateIntake::TWO;
          } else if (basketCheck.get() < 62) {
            delay(350);
            current_number = StateIntake::BRAKE;
          }
        }
        break;
      case StateIntake::REV:
        Intake.move(-127);
        break;
      case StateIntake::BRAKE:
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
  if (controller.get_digital(E_CONTROLLER_DIGITAL_R1) && basketLimit.get_value() == 1){
    spinFor(StateIntake::FWD);
  } else if (controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
    spinFor(StateIntake::REV);
  } else {
    spinFor(StateIntake::BRAKE);
  }
}