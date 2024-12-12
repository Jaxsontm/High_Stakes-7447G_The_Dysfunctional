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
	Intake.set_brake_mode(pros::MotorBrake::coast);
	basket.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
	basket.set_brake_mode(MotorBrake::hold);
	pros::Task mogo_machine(state_machine_mogo);
	pros::Task auton_selector_task(selector);
}

void disabled() {}

void competition_initialize() { selector(); }

void autonomous() {
	basketReset();
	pros::Task intake_machine(state_machine_intake);
		if (autonSelection == 0) {
			Skills();
		} else if (autonSelection == 1) {
				redRight();
		} else if (autonSelection == 2) {
				redLeft();
		} else if (autonSelection == 3) {
				redSolo();
		} else if (autonSelection == 4) {
				redRightElim();
		} else if (autonSelection == 5) {
				redLeftElim();
		} else if (autonSelection == 6) {
				blueRight();
		} else if (autonSelection == 7) {
				blueLeft();
		} else if (autonSelection == 8) {
				blueSolo();
		} else if (autonSelection == 9) {
				blueRightElim();
		} else if (autonSelection == 10) {
				blueLeftElim();
		}
}

void opcontrol() {
	Intake.set_brake_mode(pros::MotorBrake::coast);
	while (true) {
		intakeControl();
		mogoToggle();
		//liftPTOToggle();
		extenderToggle();
		//liftDriver();
		basketDriver();
		basketResetDriver();
		doinkerToggle();
		tank();
	
		// delay to save resources
		pros::delay(10);
	}
}