#include "config.hpp"
#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/rtos.hpp"

//finished
void RightAWP() {
//1 
    chassis.setPose(-38, 0, 45);
    
        request_new_state_mogo(StateMogo::LOCATE);
//2
    chassis.moveToPose(33, -29, 45, 1200, {.forwards = false, .lead = 0, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

    while (Mogo.extend() == false) {
      pros::delay(5);
    }
    
        request_new_state_intake(SCORE);
pros::delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(15.5, -25.5, 500);   
//3
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
//4
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
//5
    chassis.moveToPose(36, 16, -2, 1000, {.lead = 0.001});
chassis.waitUntilDone();

            LiftPID(-285);
pros::delay(500);
//6
    chassis.moveToPoint(25, -27, 1000, {.forwards = false, .maxSpeed = 110, .earlyExitRange = 3});

            LiftPID(-425);

        request_new_state_intake(SCORE);

    chassis.swingToHeading(-55, lemlib::DriveSide::RIGHT, 700);

                intakePiston.set_value(false);

    chassis.moveToPose(44, -42, -55, 1000, {.forwards = false, .maxSpeed = 60});
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BlueRight() {
    chassis.setPose(-38, 0, 45);

    
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

    chassis.moveToPose(0, 0, -55, 1000, {.forwards = false, .maxSpeed = 60});
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RedRight(){
    chassis.setPose(-38, 0, 45);

    
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
//finished
void Forwards() { 
//1
    chassis.setPose(0,0,0); 
    Lift.set_brake_mode(MotorBrake::hold);

        request_new_state_intake(SCORE);
//2
    chassis.moveToPose(0, 38, 0, 450, {.minSpeed = 127});
chassis.waitUntilDone();

delay(250);

        request_new_state_intake(BRAKE);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RedLeft() { 
    chassis.setPose(0, 0, 45);
    
            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPose(-27, -29, 45, 1200, {.forwards = false, .lead = 0, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

    while (Mogo.extend() == false) {
      pros::delay(5);
    }
    
        request_new_state_intake(SCORE);
        pros::delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(-15.5, -25.5, 500);   

    chassis.moveToPoint(-15.5, -25.5, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

pros::delay(550);

chassis.moveToPoint(-17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

while (DistanceIntakeTop.get() > 30) {
  pros::delay(5);
    }

    request_new_state_intake(UNLOAD);

    pros::delay(750);

    chassis.turnToHeading(-30, 500, {.minSpeed = 100});
    chassis.waitUntilDone(); 

    chassis.moveToPose(-29.5, 2.5, -80, 2500, {.lead = 0.3, .maxSpeed = 90});
chassis.waitUntil(9);

      request_new_state_intake(SCORE);

              LiftPID(425);

                intakePiston.set_value(true);
chassis.waitUntilDone();

pros::delay(250);

intakePiston.set_value(false);

LiftPID(-415);

chassis.moveToPose(-27, 0, -80, 1000, {.maxSpeed = 70, .minSpeed = 70});

pros::delay(850);

chassis.moveToPose(-20, 0, -80, 1000, {.maxSpeed = 70, .minSpeed = 70});
chassis.waitUntilDone();

                        intakePiston.set_value(true);
    
    chassis.moveToPose(-37, 0, -80, 1000, {.maxSpeed = 70, .minSpeed = 70});

    chassis.turnToHeading(4,  850, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});

                    LiftPID(720);

pros::delay(650);

    chassis.moveToPose(-36, 16, 2, 1000, {.lead = 0.001});
chassis.waitUntilDone();

                    LiftPID(-285);
pros::delay(500);

    chassis.moveToPoint(-25, -27, 1000,{.forwards = false, .maxSpeed = 110, .earlyExitRange = 3});

                    LiftPID(-425);

        request_new_state_intake(SCORE);

    chassis.swingToHeading(55, lemlib::DriveSide::RIGHT, 700);

                            intakePiston.set_value(false);

    chassis.moveToPose(0, 0, 55, 1000, {.forwards = false, .maxSpeed = 60});
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BlueLeft() {
    chassis.setPose(0, 0, 45);
    
            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPose(-27, -29, 45, 1200, {.forwards = false, .lead = 0, .maxSpeed = 55, .minSpeed = 25});
chassis.waitUntilDone();

    while (Mogo.extend() == false) {
      pros::delay(5);
    }
    
        request_new_state_intake(SCORE);
        pros::delay(950);

        request_new_state_intake(MECH);

    chassis.turnToPoint(-15.5, -25.5, 500);   

    chassis.moveToPoint(-15.5, -25.5, 1000, {.minSpeed = 120});
chassis.waitUntilDone();

pros::delay(550);

chassis.moveToPoint(-17, -25.75, 1000, {.forwards = false, .maxSpeed = 80});

while (DistanceIntakeTop.get() > 30) {
  pros::delay(5);
    }

    request_new_state_intake(UNLOAD);

    pros::delay(750);

    chassis.turnToHeading(-30, 500, {.minSpeed = 100});
    chassis.waitUntilDone(); 

    chassis.moveToPose(-29.5, 2.5, -80, 2500, {.lead = 0.3, .maxSpeed = 90});
chassis.waitUntil(9);

      request_new_state_intake(SCORE);

              LiftPID(425);

                intakePiston.set_value(true);
chassis.waitUntilDone();

pros::delay(250);

intakePiston.set_value(false);

LiftPID(-415);

chassis.moveToPose(-27, 0, -80, 1000, {.maxSpeed = 70, .minSpeed = 70});

pros::delay(850);

chassis.moveToPose(-20, 0, -80, 1000, {.maxSpeed = 70, .minSpeed = 70});
chassis.waitUntilDone();

                        intakePiston.set_value(true);
    
    chassis.moveToPose(-37, 0, -80, 1000, {.maxSpeed = 70, .minSpeed = 70});

    chassis.turnToHeading(4,  850, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});

                    LiftPID(720);

pros::delay(650);

    chassis.moveToPose(-36, 16, 2, 1000, {.lead = 0.001});
chassis.waitUntilDone();

                    LiftPID(-285);
pros::delay(500);

    chassis.moveToPoint(-25, -27, 1000,{.forwards = false, .maxSpeed = 110, .earlyExitRange = 3});

                    LiftPID(-425);

        request_new_state_intake(SCORE);

    chassis.swingToHeading(55, lemlib::DriveSide::RIGHT, 700);

                            intakePiston.set_value(false);

    chassis.moveToPose(-44, -42, 55, 1000, {.forwards = false, .maxSpeed = 60});
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LeftAWP(){
//1
     chassis.setPose(0, 0, -90);
//2
    chassis.moveToPose(14.35, 0, -90, 500, {.forwards = false, .minSpeed = 126});
chassis.waitUntilDone();
    chassis.turnToHeading(0, 500, {.maxSpeed = 60});
chassis.waitUntilDone();
//3
    chassis.moveToPose(14.75, -30, 0, 500, {.forwards = false, .maxSpeed = 60});
chassis.waitUntilDone();

delay(500);

        request_new_state_intake(SCORE);
delay(1150);

        request_new_state_intake(BRAKE);
chassis.moveToPose(14.75, 2, 0, 1000, {.minSpeed = 100});

        request_new_state_mogo(LOCATE);

    chassis.turnToHeading(130, 500);
chassis.waitUntilDone();
//4
    chassis.moveToPose(-10, 31.5, 133, 1900, {.forwards = false, .lead = 0.45});
chassis.waitUntilDone();

    chassis.turnToHeading(-90, 800, {.maxSpeed = 80});
chassis.waitUntilDone();

        request_new_state_intake(SCORE);
//5
    chassis.moveToPose(-21, 31, -88, 2000, {.lead = 0.2, .minSpeed = 80});
chassis.waitUntilDone();

pros::delay(650);

    chassis.moveToPose(-19, 31, -88, 500);

    chassis.swingToHeading(-2, lemlib::DriveSide::RIGHT, 900);
chassis.waitUntilDone();
//6
    chassis.moveToPose(-31, 46, -10, 500, {.lead = 0});
chassis.waitUntilDone();

pros::delay(250);

    chassis.turnToHeading(-30, 500);
chassis.waitUntilDone();
//7
    chassis.swingToHeading(75, lemlib::DriveSide::LEFT, 500);

            LiftPID(720);

    chassis.moveToPose(42, 46, 75, 1200);

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

    chassis.moveToPose(-26, 8, 90, 3000, {.forwards = false, .lead = 0.7, .maxSpeed = 80});
chassis.waitUntilDone();

pros::delay(350);

        request_new_state_intake(SCORE);

    chassis.turnToHeading(0, 500);
chassis.waitUntilDone();

    chassis.moveToPose(-23.5, 30, 0, 1000, {.lead = 0});

    chassis.turnToHeading(-90, 500);
chassis.waitUntilDone();

    chassis.moveToPose(-48, 31, -90, 1000);
chassis.waitUntilDone();

pros::delay(350);

    chassis.turnToHeading(180, 500);
chassis.waitUntilDone();

    chassis.moveToPose(-48, 12, 180, 1000, {.lead = 0.1, .maxSpeed = 80});
chassis.waitUntilDone();

pros::delay(2000);

    chassis.moveToPose(-48, -2, 180, 1500, {.maxSpeed = 60});
chassis.waitUntilDone();

pros::delay(750);

    chassis.moveToPose(-48, 12, 180, 1500, {.maxSpeed = 95});

    chassis.turnToHeading(45, 850, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
chassis.waitUntilDone();

pros::delay(750);

        request_new_state_mogo(RELEASE);

        request_new_state_intake(BRAKE);

    chassis.moveToPose(-64, -12, 45, 1000, {.forwards = false, .lead = 0});

    chassis.moveToPose(-10, 92, 10, 4000, {.lead = 0, .minSpeed = 127});
chassis.waitUntil(10);


            LiftPID(640);
chassis.waitUntilDone();

    chassis.swingToHeading(-80, lemlib::DriveSide::LEFT, 850);

            LiftPID(-640);

    chassis.moveToPose(-72, 92, -80, 1250, {.lead = 0.1});

    chassis.swingToHeading(135, lemlib::DriveSide::LEFT, 850);

}