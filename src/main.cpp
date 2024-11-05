#include "nah/main.h"
#include "auton.h"
#include "liblvgl/llemu.hpp"
#include "pros/llemu.hpp"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/intake.hpp"
#include "subsystemsHeaders/Lift.hpp"
#include "subsystemsHeaders/mogo.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"
#include "auton_selector.hpp"


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

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	//pros::lcd::initialize(); // initialize brain screen
    Intake.set_brake_mode(pros::MotorBrake::coast);
    pros::Task auton_selector_task(selector);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
bool auton = false;

void competition_initialize() {
    while (auton == false) {
        selector();
    }
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    switch (autonSelection) {
        case 0:
            none();
            break;
        case 1:
            Skills();
            break;
        case 2:
            redRight();
            break;
        case 3:
            redLeft();
            break;
        case 4:
            redSolo();
            break;
        case 5:
            redRightElim();
            break;
        case 6:
            redLeftElim();
            break;
        case 7:
            blueRight();
            break;
        case 8:
            blueLeft();
            break;
        case 9:
            blueSolo();
            break;
        case 10:
            blueRightElim();
            break;
        case 11:
            blueLeftElim();
            break;
    }
}
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
    Intake.set_brake_mode(pros::MotorBrake::coast);

	while (true) {

    /** get left y and right y positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

        //move the robot
        chassis.tank(leftY, rightY);
    */

    /////////////////////////////////////////////////////////////////

		intakeControl();

    /////////////////////////////////////////////////////////////////

        mogoToggle();

    /////////////////////////////////////////////////////////////////    
       


    /////////////////////////////////////////////////////////////////
        
        liftToggle();

    /////////////////////////////////////////////////////////////////

        basketDriver();

    /////////////////////////////////////////////////////////////////
    
        tank();

        // delay to save resources
        pros::delay(25);

    

     }
	}
