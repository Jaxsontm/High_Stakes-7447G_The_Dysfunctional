#include "main.h"
#include "subsystemsHeaders/lift.hpp"

void initialize() {
  chassis.calibrate();
  //pros::lcd::initialize();
	Intake.set_brake_mode(pros::MotorBrake::coast);
	basket.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
	basket.set_brake_mode(MotorBrake::brake);
  lift.set_zero_position(0);
	pros::Task auton_selector_task(selector);
	pros::Task mogo_machine(state_machine_mogo);
	intake_machine = new pros::Task(state_machine_intake);
  basket_machine = new pros::Task(basketControl);
  lift_load = new pros::Task (liftLoad);
  lift_score = new pros::Task(liftScore);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  request_new_state_mogo(StateMogo::RELEASE);
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
  pros::Task texts(text);
	while (true) {
		intakeControl();
		mogoToggle();
		doinkerToggle();
		liftDriver();
		basketDriver();
    manualToggle();
    tank();

    text();

    pros::lcd::print(1, "Pos: %f", lift.get_position());
	
		// delay to save resources
		pros::delay(20);
	}
}