#include "importants.h"
#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"



void RightAWP() { 

    chassis.setPose(0, 0, 0);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPoint(0, -27.5, 1200, {.forwards = false, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

        request_new_state(SCORE);
pros::delay(950);

    chassis.turnToHeading(-90, 500, {.minSpeed = 30});

    chassis.moveToPose(-17, -27, -90, 1000, {.lead = 0});
chassis.waitUntilDone();
    
pros::delay(1250);

              intakePiston.set_value(true);

                    LiftPID(425);

    chassis.moveToPose(14, -5, 90, 2500, {.lead = 0.2, .maxSpeed = 80});
chassis.waitUntil(11);

            request_new_state_mogo(StateMogo::RELEASE);

      request_new_state(LOAD);
              
    chassis.moveToPoint(20, -5, 1000, {.maxSpeed = 40, .minSpeed = 30, .earlyExitRange = 1.5});

                    LiftPID(-425);

              intakePiston.set_value(false);

      request_new_state(IDLE);

    chassis.swingToHeading(24, lemlib::DriveSide::RIGHT, 1000);

        request_new_state(State::UNLOAD);
pros::delay(1000);

                    LiftPID(660);

    chassis.moveToPose(23, 14, 24, 1000);
chassis.waitUntilDone();

                    LiftPID(-235);
pros::delay(500);

    chassis.moveToPose(0, -33, 24, 1000, {.forwards = false});

                    LiftPID(-425);

    chassis.swingToHeading(-45, lemlib::DriveSide::RIGHT, 1000);
chassis.waitUntilDone();

        request_new_state(BRAKE);

    chassis.moveToPose(12, -50, -45, 1000, {.forwards = false, .maxSpeed = 30});
}

void LeftAWP() { 
    chassis.setPose(0, 0, 0);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPoint(0, -27.5, 1200, {.forwards = false, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

        request_new_state(SCORE);
pros::delay(950);

    chassis.turnToHeading(90, 500, {.minSpeed = 30});

    chassis.moveToPose(17, -27, 90, 1000, {.lead = 0});
chassis.waitUntilDone();
    
pros::delay(1250);

              intakePiston.set_value(true);

                    LiftPID(425);

    chassis.moveToPose(-14, -5, 90, 2500, {.lead = 0.2, .maxSpeed = 80});
chassis.waitUntil(11);

            request_new_state_mogo(StateMogo::RELEASE);

      request_new_state(LOAD);
              
    chassis.moveToPoint(-20, -5, 1000, {.maxSpeed = 40, .minSpeed = 30, .earlyExitRange = 1.5});

                    LiftPID(-425);

              intakePiston.set_value(false);

      request_new_state(IDLE);

    chassis.swingToHeading(-24, lemlib::DriveSide::RIGHT, 1000);

        request_new_state(State::UNLOAD);
pros::delay(1000);

                    LiftPID(660);

    chassis.moveToPose(-23, 14, -24, 1000);
chassis.waitUntilDone();

                    LiftPID(-235);
pros::delay(500);

    chassis.moveToPose(0, -33, -24, 1000, {.forwards = false});

                    LiftPID(-425);

    chassis.swingToHeading(45, lemlib::DriveSide::RIGHT, 1000);
chassis.waitUntilDone();

        request_new_state(BRAKE);

    chassis.moveToPose(-12, -50, 45, 1000, {.forwards = false, .maxSpeed = 30});
}

void Skills() {
    chassis.setPose(0,0,0);

            request_new_state_mogo(UNLOAD);
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
}

void BlueRight() {
    chassis.setPose(0, 0, 0);

    LiftPID(660);
}

/** top ring of the double stack
    intakePiston.set_value(true);

    request_new_state(State::LOAD);

    chassis.moveToPoint(0, 3, 1000);
    
    chassis.waitUntilDone();

    intakePiston.set_value(false);
    
    chassis.moveToPoint(0, -5, 1000, {.forwards = false});
 */
