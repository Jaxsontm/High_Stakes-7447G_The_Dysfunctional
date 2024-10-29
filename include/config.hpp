#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
using namespace pros;


// controller
extern Controller controller;

// Green Ziptie

extern MotorGroup DTLeft;
extern MotorGroup DTRight;

extern Imu inertial_sensor;
//

// Blue Ziptie
extern Motor Intake;

extern Distance DistanceIntakeTop;

extern Distance DistanceIntakeBottom;

extern adi::Pneumatics intakePiston;
//

// Yellow Ziptie
extern Motor LiftA;

extern Motor LiftB;
//

// Red Ziptie
extern Distance DistanceMogo;

extern adi::Pneumatics Mogo;
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
extern Rotation horizontal_sensor;
extern Rotation vertical_sensor;

extern lemlib::TrackingWheel horizontal_tracking_wheel;
extern lemlib::TrackingWheel vertical_tracking_wheel;
// sensors for odometry
// note that in this example we use internal motor encoders (IMEs), so we don't
// pass vertical tracking wheels
extern lemlib::OdomSensors sensors;

// create the chassis
extern lemlib::Chassis chassis;

extern void waitUntilTankDist();

enum StateIntake { //Sets the name of the States in the Intake State Machine
    LOAD = 0, 
    MECH = 1,
    STOP = 2,
    SCORE = 3, 
    UNLOAD = 4, 
    BRAKE = 5,
};

enum StateMogo { //Sets the name of the States in the Mogo State Machine
    LOCATE = 0, 
    GRAB = 1,
    RELEASE = 2,
    dcGRAB = 3
};

extern void state_machine_intake();
extern void state_machine_mogo();
extern void request_new_state_intake(StateIntake new_state);
extern void request_new_state_mogo(StateMogo new_state);