#include "main.h"
#include "auton.h"
#include "importants.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"


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





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Lift Angles
Set Zero:
lift.move_absolute(100, 127);
while (((Lift.get_position()) < 105) && (Lift.get_position()) > 95)) {
 pros::delay(5);
 }
 Lift.tare_position();
LOWER:
ALLIANCE:
WALL:
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	//pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    console.println("Initializing robot...");
    pros::Task state_machine_task(state_machine);
    pros::Task state_machine_task_mogo(state_machine_mogo);
    Intake.set_brake_mode(pros::MotorBrake::brake);
    Lift.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
    Lift.tare_position();
    pros::Task screenTask([&]() {
        lemlib::Pose pose(0, 0, 0);
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta);//heading
            
            // delay to save resources
            pros::delay(50); 
        }
    });
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
void competition_initialize() {}

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
  Lift.set_brake_mode(pros::MotorBrake::coast);
        pros::delay(500); 
    console.println("Running auton..."); //makes the auton selector properly function
	selector.run_auton();
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

 //these are booleans that allow us to have one button toggles for pistons
 bool static yPressed = false;
 bool static yState = false;

 bool static rightPressed = false;
 bool static rightState = false;


void opcontrol() {
  //sets the brake modes for the Intake and lift
    Intake.set_brake_mode(pros::MotorBrake::coast);
    Lift.set_brake_mode(pros::MotorBrake::hold); 

	while (true) {
    /////////////////////////////////////////////////////////////////
    //Intake buttons

		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            request_new_state(State::SCORE);
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            request_new_state(State::UNLOAD);
        } else {
            request_new_state(State::BRAKE);
        }

    /////////////////////////////////////////////////////////////////
    //MoGo Mech toggle 

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) && !yPressed && !yState) {
            request_new_state_mogo(StateMogo::GRAB);
            yPressed = true;
            yState = true;
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) && !yPressed && yState) {
            request_new_state_mogo(StateMogo::RELEASE);
            yPressed = true;
            yState = false;
        } else if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
            yPressed = false;
        }

    /////////////////////////////////////////////////////////////////
    //Intake Piston toggle    

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) && !rightPressed && !rightState) {
            intakePiston.set_value(true);
            rightPressed = true;
            rightState = true;
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) && !rightPressed && rightState) {
            intakePiston.set_value(false);
            rightPressed = true;
            rightState = false;
        } else if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            rightPressed = false;
        }

    /////////////////////////////////////////////////////////////////
    //Lift buttons
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
          Lift.move(-127);
        }  else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
          Lift.move(127);
        }  else {
          Lift.brake();
        }
    /////////////////////////////////////////////////////////////////
    //Drivetrain Mode
    
        // get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

        // move the robot
        chassis.tank(leftY, rightY);

        // delay to save resources
        pros::delay(25);
     }
	}
