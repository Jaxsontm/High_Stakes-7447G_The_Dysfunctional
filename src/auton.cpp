#include "importants.h"
#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/rtos.hpp"



void RightAWP() { 

    chassis.setPose(0, 0, 0);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPoint(0, -27.5, 1200, {.forwards = false, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

        request_new_state(SCORE);
pros::delay(950);

    chassis.turnToHeading(-110, 500, {.minSpeed = 127});
chassis.waitUntilDone();

    chassis.turnToHeading(-90, 500, {.minSpeed = 127});

    chassis.moveToPose(-17, -25, -90, 1000, {.lead = 0});
chassis.waitUntilDone();
    
pros::delay(1250);

              intakePiston.set_value(true);

    chassis.moveToPose(16, -2, 90, 2500, {.lead = 0.2, .maxSpeed = 80});
chassis.waitUntil(11);

      request_new_state(State::BRAKE);

            request_new_state_mogo(StateMogo::RELEASE);

      request_new_state(LOAD);
              
    chassis.moveToPoint(18, -2, 1000);

              intakePiston.set_value(false);

      request_new_state(LOAD);

    chassis.swingToHeading(24, lemlib::DriveSide::RIGHT, 1000);

        /**request_new_state(State::UNLOAD);

                    LiftPID(660);

    chassis.moveToPose(24, 12, 0, 1000);

                    LiftPID(-250);*/
}

void LeftAWP() { 
    chassis.setPose(0, 0, 0);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPoint(0, -27, 1200, {.forwards = false, .maxSpeed = 70, .minSpeed = 25, .earlyExitRange = 1});

    chassis.turnToHeading(90, 500);

    chassis.moveToPose(19, -25, -90, 1000, {.lead = 0});
    
      request_new_state(State::IDLE);
pros::delay(3000);

    chassis.moveToPose(-16, -8, -50, 2500, {.lead = 0.2, .maxSpeed = 80});

            request_new_state_mogo(StateMogo::RELEASE);

        request_new_state(State::SCORE);
pros::delay(1000);

    chassis.moveToPoint(-23, -3, 1000);

        request_new_state(State::LOAD);

    chassis.turnToHeading(180, 500);

    chassis.moveToPose(-22.5, 14, 180, 1100, {.forwards = false, .lead = 0, .maxSpeed = 80});

      request_new_state(State::IDLE);
pros::delay(1000);

    chassis.moveToPose(-20, -44, -135, 2000);
}

void Skills() {
    chassis.setPose(0,0,0);
}

void Score() {
    chassis.setPose(0,0,0);
}

void Forwards() { //finished
    chassis.setPose(0,0,0); 
//sets robot position to 0 on every axes
    chassis.moveToPose(0, 6, 0, 450, {.forwards = false, .minSpeed = 127});
//goes reverse 6 inches at max speed
    Intake.move(127); 
//spins the Intake to release the rubber band
pros::delay(1500);
    Lift.set_brake_mode(pros::MotorBrake::hold); 
//sets the brake mode to hold the lift instead of flowing back down
    Intake.brake();
//stops the intake from moving    
    Lift.tare_position();
//resets the lift's position
}

void BlueRight() {
    chassis.setPose(0, 0, 0);

    LiftPID(660, {100});
}

/** top ring of the double stack
    intakePiston.set_value(true);

    request_new_state(State::LOAD);

    chassis.moveToPoint(0, 3, 1000);
    
    chassis.waitUntilDone();

    intakePiston.set_value(false);
    
    chassis.moveToPoint(0, -5, 1000, {.forwards = false});
 */
