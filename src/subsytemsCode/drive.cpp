#include "lemlib/chassis/chassis.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
using namespace pros;

// controller
using pros::delay;

Controller controller(E_CONTROLLER_MASTER);

// Green Ziptie
MotorGroup DTLeft({-16, -15, 14}, MotorGearset::blue);
MotorGroup DTRight({20, 19, -18}, MotorGearset::blue);

Imu inertial_sensor(13);
//

// drivetrain settings
lemlib::Drivetrain drivetrain(
    &DTLeft,                    // left motor group
    &DTRight,                   // right motor group
    11,                         // 40 inch track width
    lemlib::Omniwheel::NEW_275, // using new 2.75" omnis
    450,                        // drivetrain rpm is 450
    2 // horizontal drift is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings
    linearController(12,    // proportional gain (kP)
                     0,     // integral gain (kI)
                     24,    // derivative gain (kD)
                     10,    // anti windup
                     1,     // small error range, in inches
                     100,   // small error range timeout, in milliseconds
                     30,    // large error range, in inches
                     30000, // large error range timeout, in milliseconds
                     10     // maximum acceleration (slew)
    );

// angular motion controller
lemlib::ControllerSettings
    angularController(1.045, // proportional gain (kP)
                      0,     // integral gain (kI)
                      6,     // derivative gain (kD)
                      2,     // anti windup
                      1,     // small error range, in degrees
                      500,   // small error range timeout, in milliseconds
                      15,    // large error range, in degrees
                      750,   // large error range timeout, in milliseconds
                      5      // maximum acceleration (slew)
    );

// Rotation Sensors
Rotation horizontal_sensor(12);
Rotation vertical_sensor(1);

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_sensor,
                                                lemlib::Omniwheel::NEW_2, 3.25);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_sensor,
                                              lemlib::Omniwheel::NEW_275, 0.5);
// sensors for odometry
// note that in this example we use internal motor encoders (IMEs), so we don't
// pass vertical tracking wheels
lemlib::OdomSensors sensors(
    &vertical_tracking_wheel, // vertical tracking wheel 1, set to null
    nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
    &horizontal_tracking_wheel, // horizontal tracking wheel 1
    nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a
             // second one
    &inertial_sensor // inertial sensor
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController,
                        sensors);

void waitUntilTankDist(
    double inches) { // creates a new function with the parameter inches
  lemlib::Pose lastPose =
      chassis.getPose(); // creates a new value under the lemlib:pose class that
                         // holds the initial position of the robot
  while (inches > 0) {   // while inches is greater than 0, the inside bit runs
    inches -= chassis.getPose().distance(
        lastPose); // redeclares param inches as inches minus distance away from
                   // the last position
    lastPose = chassis.getPose(); // updates current position of robot
    delay(10);                    // adds delay to not overload sensors
  } // slowly whittles down at inches until it is equal to 0, in which it will
    // run the next line of code in queue
}

void tank() {
  int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

  chassis.tank(leftY, rightY);
}

void arcade() {
  int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

  chassis.arcade(leftY, rightX);
}