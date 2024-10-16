#include "config.hpp"
#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/abstract_motor.hpp"
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

    chassis.turnToPoint(15.5, -25.5, 500);   

    chassis.moveToPoint(15.5, -25.5, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

pros::delay(550);

chassis.moveToPoint(17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

while (DistanceIntakeTop.get() > 30) {
  pros::delay(5);
    }

    request_new_state_intake(UNLOAD);

    pros::delay(750);

    chassis.turnToHeading(30, 500, {.minSpeed = 100});
    chassis.waitUntilDone(); 

    chassis.moveToPose(29.5, 2.5, 80, 2500, {.lead = 0.3, .maxSpeed = 90});
chassis.waitUntil(9);

      request_new_state_intake(SCORE);

              LiftPID(425);

                intakePiston.set_value(true);
chassis.waitUntilDone();

pros::delay(250);

intakePiston.set_value(false);

LiftPID(-415);

chassis.moveToPose(27, 0, 80, 1000, {.maxSpeed = 70, .minSpeed = 70});

pros::delay(850);

chassis.moveToPose(20, 0, 80, 1000, {.maxSpeed = 70, .minSpeed = 70});
chassis.waitUntilDone();

                        intakePiston.set_value(true);
    
    chassis.moveToPose(37, 0, 80, 1000, {.maxSpeed = 70, .minSpeed = 70});

    chassis.turnToHeading(-4,  850, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});

                    LiftPID(720);

                    pros::delay(650);

                    chassis.moveToPose(36, 16, -2, 1000, {.lead = 0.001});
                    chassis.waitUntilDone();

                    LiftPID(-285);
                    pros::delay(500);

                    chassis.moveToPoint(25, -27, 1000,
                                        {.forwards = false,
                                         .maxSpeed = 110,
                                         .earlyExitRange = 3});

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

                    chassis.moveToPoint(25, 3, 1000,
                                        {.forwards = false,
                                         .maxSpeed = 110,
                                         .earlyExitRange = 3});

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

                    chassis.moveToPoint(25, -27, 1000,
                                        {.forwards = false,
                                         .maxSpeed = 110,
                                         .earlyExitRange = 3});

                    LiftPID(-425);

    chassis.swingToHeading(135, lemlib::DriveSide::LEFT, 700);

    chassis.moveToPose(0, 0, 135, 1000, {.forwards = false, .minSpeed = 120});
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Forwards() { //finished
    chassis.setPose(0,0,0); 
Lift.set_brake_mode(MotorBrake::hold);

        request_new_state_intake(SCORE);

    chassis.moveToPose(0, 38, 0, 450, {.minSpeed = 127});

    
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RedLeft() { 
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

                    chassis.moveToPoint(-25, -27, 1000,
                                        {.forwards = false,
                                         .maxSpeed = 110,
                                         .earlyExitRange = 3});

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

                    chassis.moveToPoint(-25, -27, 1000,
                                        {.forwards = false,
                                         .maxSpeed = 110,
                                         .earlyExitRange = 3});

                    LiftPID(-425);

    chassis.swingToHeading(-135, lemlib::DriveSide::RIGHT, 700);

    chassis.moveToPose(0, 0, -135, 1000, {.forwards = false, .minSpeed = 120});
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LeftAWP(){
    chassis.setPose(0, 0, -90);

    chassis.moveToPose(14.75, 0, -90, 500, {.forwards = false, .minSpeed = 126});
chassis.waitUntilDone();


    chassis.turnToHeading(0, 500, {.maxSpeed = 60});
chassis.waitUntilDone();

    chassis.moveToPose(14.75, -30, 0, 515, {.forwards = false, .maxSpeed = 60});
chassis.waitUntilDone();

pros::delay(250);

request_new_state_intake(SCORE);
pros::delay(800);

chassis.moveToPose(14.75, 2, 0, 1000, {.minSpeed = 100});

request_new_state_intake(BRAKE);

chassis.turnToHeading(135, 500);

request_new_state_mogo(LOCATE);

chassis.moveToPose(-11.25, 34, 135, 1750, {.forwards = false});

chassis.turnToHeading(-90, 500);
chassis.waitUntilDone();

        request_new_state_intake(SCORE);

    chassis.moveToPose(-27, 32, -90, 1000, {.lead = 0, .minSpeed = 100});

    chassis.swingToHeading(0, lemlib::DriveSide::RIGHT, 850);

    chassis.moveToPose(-37, 48, 0, 1000, {.lead = 0});

    chassis.swingToHeading(30, lemlib::DriveSide::LEFT, 850);

    chassis.moveToPose(-21, 48, 30, 1000);

    chassis.moveToPose(8, 56, -135, 2500, {.forwards = false});

}   
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Skills() {
    chassis.setPose(0, 0, 0);

        request_new_state_intake(SCORE);
        pros::delay(750);

        request_new_state_mogo(LOCATE);

        request_new_state_intake(BRAKE);

    chassis.swingToHeading(-90, lemlib::DriveSide::LEFT, 850, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 90, .earlyExitRange = 10});   

    chassis.waitUntilDone();

    chassis.moveToPose(20, 15, -90, 1000, {.forwards = false, .maxSpeed = 80});
chassis.waitUntilDone();

pros::delay(350);

        request_new_state_intake(SCORE);

    chassis.turnToHeading(0, 500);
chassis.waitUntilDone();

    chassis.moveToPose(23.5, 38, 0, 1000, {.lead = 0});

    chassis.turnToHeading(90, 500);
chassis.waitUntilDone();

    chassis.moveToPose(48, 38, 90, 1000);

    chassis.turnToHeading(180, 500);
chassis.waitUntilDone();

    chassis.moveToPose(48, 22, 180, 1000, {.lead = 0.1});
chassis.waitUntilDone();

pros::delay(500);

    chassis.moveToPose(48, 4, 180, 1500, {.maxSpeed = 60});
chassis.waitUntilDone();

pros::delay(750);

    chassis.moveToPose(48, 16, 180, 1500, {.maxSpeed = 95});
chassis.waitUntilDone();

    chassis.turnToHeading(-45, 850, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
chassis.waitUntilDone();

pros::delay(750);

        request_new_state_mogo(RELEASE);

        request_new_state_intake(BRAKE);

    chassis.moveToPose(59, 1, -45, 1000, {.forwards = false, .lead = 0});
chassis.waitUntilDone();

    chassis.moveToPose(50, 16, -65, 1000);

    chassis.turnToHeading(90, 500);

        request_new_state_mogo(LOCATE);

    chassis.moveToPose(-20, 15, 90, 3000, {.forwards = false, .lead = 1, .maxSpeed = 80});
chassis.waitUntilDone();

pros::delay(350);

        request_new_state_intake(SCORE);

    chassis.turnToHeading(0, 500);
chassis.waitUntilDone();

    chassis.moveToPose(-23.5, 38, 0, 1000, {.lead = 0});

    chassis.turnToHeading(-90, 500);
chassis.waitUntilDone();

    chassis.moveToPose(-48, 38, -90, 1000);

    chassis.turnToHeading(180, 500);
chassis.waitUntilDone();

    chassis.moveToPose(-48, -22, 180, 1000, {.lead = 0.1});
chassis.waitUntilDone();

pros::delay(500);

    chassis.moveToPose(-48, 4, 180, 1500, {.maxSpeed = 60});
chassis.waitUntilDone();

pros::delay(750);

    chassis.moveToPose(-48, 16, 180, 1500, {.maxSpeed = 95});

    chassis.turnToHeading(45, 850, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
chassis.waitUntilDone();

pros::delay(750);

        request_new_state_mogo(RELEASE);

        //request_new_state_intake(BRAKE);

    chassis.moveToPose(-59, 1, 45, 1000, {.forwards = false, .lead = 0});

}