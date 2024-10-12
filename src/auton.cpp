#include "config.hpp"
#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"
#include <string>
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

    chassis.turnToPoint(15, -25.5, 500);   

    chassis.moveToPoint(15, -25.5, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

delay(550);

    chassis.moveToPoint(17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

    while (DistanceIntakeTop.get() > 16) {
        delay(5);
    }

    while (DistanceIntakeTop.get() < 80) {
        request_new_state_intake(UNLOAD);
        delay(5);
    }

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

    chassis.moveToPose(27, 2.5, 80, 1000, {.maxSpeed = 70, .minSpeed = 70});
                    
delay(850);

    chassis.swingToHeading(32, lemlib::DriveSide::RIGHT, 1000);

                    LiftPID(720);

delay(650);

    chassis.moveToPose(28, 14.5, 32, 1000, {.lead = 0});
chassis.waitUntilDone();

    console.print(std::to_string(chassis.getPose().x));
    console.println(std::to_string(chassis.getPose().y));

                    LiftPID(-285);
/*delay(500);

    chassis.moveToPoint(25, -27, 1000, {.forwards = false, .maxSpeed = 110, .earlyExitRange = 3});

                    LiftPID(-425);

    chassis.swingToHeading(-55, lemlib::DriveSide::RIGHT, 700);

    chassis.moveToPose(44, -42, -55, 1000, {.forwards = false, .maxSpeed = 60});*/
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BlueRight() {
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

    chassis.moveToPose(-50, -2, 90, 1000, {.forwards = false, .maxSpeed = 110});

                    LiftPID(-425);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Skills() {
    chassis.setPose(0,0,135);
    
            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPose(-3, 4.5, 135, 500);

    while (Mogo.extend() == false) {
        delay(5);
    }
delay(150);

        request_new_state_intake(SCORE);

    chassis.moveToPose(17.5, -2.5, 93, 800, {.lead = 0, .minSpeed = 120, .earlyExitRange = 3});//

    chassis.moveToPose(29.5, 9.5, 45, 750, {.lead = 0, .minSpeed = 120, .earlyExitRange = 2});

    chassis.moveToPose(29.5, 56.5, 0, 1000, {.lead = 0, .minSpeed = 120});

    chassis.turnToHeading(-135, 500, {.minSpeed = 100});

    chassis.moveToPose(17.5, 32.5, -135, 750, {.lead = 0, .minSpeed = 120, .earlyExitRange = 2});

    chassis.moveToPose(-5.5, 33, 90, 900, {.lead = 0, .minSpeed = 120});

    chassis.turnToHeading(135, 650);

        request_new_state_intake(STOP);

    chassis.moveToPose(18, 9.5, 135, 850, {.minSpeed = 120});

    chassis.turnToHeading(-45, 850, {.minSpeed = 100});

            request_new_state_mogo(RELEASE);

    chassis.moveToPose(29.5, -2.5, -45, 850, {.forwards = false, .minSpeed = 120, .earlyExitRange = 3});

    chassis.moveToPose(-29.5, -6.5, 0, 1250, {.forwards = false, .lead = 0.6, .minSpeed = 120});
chassis.waitUntilDone();

        request_new_state_intake(SCORE);
delay(250);

    chassis.swingToHeading(100, lemlib::DriveSide::RIGHT, 850, {.minSpeed = 80});

        request_new_state_intake(BRAKE);

            request_new_state_mogo(LOCATE);

    chassis.moveToPose(49.5, 9.75, 90, 1000, {.forwards = false, .lead = 0, .minSpeed = 120});

    while (Mogo.extend() == false) {
        delay(5);
    }
delay(150);

        request_new_state_intake(SCORE);

    chassis.moveToPose(-53.5, 33, -70, 1000, {.lead = 0 ,.minSpeed = 100});

    chassis.moveToPose(-76.5, 33, -90, 1000, {.lead = 0, .minSpeed = 100});

    chassis.turnToHeading(180, 500, {.minSpeed = 120});

    chassis.moveToPose(-76.5, -2.5, 180, 1000, {.lead = 0, .minSpeed = 100});

    chassis.turnToHeading(-45, 500, {.minSpeed = 120});

    chassis.moveToPose(-88.5, 9.5, -45, 1000, {.lead = 0, .minSpeed = 100});

    chassis.swingToHeading(45, lemlib::DriveSide::LEFT, 850, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});

            request_new_state_mogo(RELEASE);

    chassis.moveToPose(-88.5, -2.5, 45, 1000, {.lead = 0, .minSpeed = 100});

        request_new_state_intake(MECH);

    chassis.moveToPose(-88.5, 56.5, 0, 1000, {.lead = 0, .minSpeed = 100});
    
chassis.waitUntil(10);
        request_new_state_intake(STOP);

    chassis.moveToPose(-53.5, 80.5, 45, 1000, {.lead = 0, .minSpeed = 100});

    chassis.turnToHeading(-135, 750, {.minSpeed = 100});

            request_new_state_mogo(LOCATE);

    chassis.moveToPose(-32.5, 99, -135, 1000, {.forwards = false, .lead = 0, .minSpeed = 100});

    while (Mogo.extend() == false) {
        delay(5);
    }
delay(150);

        request_new_state_intake(SCORE);

    chassis.moveToPose(-77, 80.5, 110, 1000, {.lead = 0, .minSpeed = 100});

chassis.waitUntil(10);
                    LiftPID(1150);

        request_new_state_intake(BRAKE);

    chassis.moveToPose(-91.5, 56.5, -90, 1250, {.minSpeed = 80});

                    LiftPID(-1150);
delay(250);

    chassis.moveToPose(-85.5, 56.5, 90, 1250, {.minSpeed = 80});

    chassis.turnToHeading(0, 500, {.minSpeed = 100});

        request_new_state_intake(SCORE);

    chassis.moveToPose(-76.5, 103.5, 0, 1000, {.lead = 0, .minSpeed = 100});

    chassis.turnToHeading(90, 500, {.minSpeed = 100});

    chassis.moveToPose(-88.5, 103.5, 0, 1000, {.lead = 0, .minSpeed = 100});

    chassis.turnToHeading(0, 500, {.minSpeed = 100});

    chassis.moveToPose(-88.5, 103.5, 0, 1000, {.lead = 0, .minSpeed = 100});

    chassis.swingToHeading(135, lemlib::DriveSide::LEFT, 850, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});

        request_new_state_intake(BRAKE);

            request_new_state_mogo(RELEASE);

    chassis.moveToPose(-88.5, 115.5, 135, 1000, {.lead = 0, .minSpeed = 120});

    chassis.moveToPose(-9, 115.5, -90, 1000, {.forwards = false, .lead = 0, .minSpeed = 120});

    chassis.moveToPose(29.5, 115.5, -135, 1000, {.forwards = false, .lead = 0.2, .minSpeed = 120});

    chassis.moveToPose(17.5, 80.5, 155, 1000, {.lead = 0.3, .minSpeed = 100});

    while (DistanceIntakeTop.get() > 16) {
        delay(5);
    }

    while (DistanceIntakeTop.get() < 80) {
        delay(5);
    }

                        LiftPID(1150);

    chassis.moveToPose(32.5, 56.5, 90, 1000, {.minSpeed = 100});

                        LiftPID(-1150);
delay(250);


}