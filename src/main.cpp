#include "nah/main.h"
#include "liblvgl/llemu.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/llemu.hpp"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/intake.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"
#include "auton_selector.hpp"
#include "auton.h"
#include "subsystemsHeaders/mogo.hpp"


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
    chassis.calibrate();
    controller.rumble("-- .");
    Intake.set_brake_mode(pros::MotorBrake::coast);
    basket.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
    basket.set_brake_mode(MotorBrake::hold);
    pros::Task auton_selector_task(selector);
}   

void disabled() {}

void competition_initialize() {
    selector();
}

void autonomous() {
    switch (autonSelection) {
        default:
            Skills();
        case 0:
            Skills();
        case 1:
            redRight();
        case 2:
            redLeft();
        case 3:
            redSolo();
        case 4:
            redRightElim();
        case 5:
            redLeftElim();
        case 6:
            blueRight();
        case 7:
            blueLeft();
        case 8:
            blueSolo();
        case 9:
            blueRightElim();
        case 10:
            blueLeftElim();

    }
}

void opcontrol() {
    Intake.set_brake_mode(pros::MotorBrake::coast);
	while (true) {
    ///////////////////////////////////////////////////////////////

		intakeControl();

    /////////////////////////////////////////////////////////////////

        mogoToggle();

    /////////////////////////////////////////////////////////////////    
       


    /////////////////////////////////////////////////////////////////
        
        //liftToggle();

    /////////////////////////////////////////////////////////////////

        basketDriver();

        basketAllianceDriver();
    
    /////////////////////////////////////////////////////////////////
    
        tank();

        // delay to save resources
        pros::delay(20);
     }
	}
