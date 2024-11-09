#include "nah/main.h"
#include "liblvgl/llemu.hpp"
#include "pros/llemu.hpp"
#include "subsystemsHeaders/intake.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"
#include "auton_selector.hpp"
#include "auton.h"


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    pros::lcd::set_text(2, "I was pressed!");
  } else {
    pros::lcd::clear_line(2);
  }
}

void screen() {
    while (true) {
        pros::lcd::print(0, "X: %f", chassis.getPose().x);
        pros::lcd::print(1, "Y: %f", chassis.getPose().y);
        pros::lcd::print(2, "Theta: %f", chassis.getPose().theta);
        pros::delay(50);
    }
}

void initialize() {
    Intake.set_brake_mode(pros::MotorBrake::coast);
    pros::Task auton_selector_task(selector);
}

void disabled() {}

void competition_initialize() {
    selector();
}

void autonomous() {
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
    }
}

void opcontrol() {
    Intake.set_brake_mode(pros::MotorBrake::coast);
	while (true) {
    ///////////////////////////////////////////////////////////////

		intakeControl();

    /////////////////////////////////////////////////////////////////

        //mogoToggle();

    /////////////////////////////////////////////////////////////////    
       


    /////////////////////////////////////////////////////////////////
        
        //liftToggle();

    /////////////////////////////////////////////////////////////////

        //basketDriver();

    /////////////////////////////////////////////////////////////////
    
        tank();

        // delay to save resources
        pros::delay(25);

    

     }
	}
