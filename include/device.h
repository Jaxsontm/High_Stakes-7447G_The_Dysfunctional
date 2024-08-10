#pragma once

/**
static and inline are used to be bale to set everything wihtin .h files.
 */

#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"

// controller
static pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Green Ziptie

static pros::MotorGroup DTLeft({-1, 2, -3}, pros::MotorGearset::blue);
static pros::MotorGroup DTRight({12, -13, 14}, pros::MotorGearset::blue);

static pros::Imu inertial_sensor(4);
//

// Blue Ziptie
static pros::Motor Intake(11, pros::MotorGearset::blue);

static pros::Distance DistanceIntake(5);

static pros::adi::Pneumatics intakePiston('B', false);
//

// Yellow Ziptie
static pros::MotorGroup Descore({20, -19}, pros::MotorGearset::green);

static pros::Distance DistanceDescore(10);
//

// Red Ziptie
static pros::Distance DistanceMogo(18);

static pros::adi::Pneumatics Mogo('A', false);
//

// drivetrain settings
static lemlib::Drivetrain drivetrain(
    &DTLeft,                    // left motor group
    &DTRight,                   // right motor group
    14,                         // 10 inch track width
    lemlib::Omniwheel::NEW_275, // using new 3.25" omnis
    450,                        // drivetrain rpm is 360
    2 // chase power is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
static lemlib::ControllerSettings
    linearController(12,   // proportional gain (kP)
                     0,    // integral gain (kI)
                     35,   // derivative gain (kD)
                     0,    // anti windup
                     1,    // small error range, in inches
                     1000, // small error range timeout, in milliseconds
                     30,   // large error range, in inches
                     3000, // large error range timeout, in milliseconds
                     2     // maximum acceleration (slew)
    );

// angular motion controller
static lemlib::ControllerSettings
    angularController(4.05, // proportional gain (kP)
                      0,    // integral gain (kI)
                      22,   // derivative gain (kD)
                      0,    // anti windup
                      1,    // small error range, in degrees
                      500,  // small error range timeout, in milliseconds
                      750,  // large error range, in degrees
                      750,  // large error range timeout, in milliseconds
                      0     // maximum acceleration (slew)
    );

static pros::Rotation horizontal_sensor(6);
static pros::Rotation vertical_sensor(7);

static lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_sensor,
                                                lemlib::Omniwheel::NEW_275, 2);
static lemlib::TrackingWheel vertical_tracking_wheel(&vertical_sensor,
                                              lemlib::Omniwheel::NEW_275, -1.5);
// sensors for odometry
// note that in this example we use internal motor encoders (IMEs), so we don't
// pass vertical tracking wheels
static lemlib::OdomSensors sensors(
    &vertical_tracking_wheel, // vertical tracking wheel 1, set to null
    nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
    &horizontal_tracking_wheel, // horizontal tracking wheel 1
    nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a
             // second one
    &inertial_sensor // inertial sensor
);

// create the chassis
static lemlib::Chassis chassis(drivetrain, linearController, angularController,
                        sensors);

static void waitUntilTankDist(
    double inches) { // creates a new function with the parameter inches
  lemlib::Pose lastPose =
      chassis.getPose(); // creates a new value under the lemlib:pose class that
                         // holds the initial position of the robot
  while (inches > 0) {   // while inches is greater than 0, the inside bit runs
    inches -= chassis.getPose().distance(
        lastPose); // redeclares param inches as inches minus distance away from
                   // the last position
    lastPose = chassis.getPose(); // updates current position of robot
    pros::delay(10);              // adds delay to not overload sensors
  } // slowly whittles down at inches until it is equal to 0, in which it will
    // run the next line of code in queue
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Intake State Machine
// enum representing the possible states of the mechanism
// states with higher priorities have lower numbers
// additional states can be added as needed


// the current state of the mechanism
static State current_state = BRAKE;

// function used to request a new state
 inline void request_new_state(State requested_state) {
  if (requested_state < current_state) {
    current_state = requested_state;
  }
  if (requested_state > current_state) {
    current_state = requested_state;
  }
}

// function which constantly updates the state of the mechanism
inline void state_machine() {
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
        if (DistanceMogo.get() < 49 or DistanceDescore.get() < 125) current_state = State::SCORE;
        //Stop the Intake from spinning
        else if (DistanceIntake.get() > 52 or DistanceDescore.get() > 127) current_state = State::BRAKE;
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
      case State::UNLOAD:{
        //reverse Intake for Driver Control
        Intake.move(127);
        //break out of the switch statement
        break;
      }
      case State::BRAKE:{
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
static StateMogo current_state2 = RELEASE;

// function used to request a new state
inline void request_new_state_mogo(StateMogo requested_state_mogo) {
  if (requested_state_mogo < current_state2) {
    current_state2 = requested_state_mogo;
  }
  if (requested_state_mogo > current_state2) {
    current_state2 = requested_state_mogo;
  }
}

// function which constantly updates the state of the mechanism
inline void state_machine_mogo() {
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