#include "nah/main.h"
#include "auton.h"
#include "subsystems.h/drive.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.h"
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Intake State Machine
// enum representing the possible states of the mechanism
// states with higher priorities have lower numbers
// additional states can be added as needed


// the current state of the mechanism
State current_state = BRAKE;

// function used to request a new state
void request_new_state(State requested_state) {
  if (requested_state < current_state) {
    current_state = requested_state;
  }
  if (requested_state > current_state) {
    current_state = requested_state;
  }
}

// function which constantly updates the state of the mechanism
void state_machine() {
  // run forever
  while (true) {
    // switch statement to select what to do based on the current state
    switch (current_state) {
      // the Intake should be spinning
      case State::LOAD: {
        // if the Sensor does detect something, stop the intake
        if (DistanceIntake.get() < 1) current_state = State::IDLE;
        // if the Sensors doesn't detect anything, keep spinning the intake
        else Intake.move(-127);
        // break out of the switch statement
        break;
      }
      // the Intake should stop
      case State::IDLE: {
        if (DistanceMogo.get() < 49 or WallDistance.get() < 125) current_state = State::SCORE;
        //Stop the Intake from spinning
        else if (DistanceIntake.get() > 52 or WallDistance.get() > 127) current_state = State::BRAKE;
        // make the Intake hold its position
        else Intake.brake();
        // break out of the switch statement
        break;
      }
      case State::SCORE: {
        Intake.move(-127);
        //break out of the switch statement
        break;
      }
      case State::UNLOAD: {
        //reverse Intake for Driver Control
        Intake.move(127);
        //break out of the switch statement
        break;
      }
      case State::BRAKE: {
        //keep the Intake from spinning
        Intake.brake();
        //break out of the switch statement
        break;
      }
    }
    // delay to save resources
    pros::delay(10);
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// the current state of the mechanism
StateMogo current_state2 = RELEASE;

// function used to request a new state
void request_new_state_mogo(StateMogo requested_state_mogo) {
  if (requested_state_mogo < current_state2) {
    current_state2 = requested_state_mogo;
  }
  if (requested_state_mogo > current_state2) {
    current_state2 = requested_state_mogo;
  }
}

// function which constantly updates the state of the mechanism
void state_machine_mogo() {
  // run forever
  while (true) {
    // switch statement to select what to do based on the current state
    switch (current_state2) {
      // the Intake should be spinning
      case StateMogo::LOCATE: {
        // if the Sensor does detect something, stop the intake
        if (DistanceMogo.get() < 39) current_state2 = StateMogo::GRAB;
        // if the Sensors doesn't detect anything, keep spinning the intake
        else Mogo.set_value(false);
        // break out of the switch statement
        break;
      }
      case StateMogo::GRAB:{
        Mogo.set_value(true);
        break;
      }
      case StateMogo::RELEASE:{
        Mogo.set_value(false);
        break;
      }
    }
    // delay to save resources
    pros::delay(10);
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// the current state of the mechanism
StateLift current_state3 = LOWER;

// function used to request a new state
void request_new_state_lift(StateLift requested_state_lift) {
  if (requested_state_lift < current_state3) {
    current_state3 = requested_state_lift;
  }
  if (requested_state_lift > current_state3) {
    current_state3 = requested_state_lift;
  }
}

// function which constantly updates the state of the mechanism
void state_machine_lift() {
  // run forever
  while (true) {
    // switch statement to select what to do based on the current state
    switch (current_state3) {
      // the Intake should be spinning
      case StateLift::LOWER: {
        liftToAngle(-30);

        break;
      }
      case StateLift::ALLIANCE:{
        liftToAngle(20);

        break;
      }
      case StateLift::WALL:{
        liftToAngle(60);

        break;
      }
      case StateLift::STOP: {
        
      }
    }
    // delay to save resources
    pros::delay(10);
  }
}
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
    pros::Task state_machine_task_left(state_machine_lift);
    Intake.set_brake_mode(pros::MotorBrake::brake);
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
        pros::delay(500);
    console.println("Running auton...");
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

 bool static yPressed = false;
 bool static yState = false;

 bool static rightPressed = false;
 bool static rightState = false;


void opcontrol() {
    Intake.set_brake_mode(pros::MotorBrake::coast);
    Lift.set_brake_mode(pros::MotorBrake::hold);

	while (true) {

    /** get left y and right y positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

        //move the robot
        chassis.tank(leftY, rightY);
    */

    /////////////////////////////////////////////////////////////////

		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            request_new_state(State::SCORE);
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            request_new_state(State::UNLOAD);
        } else {
            request_new_state(State::BRAKE);
        }

    //////////////////////////////////////////////////////

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

    ////////////////////////////////////////////////////////////    
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

    //////////////////////////////////////////////////////
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
          Lift.move(127);
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
          Lift.move(-127);
        } else {
          Lift.brake();
        }
    /////////////////////////////////////////////////////
    

        // get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

        // move the robot
        chassis.tank(leftY, rightY);

        // delay to save resources
        pros::delay(25);

    

     }
	}
