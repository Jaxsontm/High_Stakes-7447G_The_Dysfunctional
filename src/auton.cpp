#include "importants.h"
#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"



void RightAWP() { 

    chassis.setPose(0, 0, -45);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPose(27, -29, -45, 1200, {.forwards = false, .lead = 0, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

    while (Mogo.extend() == false) {
        pros::delay(5);
    }

pros::delay(250);

        request_new_state(SCORE);
pros::delay(950);

    chassis.turnToPoint(9, -25.8, 500, {.minSpeed = 30});

        request_new_state(MECH);

    chassis.moveToPoint(7, -26, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

    while (DistanceIntake.get() > 15) {
        pros::delay(5);
    }

        request_new_state(UNLOAD);

    chassis.moveToPoint(5, -26, 1000);
    
/*pros::delay(1750);

    chassis.swingToHeading(50, lemlib::DriveSide::RIGHT, 1000, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
chassis.waitUntilDone(); 

    chassis.moveToPose(35, 2, 80, 2500, {.lead = 0.4, .maxSpeed = 80});
chassis.waitUntil(11);

      request_new_state(SCORE);

              LiftPID(425);

                intakePiston.set_value(true);
chassis.waitUntilDone();

pros::delay(500);
                intakePiston.set_value(false); 

                    LiftPID(-430);

    chassis.moveToPose(32, 2, 90, 1000, {.maxSpeed = 70, .minSpeed = 50});
                    
pros::delay(1200);

    chassis.swingToHeading(31, lemlib::DriveSide::RIGHT, 1000);

pros::delay(1250);

                    LiftPID(660);

    chassis.moveToPose(30, 14, 32, 1000, {.lead = 0});
chassis.waitUntilDone();

                    LiftPID(-235);
pros::delay(500);

    chassis.moveToPoint(25, -27, 1000, {.forwards = false, .maxSpeed = 110, .earlyExitRange = 3});

                    LiftPID(-425);

    chassis.swingToHeading(-55, lemlib::DriveSide::RIGHT, 1000);
chassis.waitUntilDone();

        request_new_state(BRAKE);*/
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

      //request_new_state(IDLE);

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
    
    request_new_state_mogo(LOCATE);
    chassis.moveToPoint(0, -10, 1000, {.forwards = false});
request_new_state(SCORE);
  chassis.moveToPoint(0, 10, 1000, {.minSpeed = 120});           //request_new_state_mogo(StateMogo::LOCATE);
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
