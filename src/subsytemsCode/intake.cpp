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

Distance basketCheck(9);

//////// state machine
StateIntake current_number = StateIntake::BRAKE;

void how_many_rings(StateIntake request_number) {
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
			} else if (basketCheck.get_distance() <= 160) {
				while (basketCheck.get() >= 60 && basketLimit.get_value() == 1) {
					Intake.move(127);
				}
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
				delay(150);
				if (basketCheck.get() <= 210) {
					current_number = StateIntake::TWO;
				} else if (basketCheck.get() < 62) {
					current_number = StateIntake::BRAKE;
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
	if (controller.get_digital(E_CONTROLLER_DIGITAL_R1) && (basketLimit.get_value() == 1) && basketCheck.get() > 60) {
		Intake.move(127);
	} else if (controller.get_digital(E_CONTROLLER_DIGITAL_A)) {
		Intake.move(-127);
	} else {
		Intake.brake();
	}
}