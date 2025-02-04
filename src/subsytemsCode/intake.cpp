#include "subsystemsHeaders/intake.hpp"

/////// globals
Motor Intake(-11, MotorGearset::green);

Distance basketCheck(9);

bool first = true;

bool p = false;

pros::Task *intake_task = nullptr;
//////// piston
adi::Pneumatics intakeP('F', false);

void intakePtoggle() {
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
    p = !p;
    intakeP.set_value(p);
  }
}

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
          if (basketCheck.get_distance() >= 205 && basketCheck.get_distance() <= 140) {
            while (basketCheck.get() >= 205 && basketCheck.get_distance() <= 100 && basketLimit.get_value() == 1) {
              Intake.move(127);
            }
            delay(500);
            current_number = StateIntake::BRAKE;
          } else {
            while ((basketCheck.get() > 90 || basketCheck.get() < 60) && basketLimit.get_value() == 1) {
              Intake.move(127);
            }
            current_number = StateIntake::BRAKE;
          }
      break;
      case StateIntake::TWO:
        intakeState = 2;
        if (first) {
          while ((basketCheck.get() >= 205 || basketCheck.get() < 100) && basketLimit.get_value() == 1) {
            Intake.move(127);
          }
          current_number = StateIntake::CHECK;
        } else {
          while ((basketCheck.get() > 90 || basketCheck.get() < 60) && basketLimit.get_value() == 1) {
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
          if (first == true) {
            first = false;
            delay(750);
            current_number = StateIntake::TWO;
          } else {
            delay(350);
            first = true;
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

void startIntake() {
  stopIntake();

  intake_task = new pros::Task(state_machine_intake);
}

void stopIntake() {
  if (intake_task != nullptr) {
    intake_task->remove();
    delete intake_task;
    intake_task = nullptr;
  }
}

void resetIntake() {
  startIntake();
  StateIntake current_number = StateIntake::BRAKE;
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