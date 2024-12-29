#include "main.h"
#include "auton_selector.hpp"
#include "subsystemsHeaders/mogo.hpp"

void initialize() {
  chassis.calibrate();
  //pros::lcd::initialize();
	pros::Task auton_selector_task(selector);
	Intake.set_brake_mode(pros::MotorBrake::coast);
	basket.set_brake_mode(MotorBrake::brake);
  lift.set_brake_mode(MotorBrake::hold);
	pros::Task mogo_machine(state_machine_mogo);
	pros::Task intake_machine(state_machine_intake);
  pros::Task basket_machine(basketControl);
  pros::Task lift_machine(liftMachine);
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
	basket.set_brake_mode(MotorBrake::brake);
  Intake.set_brake_mode(pros::MotorBrake::coast);
  pros::Task display(text);
	while (true) {
		intakeControl();
		mogoToggle();
		doinkerToggle();
		liftDriver();
		basketDriver();
    tank();

    text();

    //pros::lcd::print(1, "Pos: %f", lift.get_position());
	
		// delay to save resources
		pros::delay(20);
	}
}