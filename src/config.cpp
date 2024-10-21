#include "config.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "pros/rtos.h"
using namespace pros;

// controller
using pros::delay;

Controller controller(E_CONTROLLER_MASTER);

// Green Ziptie

 MotorGroup DTLeft({-15, 16, -17}, MotorGearset::blue);
 MotorGroup DTRight({12, -13, 14}, MotorGearset::blue);

 Imu inertial_sensor(9);
//

// Blue Ziptie
 Motor Intake(-11, MotorGearset::blue);

 Distance DistanceIntakeTop(19);

 Distance DistanceIntakeBottom(21);

 adi::Pneumatics intakePiston('B', false);
//

// Yellow Ziptie
 Motor Lift(-1, MotorGearset::green);
//

// Red Ziptie
 Distance DistanceMogo(8);

 adi::Pneumatics Mogo('A', false);
//

//Utilites White ziptie

// drivetrain settings
 lemlib::Drivetrain drivetrain(
    &DTLeft,                    // left motor group
    &DTRight,                   // right motor group
    14,                         // 10 inch track width
    lemlib::Omniwheel::NEW_275, // using new 3.25" omnis
    450,                        // drivetrain rpm is 360
    2 // chase power is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
 lemlib::ControllerSettings
    linearController(12.01,   // proportional gain (kP)
                     0.0001,    // integral gain (kI)
                     52,   // derivative gain (kD)
                     3,    // anti windup
                     1,    // small error range, in inches
                     1000, // small error range timeout, in milliseconds
                     30,   // large error range, in inches
                     3000, // large error range timeout, in milliseconds
                     2     // maximum acceleration (slew)
    );

// angular motion controller
 lemlib::ControllerSettings
    angularController(4, // proportional gain (kP)
                      0.00006,    // integral gain (kI)
                      36,   // derivative gain (kD)
                      2,    // anti windup
                      1,    // small error range, in degrees
                      500,  // small error range timeout, in milliseconds
                      750,  // large error range, in degrees
                      750,  // large error range timeout, in milliseconds
                      0     // maximum acceleration (slew)
    );

//Rotation Sensors
 Rotation horizontal_sensor(10);
 Rotation vertical_sensor(18);

 lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_sensor,
                                                lemlib::Omniwheel::NEW_275, 1.375);
 lemlib::TrackingWheel vertical_tracking_wheel(&vertical_sensor,
                                              lemlib::Omniwheel::NEW_275, -1.25);
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
    delay(10);              // adds delay to not overload sensors
  } // slowly whittles down at inches until it is equal to 0, in which it will
    // run the next line of code in queue
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Intake State Machine

// the current state of the mechanism
StateIntake current_state_intake = BRAKE;

// functions used to request a new state
void request_new_state_intake(StateIntake requested_state_intake) {
  if (requested_state_intake != current_state_intake) {
    current_state_intake = requested_state_intake;
  }
}

// function which constantly updates the state of the mechanism
void state_machine_intake() {
  while (true) {
    switch (current_state_intake) {
      case StateIntake::LOAD: {
        if (DistanceIntakeTop.get() < 20) current_state_intake = StateIntake::MECH;
       
        else Intake.move(-127);
       
        break; // break out of the switch statement
      }
      case StateIntake::MECH: {
        while (DistanceIntakeTop.get_distance() > 31) {
          Intake.move(-127);
          while (DistanceIntakeBottom.get() <= 50){
            Intake.move(-63);
            delay(5);
          }
          delay(5);
        }

        if (DistanceIntakeTop.get() <= 30) current_state_intake = StateIntake::UNLOAD;

        break;
      }
      case StateIntake::STOP: {
        while (DistanceIntakeTop.get() > 31) {
          Intake.move(-127);
          while (DistanceIntakeBottom.get() <= 50){
            Intake.move(-63);
            delay(5);
          }
          delay(5);
        }

        if (!Mogo.is_extended()){
          Intake.move(0);
          delay(5);
        } else current_state_intake = StateIntake::SCORE;

        break;
      }
      case StateIntake::SCORE: {
        Intake.move(-127);
      
        break;
      }
      case StateIntake::UNLOAD: {
        Intake.move(127);

        break;
      }
      case StateIntake::BRAKE: {
        Intake.brake();

        break;
      }
    }
    // delay to save resources
    delay(10);
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// the current state of the mechanism
StateMogo current_state_mogo = RELEASE;

// function used to request a new state
void request_new_state_mogo(StateMogo requested_state_mogo) {
  if (requested_state_mogo != current_state_mogo) {
    current_state_mogo = requested_state_mogo;
  }
}

// function which constantly updates the state of the mechanism
void state_machine_mogo() {
  // run forever
  while (true) {
    // switch statement to select what to do based on the current state
    switch (current_state_mogo) {
      // the MoGo Mech should be open
      case StateMogo::LOCATE: {
        if (DistanceMogo.get() <= 83) current_state_mogo = StateMogo::GRAB;
        
        else Mogo.set_value(false);

        break;
      }
      case StateMogo::GRAB: {
        delay(100);

        Mogo.set_value(true);

        delay(250);

        break;
      }
      case StateMogo::RELEASE: {
        Mogo.set_value(false);

        break;
      }
      case StateMogo::dcGRAB: {
        Mogo.set_value(true);

        delay(250);

        break;
      }
    }
    // delay to save resources
    delay(10);
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LiftPID(double targetAngle){
  double kP;
  double kI;
  double kD;
  lemlib::PID LiftController(
        kP = 0.15,
        kI = 0.0175,
        kD = 0.75,
        5,
        false
  );

  double error;
  double prevError = 0;
  double revError;
  double prevRevError = 0;
  double integral = 0;
  double revIntegral;
  double revDerivative;
  double currentAngle = Lift.get_position();
  if (currentAngle < targetAngle){
    while ((error < 1) && (error > -1)) {
      error = (currentAngle - targetAngle) - 1.25; //proportional
      integral = integral + error; //integral

      if (error == 0) {
        integral = 0;
      }

      if (std::abs(error) > 1200) {
        integral = 0;
      }

      double derivative = error - prevError; //derivative
      prevError = error;

      double speed = (kP*error + kI*integral + kD*derivative) * 1.4;
        
      Lift.move_absolute(error, speed);


      if ((error < 1) && (error > -1)) {
        break;
      }
    }
  } else {
    while ((revError < 1) && (revError > -1)) {
      revError = (targetAngle - currentAngle); //proportional
      revIntegral = revIntegral + (revError * -1); //revIntegral

      if (revError == 0) {
        revIntegral = 0;
      }

      if (std::abs(revError) > 1200) {
        revIntegral = 0;
      }

      double revDerivative = revError - prevRevError; //derivative
      prevRevError = revError;

      double speed = (kP*revError + kI*revIntegral + kD*revDerivative);
        
      Lift.move_absolute(revError, speed);


      if ((revError < 1) && (revError > -1)) {
        break;
      }
    }
  }
}

//Alliance = 660
//Wall = 1150

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Intake State Machine

// the current state of the mechanism
/*StateLift current_state_lift = liftSTOP;

// functions used to request a new state
void request_new_state_lift(StateLift requested_state_lift) {
  if (requested_state_lift != current_state_lift) {
    current_state_lift = requested_state_lift;
  }
}

// function which constantly updates the state of the mechanism
void state_machine_lift() {
  // run forever
  while (true) {
    switch (current_state_lift) {
      case StateLift::NEUTRAL: {
        LiftPID(1150);
              
        break;
      }
      case StateLift::ALLIANCE: {
        LiftPID(720);

        break;
      }
      case StateLift::neutralDOWN: {
        LiftPID(-1150);

        break;
      }
      case StateLift::allianceDOWN: {
        LiftPID(720);
        
        break;
      }
      case StateLift::UP: {
        Lift.move(-127);
        
        break;
      }
      case StateLift::DOWN: {
        Lift.move(127);

        break;
      }
      case StateLift::liftSTOP: {
        Lift.brake();

        break;
      }
      case StateLift::Raise: {
        LiftPID(425);

        break;
      }
      case StateLift::Lower: {
        LiftPID(-425);

        break;
      }
    }
    // delay to save resources
    delay(10);
  }
}*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////