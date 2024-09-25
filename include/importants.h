#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"


// controller
extern pros::Controller controller;

// Green Ziptie

extern pros::MotorGroup DTLeft;
extern pros::MotorGroup DTRight;

extern pros::Imu inertial_sensor;
//

// Blue Ziptie
extern pros::Motor Intake;

extern pros::Distance DistanceIntake;

extern pros::adi::Pneumatics intakePiston;
//

// Yellow Ziptie
extern pros::Motor Lift;

extern pros::Distance WallDistance;
//

// Red Ziptie
extern pros::Distance DistanceMogo;

extern pros::adi::Pneumatics Mogo;
//

//Utilites White ziptie

// drivetrain settings
extern lemlib::Drivetrain drivetrain;

// lateral motion controller
extern lemlib::ControllerSettings
    linearController;

// angular motion controller
extern lemlib::ControllerSettings
    angularController;

//Rotation Sensors
extern pros::Rotation horizontal_sensor;
extern pros::Rotation vertical_sensor;

extern lemlib::TrackingWheel horizontal_tracking_wheel;
extern lemlib::TrackingWheel vertical_tracking_wheel;
// sensors for odometry
// note that in this example we use internal motor encoders (IMEs), so we don't
// pass vertical tracking wheels
extern lemlib::OdomSensors sensors;

// create the chassis
extern lemlib::Chassis chassis;

extern void waitUntilTankDist();

enum State { //Sets the name of the States in the Intake State Machine
    LOAD = 0, 
    IDLE = 1, 
    SCORE = 2, 
    UNLOAD = 3, 
    BRAKE = 4,
};

enum StateMogo { //Sets the name of the States in the Mogo State Machine
    LOCATE = 0, 
    GRAB = 1,
    RELEASE = 2
};

extern void state_machine();
extern void state_machine_mogo();
extern void request_new_state(State new_state);
extern void request_new_state_mogo(StateMogo new_state);

extern void LiftPID(double targetAngle);