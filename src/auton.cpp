#include "config.hpp"
#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"



void RightAWP() { //finished
    chassis.setPose(0, 0, -45);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPose(27, -29, -45, 1200, {.forwards = false, .lead = 0, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

    while (Mogo.extend() == false) {
        pros::delay(5);
    }
    
        request_new_state_intake(SCORE);
pros::delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(11, -25.5, 500);   

    chassis.moveToPoint(11, -25.75, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

pros::delay(250);

    chassis.moveToPoint(17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

    while (DistanceIntakeTop.get() > 16) {
        pros::delay(5);
    }

    while (DistanceIntakeTop.get() < 80) {
        pros::delay(5);
    }

pros::delay(250);

   chassis.turnToHeading(30, 500, {.minSpeed = 100});
chassis.waitUntilDone(); 

    chassis.moveToPose(29, 3, 80, 2500, {.lead = 0.3, .maxSpeed = 90});
chassis.waitUntil(9);

      request_new_state_intake(SCORE);

              LiftPID(425);

                intakePiston.set_value(true);
chassis.waitUntilDone();

                intakePiston.set_value(false); 

                    LiftPID(-415);

    chassis.moveToPose(24, 3, 80, 1000, {.maxSpeed = 70, .minSpeed = 70});
                    
pros::delay(450);

    chassis.swingToHeading(26, lemlib::DriveSide::RIGHT, 1000);

                    LiftPID(720);

pros::delay(650);

    chassis.moveToPose(29, 12, 26, 1000, {.lead = 0});
chassis.waitUntilDone();

                    LiftPID(-285);
pros::delay(500);

    chassis.moveToPoint(25, -27, 1000, {.forwards = false, .maxSpeed = 110, .earlyExitRange = 3});

                    LiftPID(-425);

    chassis.swingToHeading(-55, lemlib::DriveSide::RIGHT, 700);

    chassis.moveToPose(38, -36, -55, 1000, {.forwards = false, .maxSpeed = 60});
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BlueRight() {
    chassis.setPose(0, 0, -45);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPose(27, -29, -45, 1200, {.forwards = false, .lead = 0, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

    while (Mogo.extend() == false) {
        pros::delay(5);
    }
    
        request_new_state_intake(SCORE);
pros::delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(11, -25.5, 500);   

    chassis.moveToPoint(11, -25.75, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

pros::delay(250);

    chassis.moveToPoint(17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

    while (DistanceIntakeTop.get() > 16) {
        pros::delay(5);
    }

    while (DistanceIntakeTop.get() < 80) {
        pros::delay(5);
    }

pros::delay(250);

   chassis.turnToHeading(30, 500, {.minSpeed = 100});
chassis.waitUntilDone(); 

    chassis.moveToPose(29, 3, 80, 2500, {.lead = 0.3, .maxSpeed = 90});
chassis.waitUntil(9);

      request_new_state_intake(SCORE);

              LiftPID(425);

                intakePiston.set_value(true);
chassis.waitUntilDone();

                intakePiston.set_value(false); 

                    LiftPID(-415);

    chassis.moveToPose(24, 3, 80, 1000, {.maxSpeed = 70, .minSpeed = 70});
                    
pros::delay(450);

    chassis.swingToHeading(26, lemlib::DriveSide::RIGHT, 1000);

                    LiftPID(720);

pros::delay(650);

    chassis.moveToPose(29, 12, 26, 1000, {.lead = 0});
chassis.waitUntilDone();

                    LiftPID(-285);
pros::delay(500);

    chassis.moveToPoint(25, 3, 1000, {.forwards = false, .maxSpeed = 110, .earlyExitRange = 3});

                    LiftPID(-425);

    chassis.swingToHeading(-90, lemlib::DriveSide::RIGHT, 850);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RedRight(){
    chassis.setPose(0, 0, -45);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPose(27, -29, -45, 1200, {.forwards = false, .lead = 0, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

    while (Mogo.extend() == false) {
        pros::delay(5);
    }
    
        request_new_state_intake(SCORE);
pros::delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(11, -25.5, 500);   

    chassis.moveToPoint(11, -25.75, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

pros::delay(250);

    chassis.moveToPoint(17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

    while (DistanceIntakeTop.get() > 16) {
        pros::delay(5);
    }

    while (DistanceIntakeTop.get() < 80) {
        pros::delay(5);
    }

pros::delay(250);

   chassis.turnToHeading(30, 500, {.minSpeed = 100});
chassis.waitUntilDone(); 

    chassis.moveToPose(29, 3, 80, 2500, {.lead = 0.3, .maxSpeed = 90});
chassis.waitUntil(9);

      request_new_state_intake(SCORE);

              LiftPID(425);

                intakePiston.set_value(true);
chassis.waitUntilDone();

                intakePiston.set_value(false); 

                    LiftPID(-415);

    chassis.moveToPose(24, 3, 80, 1000, {.maxSpeed = 70, .minSpeed = 70});
                    
pros::delay(450);

    chassis.swingToHeading(26, lemlib::DriveSide::RIGHT, 1000);

                    LiftPID(720);

pros::delay(650);

    chassis.moveToPose(29, 12, 26, 1000, {.lead = 0});
chassis.waitUntilDone();

                    LiftPID(-285);
pros::delay(500);

    chassis.moveToPoint(25, -27, 1000, {.forwards = false, .maxSpeed = 110, .earlyExitRange = 3});

                    LiftPID(-425);

    chassis.swingToHeading(135, lemlib::DriveSide::LEFT, 700);

    chassis.moveToPose(0, 0, 135, 1000, {.forwards = false, .minSpeed = 120});
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Forwards() { //finished
    chassis.setPose(0,0,0); 
//sets robot position to 0 on every axes
    chassis.moveToPose(0, 6, 0, 450, {.forwards = false, .minSpeed = 127});
//goes reverse 6 inches at max speed
    Intake.move(127); 
//spins the Intake to release the rubber band
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LeftAWP() { 
    chassis.setPose(0, 0, 45);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPose(-27, -29, -45, 1200, {.forwards = false, .lead = 0, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

    while (Mogo.extend() == false) {
        pros::delay(5);
    }
    
        request_new_state_intake(SCORE);
pros::delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(-11, -25.5, 500);   

    chassis.moveToPoint(-11, -25.75, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

pros::delay(250);

    chassis.moveToPoint(-17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

    while (DistanceIntakeTop.get() > 16) {
        pros::delay(5);
    }

    while (DistanceIntakeTop.get() < 80) {
        pros::delay(5);
    }

pros::delay(250);

   chassis.turnToHeading(-30, 500, {.minSpeed = 100});
chassis.waitUntilDone(); 

    chassis.moveToPose(-29, 3, -80, 2500, {.lead = 0.3, .maxSpeed = 90});
chassis.waitUntil(9);

      request_new_state_intake(SCORE);

              LiftPID(425);

                intakePiston.set_value(true);
chassis.waitUntilDone();

                intakePiston.set_value(false); 

                    LiftPID(-415);

    chassis.moveToPose(-24, 3, -80, 1000, {.maxSpeed = 70, .minSpeed = 70});
                    
pros::delay(450);

    chassis.swingToHeading(-26, lemlib::DriveSide::LEFT, 1000);

                    LiftPID(720);

pros::delay(650);

    chassis.moveToPose(-29, 12, -26, 1000, {.lead = 0});
chassis.waitUntilDone();

                    LiftPID(-285);
pros::delay(500);

    chassis.moveToPoint(-25, -27, 1000, {.forwards = false, .maxSpeed = 110, .earlyExitRange = 3});

                    LiftPID(-425);

    chassis.swingToHeading(55, lemlib::DriveSide::LEFT, 700);

    chassis.moveToPose(-38, -36, 55, 1000, {.forwards = false, .maxSpeed = 60});
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BlueLeft() {
    chassis.setPose(0, 0, 45);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPose(-27, -29, -45, 1200, {.forwards = false, .lead = 0, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

    while (Mogo.extend() == false) {
        pros::delay(5);
    }
    
        request_new_state_intake(SCORE);
pros::delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(-11, -25.5, 500);   

    chassis.moveToPoint(-11, -25.75, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

pros::delay(250);

    chassis.moveToPoint(-17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

    while (DistanceIntakeTop.get() > 16) {
        pros::delay(5);
    }

    while (DistanceIntakeTop.get() < 80) {
        pros::delay(5);
    }

pros::delay(250);

   chassis.turnToHeading(-30, 500, {.minSpeed = 100});
chassis.waitUntilDone(); 

    chassis.moveToPose(-29, 3, -80, 2500, {.lead = 0.3, .maxSpeed = 90});
chassis.waitUntil(9);

      request_new_state_intake(SCORE);

              LiftPID(425);

                intakePiston.set_value(true);
chassis.waitUntilDone();

                intakePiston.set_value(false); 

                    LiftPID(-415);

    chassis.moveToPose(-24, 3, -80, 1000, {.maxSpeed = 70, .minSpeed = 70});
                    
pros::delay(450);

    chassis.swingToHeading(-26, lemlib::DriveSide::LEFT, 1000);

                    LiftPID(720);

pros::delay(650);

    chassis.moveToPose(-29, 12, -26, 1000, {.lead = 0});
chassis.waitUntilDone();

                    LiftPID(-285);
pros::delay(500);

    chassis.moveToPoint(-25, -27, 1000, {.forwards = false, .maxSpeed = 110, .earlyExitRange = 3});

                    LiftPID(-425);

    chassis.swingToHeading(-135, lemlib::DriveSide::RIGHT, 700);

    chassis.moveToPose(0, 0, -135, 1000, {.forwards = false, .minSpeed = 120});
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RedLeft(){
    chassis.setPose(0, 0, 45);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPose(-27, -29, -45, 1200, {.forwards = false, .lead = 0, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

    while (Mogo.extend() == false) {
        pros::delay(5);
    }
    
        request_new_state_intake(SCORE);
pros::delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(-11, -25.5, 500);   

    chassis.moveToPoint(-11, -25.75, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

pros::delay(250);

    chassis.moveToPoint(-17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

    while (DistanceIntakeTop.get() > 16) {
        pros::delay(5);
    }

    while (DistanceIntakeTop.get() < 80) {
        pros::delay(5);
    }

pros::delay(250);

   chassis.turnToHeading(-30, 500, {.minSpeed = 100});
chassis.waitUntilDone(); 

    chassis.moveToPose(-29, 3, -80, 2500, {.lead = 0.3, .maxSpeed = 90});
chassis.waitUntil(9);

      request_new_state_intake(SCORE);

              LiftPID(425);

                intakePiston.set_value(true);
chassis.waitUntilDone();

                intakePiston.set_value(false); 

                    LiftPID(-415);

    chassis.moveToPose(-24, 3, -80, 1000, {.maxSpeed = 70, .minSpeed = 70});
                    
pros::delay(450);

    chassis.swingToHeading(-26, lemlib::DriveSide::LEFT, 1000);

                    LiftPID(720);

pros::delay(650);

    chassis.moveToPose(-29, 12, -26, 1000, {.lead = 0});
chassis.waitUntilDone();

                    LiftPID(-285);
pros::delay(500);

    chassis.moveToPose(-50, -2, 90, 1000, {.forwards = false, .maxSpeed = 110});

                    LiftPID(-425);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Skills() {
    chassis.setPose(0,0,90);
    
            request_new_state_mogo(StateMogo::LOCATE);

    chassis.swingToHeading(135, lemlib::DriveSide::LEFT, 800, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});

    while (Mogo.extend() == false) {
        pros::delay(5);
    }
pros::delay(150);

        request_new_state_intake(SCORE);

    chassis.moveToPose(29, 0, 93, 800, {.minSpeed = 120, .earlyExitRange = 3});

    chassis.moveToPose(27, 12, 45, 750, {.lead = 0, .minSpeed = 120, .earlyExitRange = 2});

    chassis.moveToPose(15, 36, -45, 750, {.lead = 0, .minSpeed = 120, .earlyExitRange = 2});

        request_new_state_intake(STOP);

    chassis.moveToPose(-8, 36, 90, 900, {.lead = 0, .minSpeed = 120});

    chassis.turnToHeading(135, 650);

        request_new_state_intake(MECH);

    while (DistanceIntakeTop.get() < 80) {
        pros::delay(5);
    }

       request_new_state_intake(SCORE); 

    chassis.moveToPose(15, 12, 135, 850, {.minSpeed = 120});

    chassis.turnToHeading(-45, 850, {.minSpeed = 100});

            request_new_state_mogo(RELEASE);

    chassis.moveToPose(35, -7, -45, 850, {.forwards = false, .minSpeed = 120, .earlyExitRange = 3});

    chassis.moveToPoint(15, 36, 750, {.minSpeed = 120, .earlyExitRange = 2});

                        LiftPID(1150);

    chassis.moveToPose(32, 59, 90, 1000, {.lead = 0.5, .minSpeed = 80});

                        LiftPID(-1150);

        request_new_state_intake(MECH);

    chassis.moveToPoint(28, 59, 1000, {.minSpeed = 100});
\
    while (DistanceIntakeTop.get() > 16) {
        pros::delay(5);
    }

     while (DistanceIntakeTop.get() < 80) {
        pros::delay(5);
    }

    chassis.swingToHeading(-135, lemlib::DriveSide::LEFT, 850, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed = 60, .earlyExitRange = 10});

                        LiftPID(720);

    chassis.moveToPose(-3, -27, -135, 2000, {.minSpeed = 115});
chassis.waitUntilDone();

                        LiftPID(-285);

    chassis.swingToHeading(105, lemlib::DriveSide::RIGHT, 850, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 60});

            request_new_state_mogo(LOCATE);

    chassis.moveToPose(-49, 12, 90, 1500, {.forwards = false, .minSpeed = 100});

    chassis.turnToHeading(30, 500, {.minSpeed = 100});

        request_new_state_intake(SCORE);

    chassis.moveToPose(-54, 36, 30, 1250, {.minSpeed = 100});

    chassis.moveToPose(-78, 36, -90, 1000, {.lead = 0.1, .minSpeed = 100});

    chassis.moveToPose(-78, 0, 180, 1000, {.lead = 0.1, .minSpeed = 100});

    chassis.turnToHeading(-45, 500, {.minSpeed = 100});

    chassis.moveToPose(-90, 13, -45, 1000, {.minSpeed = 100});

    chassis.turnToHeading(30, 1000, {.minSpeed = 100});

            request_new_state_mogo(RELEASE);

    chassis.moveToPose(-94, -5, 30, 1000, {.forwards = false, .minSpeed = 100});

        request_new_state_intake(MECH);

    chassis.moveToPose(-89, 59, -90, 1500, {.minSpeed = 100});

    while (DistanceIntakeTop.get() > 16) {
        pros::delay(5);
    }

     while (DistanceIntakeTop.get() < 80) {
        pros::delay(5);
    }

                        LiftPID(1150);

    chassis.moveToPose(-96, 59, -90, 1000, {.minSpeed = 100});

                        LiftPID(-1150);

    chassis.moveToPose(-89, 59, -90, 1500, {.minSpeed = 100});

        request_new_state_intake(MECH);

    chassis.turnToHeading(45, 500, {.minSpeed = 100});
    
}
/** top ring of the double stack
    intakePiston.set_value(true);

    request_new_state_intake(State::LOAD);

    chassis.moveToPoint(0, 3, 1000);
    
    chassis.waitUntilDone();

    intakePiston.set_value(false);
    
    chassis.moveToPoint(0, -5, 1000, {.forwards = false});
 */
