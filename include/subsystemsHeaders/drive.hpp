#pragma once
#include "lemlib/chassis/chassis.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
using namespace pros;

// controller
extern Controller controller;

// Green Ziptie

extern MotorGroup DTLeft;
extern MotorGroup DTRight;

extern Imu inertial_sensor;
//

extern lemlib::Drivetrain drivetrain;

extern lemlib::ControllerSettings linearController;

extern lemlib::ControllerSettings angularController;

extern Rotation horizontal_sensor;
extern Rotation vertical_sensor;

extern lemlib::TrackingWheel horizontal_tracking_wheel;
extern lemlib::TrackingWheel vertical_tracking_wheel;

extern lemlib::OdomSensors sensors;

// create the chassis
extern lemlib::Chassis chassis;

extern void tank();

extern void arcade();