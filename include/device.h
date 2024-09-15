#pragma once

/**
static and inline are used to be bale to set everything wihtin .h files.
 */

#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pid.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"

// controller
static pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Green Ziptie

static pros::MotorGroup DTLeft({-15, 16, -17}, pros::MotorGearset::blue);
static pros::MotorGroup DTRight({12, -13, 14}, pros::MotorGearset::blue);

static pros::Imu inertial_sensor(4);
//

// Blue Ziptie
static pros::Motor Intake(-11, pros::MotorGearset::blue);

static pros::Distance DistanceIntake(5);

static pros::adi::Pneumatics intakePiston('B', false);
//

// Yellow Ziptie
static pros::Motor Lift(1, pros::MotorGearset::green);

static pros::adi::Encoder Liftsensor('H','G');

static pros::Distance WallDistance(10);
//

// Red Ziptie
static pros::Distance DistanceMogo(18);

static pros::adi::Pneumatics Mogo('A', false);
//

//Utilites White ziptie

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

//Lift PID///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static float kP;
static float kI;
static float kD;

static float liftAngle = -30;
static void convertLiftsensor(float value) {
    liftAngle = value/6;
}

static lemlib::PID LiftPID(
   kP = 1,
   kI = 0,
   kD = 0,
   5,
   false
);

static void liftToAngle(double targetAngle) {
    double currentAngle = liftAngle;
  while (currentAngle != targetAngle) {  
    double error = targetAngle - liftAngle;
    double integral = integral + error;

    if (error == 0) {
        integral = 0;
    }

    if (std::abs(error) > 40) {
        integral = 0;
    }

    double previousError = error;
    double derivative = error - previousError;
    
    double speed = kP*error + kI*integral + kD*derivative;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////