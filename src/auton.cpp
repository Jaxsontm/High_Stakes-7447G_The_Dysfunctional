#include "config.hpp"
#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"
using namespace pros;

void RightAWP() { //finished
    chassis.setPose(0, 0, -45);
    


            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPose(27, -29, -45, 1200, {.forwards = false, .lead = 0, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

    while (Mogo.extend() == false) {
        delay(5);
    }
    
        request_new_state_intake(SCORE);
delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(15.5, -25.5, 500);   

    chassis.moveToPoint(15.5, -25.5, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

delay(550);

    chassis.moveToPoint(17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

    while (DistanceIntakeTop.get() > 30) {
        delay(5);
    }

    request_new_state_intake(UNLOAD);

delay(750);

   chassis.turnToHeading(30, 500, {.minSpeed = 100});
chassis.waitUntilDone(); 

    chassis.moveToPose(29.5, 2.5, 80, 2500, {.lead = 0.3, .maxSpeed = 90});
chassis.waitUntil(9);

      request_new_state_intake(SCORE);

              LiftPID(425);

                intakePiston.set_value(true);
chassis.waitUntilDone();

delay(250);

                intakePiston.set_value(false); 

                    LiftPID(-415);

    chassis.moveToPose(27, 0, 80, 1000, {.maxSpeed = 70, .minSpeed = 70});
                    
delay(850);

    chassis.moveToPose(20, 0, 80, 1000, {.maxSpeed = 70, .minSpeed = 70});
chassis.waitUntilDone();

                        intakePiston.set_value(true);
    
    chassis.moveToPose(37, 0, 80, 1000, {.maxSpeed = 70, .minSpeed = 70});

    chassis.turnToHeading(-4,  850, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});

                    LiftPID(720);

delay(650);

    chassis.moveToPose(36, 16, -2, 1000, {.lead = 0.001});
chassis.waitUntilDone();

                    LiftPID(-285);
delay(500);

    chassis.moveToPoint(25, -27, 1000, {.forwards = false, .maxSpeed = 110, .earlyExitRange = 3});

                    LiftPID(-425);

        request_new_state_intake(SCORE);

    chassis.swingToHeading(-55, lemlib::DriveSide::RIGHT, 700);

                            intakePiston.set_value(false);

    chassis.moveToPose(44, -42, -55, 1000, {.forwards = false, .maxSpeed = 60});
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BlueRight() {
    chassis.setPose(0, 0, -90);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPose(27, -29, -45, 1200, {.forwards = false, .lead = 0, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

    while (Mogo.extend() == false) {
        delay(5);
    }
    
        request_new_state_intake(SCORE);
delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(11, -25.5, 500);   

    chassis.moveToPoint(11, -25.75, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

delay(250);

    chassis.moveToPoint(17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

    while (DistanceIntakeTop.get() > 16) {
        delay(5);
    }

    while (DistanceIntakeTop.get() < 80) {
        delay(5);
    }

delay(250);

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
                    
delay(450);

    chassis.swingToHeading(26, lemlib::DriveSide::RIGHT, 1000);

                    LiftPID(720);

delay(650);

    chassis.moveToPose(29, 12, 26, 1000, {.lead = 0});
chassis.waitUntilDone();

                    LiftPID(-285);
delay(500);

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
        delay(5);
    }
    
        request_new_state_intake(SCORE);
delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(11, -25.5, 500);   

    chassis.moveToPoint(11, -25.75, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

delay(250);

    chassis.moveToPoint(17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

    while (DistanceIntakeTop.get() > 16) {
        delay(5);
    }

    while (DistanceIntakeTop.get() < 80) {
        delay(5);
    }

delay(250);

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
                    
delay(450);

    chassis.swingToHeading(26, lemlib::DriveSide::RIGHT, 1000);

                    LiftPID(720);

delay(650);

    chassis.moveToPose(29, 12, 26, 1000, {.lead = 0});
chassis.waitUntilDone();

                    LiftPID(-285);
delay(500);

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
        delay(5);
    }
    
        request_new_state_intake(SCORE);
delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(-11, -25.5, 500);   

    chassis.moveToPoint(-11, -25.75, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

delay(250);

    chassis.moveToPoint(-17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

    while (DistanceIntakeTop.get() > 16) {
        delay(5);
    }

    while (DistanceIntakeTop.get() < 80) {
        delay(5);
    }

delay(250);

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
                    
delay(450);

    chassis.swingToHeading(-26, lemlib::DriveSide::LEFT, 1000);

                    LiftPID(720);

delay(650);

    chassis.moveToPose(-29, 12, -26, 1000, {.lead = 0});
chassis.waitUntilDone();

                    LiftPID(-285);
delay(500);

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
        delay(5);
    }
    
        request_new_state_intake(SCORE);
delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(-11, -25.5, 500);   

    chassis.moveToPoint(-11, -25.75, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

delay(250);

    chassis.moveToPoint(-17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

    while (DistanceIntakeTop.get() > 16) {
        delay(5);
    }

    while (DistanceIntakeTop.get() < 80) {
        delay(5);
    }

delay(250);

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
                    
delay(450);

    chassis.swingToHeading(-26, lemlib::DriveSide::LEFT, 1000);

                    LiftPID(720);

delay(650);

    chassis.moveToPose(-29, 12, -26, 1000, {.lead = 0});
chassis.waitUntilDone();

                    LiftPID(-285);
delay(500);

    chassis.moveToPoint(-25, -27, 1000, {.forwards = false, .maxSpeed = 110, .earlyExitRange = 3});

                    LiftPID(-425);

    chassis.swingToHeading(-135, lemlib::DriveSide::RIGHT, 700);

    chassis.moveToPose(0, 0, -135, 1000, {.forwards = false, .minSpeed = 120});
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RedLeft(){
    chassis.setPose(0, 0, -90);

    chassis.moveToPose(14.75, 0, -90, 500, {.forwards = false, .minSpeed = 126});
chassis.waitUntilDone();


    chassis.turnToHeading(0, 500, {.maxSpeed = 60});
chassis.waitUntilDone();

    chassis.moveToPose(14.75, -30, 0, 500, {.forwards = false, .maxSpeed = 60});
chassis.waitUntilDone();

delay(250);

        request_new_state_intake(SCORE);
delay(350);

        request_new_state_intake(BRAKE);

    chassis.swingToHeading(-55, lemlib::DriveSide::LEFT, 650);

    chassis.moveToPose(-33, 35.5, 0, 2500);

        request_new_state_intake(STOP);
delay(250);

    chassis.swingToHeading(-90, lemlib::DriveSide::LEFT, 650, {.maxSpeed = 70});

        request_new_state_mogo(LOCATE);

    chassis.moveToPose(-10, 35.5, -90, 750, {.forwards = false, .lead = 0, .maxSpeed = 65});
chassis.waitUntilDone();

        request_new_state_intake(SCORE);

    chassis.turnToHeading(-35, 500);

    chassis.moveToPose(-28, 55, -35, 1000);

    chassis.swingToHeading(-55, lemlib::DriveSide::RIGHT, 850);


}   
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Skills() {
    chassis.setPose(0,-62,90);

        /*request_new_state_intake(SCORE);
delay(350);

        request_new_state_mogo(LOCATE);

        request_new_state_intake(BRAKE);

    chassis.swingToHeading(-15, lemlib::DriveSide::LEFT, 850, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 90, .earlyExitRange = 10});   

    chassis.moveToPose(-20, -47, 0, 1000, {.forwards = false, .minSpeed = 80});

        request_new_state_intake(SCORE);

    chassis.moveToPose(-24, -24, 115, 1000, {.lead = 0.1, .minSpeed = 110});

    chassis.moveToPose(-47, 24, 120, 1000, {.lead = 0, .minSpeed = 110});

    chassis.moveToPose(-59, 0, -120, 1000, {.lead = 0, .minSpeed = 110});

    chassis.moveToPose(-47, -24, -60, 1000, {.lead = 0, .minSpeed = 110});

    chassis.moveToPose(-47, -59, -90, 1000, {.lead = 0, .minSpeed = 110});

    chassis.swingToHeading(45, lemlib::DriveSide::LEFT, 850, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed = 90, .earlyExitRange = 5});

        request_new_state_mogo(RELEASE);

    chassis.moveToPose(-59, -59, 45, 500, {.forwards = false});*/

request_new_state_intake(MECH);
}