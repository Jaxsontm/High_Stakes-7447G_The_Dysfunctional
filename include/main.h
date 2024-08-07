/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * \copyright Copyright (c) 2017-2023, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convenient for most student programmers.
 */

#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"

//controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//Green Ziptie

pros::MotorGroup DTLeft({-1, 2, -3}, pros::MotorGearset::blue);
pros::MotorGroup DTRight({12, -13, 14}, pros::MotorGearset::blue);

pros::Imu inertial_sensor(4); 
//

//Blue Ziptie
pros::Motor Intake(11, pros::MotorGearset::blue);

pros::Distance DistanceIntake(5);

pros::adi::Pneumatics intakePiston('B', false);
//

//Yellow Ziptie
pros::MotorGroup Descore({20, -19}, pros::MotorGearset::green);

pros::Distance DistanceDescore(10);
//

//Red Ziptie
pros::Distance DistanceMogo(18);

pros::adi::Pneumatics Mogo('A', false);
//






// drivetrain settings
lemlib::Drivetrain drivetrain(&DTLeft, // left motor group
                              &DTRight, // right motor group
                              14, // 10 inch track width
                              lemlib::Omniwheel::NEW_275, // using new 3.25" omnis
                              450, // drivetrain rpm is 360
                              2 // chase power is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linearController(12, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            35, // derivative gain (kD)
                                            0, // anti windup
                                            1, // small error range, in inches
                                            1000, // small error range timeout, in milliseconds
                                            30, // large error range, in inches
                                            3000, // large error range timeout, in milliseconds
                                            2 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(4.05, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             22, // derivative gain (kD)
                                             0, // anti windup
                                             1, // small error range, in degrees
                                             500, // small error range timeout, in milliseconds
                                             750, // large error range, in degrees
                                             750, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

pros::Rotation horizontal_sensor(6);
pros::Rotation vertical_sensor(7);

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_sensor, lemlib::Omniwheel::NEW_275, 2);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_sensor, lemlib::Omniwheel::NEW_275, -1.5);
// sensors for odometry
// note that in this example we use internal motor encoders (IMEs), so we don't pass vertical tracking wheels
lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &inertial_sensor // inertial sensor
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);

void waitUntilTankDist(double inches){ // creates a new function with the parameter inches
lemlib::Pose lastPose = chassis.getPose(); // creates a new value under the lemlib:pose class that holds the initial position of the robot
while(inches > 0) { // while inches is greater than 0, the inside bit runs
inches -= chassis.getPose().distance(lastPose); // redeclares param inches as inches minus distance away from the last position
lastPose = chassis.getPose(); // updates current position of robot
pros::delay(10); // adds delay to not overload sensors
} // slowly whittles down at inches until it is equal to 0, in which it will run the next line of code in queue

}

#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "auton.h"
#include "api.h"

/**
 * You should add more #includes here
 */
//#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
// using namespace pros;
// using namespace pros::literals;
// using namespace okapi;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
