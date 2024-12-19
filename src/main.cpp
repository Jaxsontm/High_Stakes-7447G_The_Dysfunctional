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
	pros::Task auton_selector_task(selector);
	chassis.calibrate();
	Intake.set_brake_mode(pros::MotorBrake::coast);
	basket.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
	basket.set_brake_mode(MotorBrake::hold);
	pros::Task mogo_machine(state_machine_mogo);
  pros::Task intake_machine(state_machine_intake);
  pros::Task basket_machine(basketControl);
  
}

void disabled() {}

void competition_initialize() { selector(); }

void autonomous() {
	basketMove(StateBasket::RESET);
	switch(autonSelection) {
		case 0:
			redRight();
			break;
		case 1:
			redLeft();
			break;
		case 2:
			redSolo();
			break;
		case 3:
			redRightElim();
			break;
		case 4:
			redLeftElim();
			break;
		case 5:
			blueRight();
			break;
		case 6:
			blueLeft();
			break;
		case 7:
			blueSolo();
			break;
		case 8:
			blueRightElim();
			break;
		case 9:
			blueLeftElim();
			break;	
		default:
			Skills();
			break;
	}
}

void opcontrol() {
	basket.set_brake_mode(MotorBrake::hold);
	Intake.set_brake_mode(pros::MotorBrake::coast);
	while (true) {
		intakeControl();
		mogoToggle();
		liftToggle();
		basketDriver();
		basketResetDriver();
		doinkerToggle();
		tank();
	
		// delay to save resources
		pros::delay(10);
	}
}