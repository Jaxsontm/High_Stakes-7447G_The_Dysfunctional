#include "config.hpp"
#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"

//finished
void RightAWP() {
    chassis.setPose(-7.5, 0, 180);

    chassis.moveToPose(3, 28, -135, 1500, {.forwards = false, .maxSpeed = 95});
chassis.waitUntilDone();

        request_new_state_mogo(LOCATE);
pros::delay(750);

        request_new_state_intake(SCORE);
pros::delay(750);

    chassis.turnToPoint(14.5, 25.5, 500);
chassis.waitUntilDone();

    chassis.moveToPoint(14.5, 25.5, 1000);
chassis.waitUntilDone();

pros::delay(1250);

    chassis.swingToHeading(-125, lemlib::DriveSide::RIGHT, 850);

    chassis.moveToPose(-18, 3, -120, 1500, {.lead = 0, .maxSpeed = 60, .minSpeed = 0});
chassis.waitUntil(5);

            intakePiston.set_value(true);

        request_new_state_intake(SCORE);
chassis.waitUntilDone();

pros::delay(750);

    chassis.swingToHeading(-75, lemlib::DriveSide::LEFT, 850);

            intakePiston.set_value(false);

    chassis.moveToPoint(-18, 24, 1000);
chassis.waitUntilDone();

    request_new_state_mogo(RELEASE);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BlueRight() {
    chassis.setPose(-7.5, 0, 180);

    chassis.moveToPose(4, 29, -135, 1700, {.forwards = false, .maxSpeed = 95});
chassis.waitUntilDone();

        request_new_state_mogo(LOCATE);

pros::delay(750);

        request_new_state_intake(SCORE);

pros::delay(750);

    chassis.turnToHeading(90, 500, {.maxSpeed = 80});
chassis.waitUntilDone();

    chassis.moveToPose(13.5, 27, 90, 2000, {.lead = 0, .minSpeed = 90});
chassis.waitUntilDone();

pros::delay(650);

    chassis.moveToPose(10.5, 27, 90, 300, {.lead = 0, .minSpeed = 125});
chassis.waitUntilDone();    

    chassis.swingToHeading(10, lemlib::DriveSide::LEFT, 500);
chassis.waitUntilDone();

    chassis.moveToPose(22.5, 36, 0, 1500, {.lead = 0, .maxSpeed = 70, .minSpeed = 50});
chassis.waitUntilDone();

    chassis.moveToPose(22.5, 34, 0, 500, {.lead = 0, .maxSpeed = 70, .minSpeed = 50});
chassis.waitUntilDone();

pros::delay(75);

            intakePiston.set_value(true);

    chassis.turnToHeading(25,  500);
chassis.waitUntilDone();

            intakePiston.set_value(false);

pros::delay(750);

    chassis.moveToPose(25.5, 40, 25, 500, {.lead = 0, .maxSpeed = 70, .minSpeed = 50});
chassis.waitUntilDone();

    chassis.moveToPose(-3, 2, -90, 2500, {.forwards = false, .lead = 0.2});
chassis.waitUntilDone();

                intakePiston.set_value(true);

pros::delay(750);
        
    chassis.moveToPose(-15, 5, -90, 2000);
chassis.waitUntilDone();

    chassis.turnToHeading(-30, 500);
chassis.waitUntilDone();

                intakePiston.set_value(false);

    chassis.moveToPose(-23, 20, -30, 1000);
chassis.waitUntilDone();

        request_new_state_mogo(RELEASE);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//finished
void Forwards() { 
//1
    chassis.setPose(0,0,0); 

        request_new_state_intake(SCORE);
//2
    chassis.moveToPose(0, 38, 0, 450, {.minSpeed = 127});

        request_new_state_intake(BRAKE);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BlueLeft() {
    chassis.setPose(7.5, 0, 180);

    chassis.moveToPose(-4, 29, 135, 1500, {.forwards = false, .maxSpeed = 95});
chassis.waitUntilDone();

        request_new_state_mogo(LOCATE);
pros::delay(750);

        request_new_state_intake(SCORE);
pros::delay(750);

    chassis.turnToPoint(-14.5, 25.5, 500);
chassis.waitUntilDone();

    chassis.moveToPoint(-14.5, 25.5, 1000);
chassis.waitUntilDone();

pros::delay(1250);

    chassis.swingToHeading(125, lemlib::DriveSide::LEFT, 850);

    chassis.moveToPose(18, 3, 120, 1500, {.lead = -0.1, .maxSpeed = 60, .minSpeed = 0});
chassis.waitUntil(5);

            intakePiston.set_value(true);

        request_new_state_intake(SCORE);
chassis.waitUntilDone();

pros::delay(750);

    chassis.swingToHeading(55, lemlib::DriveSide::RIGHT, 850);

            intakePiston.set_value(false);

    chassis.moveToPoint(18, 27, 1000);
chassis.waitUntilDone();

    request_new_state_mogo(RELEASE);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LeftAWP(){
    chassis.setPose(7.5, 0, 180);

    chassis.moveToPose(-4, 29, 135, 1700, {.forwards = false, .maxSpeed = 95});
chassis.waitUntilDone();

        request_new_state_mogo(LOCATE);

pros::delay(750);

        request_new_state_intake(SCORE);

pros::delay(750);

    chassis.turnToHeading(-90, 500, {.maxSpeed = 80});
chassis.waitUntilDone();

    chassis.moveToPose(-13.5, 27, -90,2000, {.lead = 0, .minSpeed = 90});
chassis.waitUntilDone();

pros::delay(650);

    chassis.moveToPose(-10.5, 27, -90, 300, {.lead = 0, .minSpeed = 125});
chassis.waitUntilDone();    

    chassis.swingToHeading(-10, lemlib::DriveSide::RIGHT, 500);
chassis.waitUntilDone();

    chassis.moveToPose(-22.5, 36, -0, 1500, {.lead = 0, .maxSpeed = 70, .minSpeed = 50});
chassis.waitUntilDone();

    chassis.moveToPose(-22.5, 34, -0, 500, {.lead = 0, .maxSpeed = 70, .minSpeed = 50});
chassis.waitUntilDone();

pros::delay(75);

            intakePiston.set_value(true);

    chassis.turnToHeading(-25,  500);
chassis.waitUntilDone();

            intakePiston.set_value(false);

pros::delay(750);

    chassis.moveToPose(-25.5, 40, -25, 500, {.lead = 0, .maxSpeed = 70, .minSpeed = 50});
chassis.waitUntilDone();

    chassis.moveToPose(3, 2, 90, 2500, {.forwards = false, .lead = 0.2});
chassis.waitUntilDone();

                intakePiston.set_value(true);

pros::delay(750);
        
    chassis.moveToPose(15, 5, 90, 2000);
chassis.waitUntilDone();

    chassis.turnToHeading(30, 500);
chassis.waitUntilDone();

                intakePiston.set_value(false);

    chassis.moveToPose(23, 20, 30, 1000);
chassis.waitUntilDone();

        request_new_state_mogo(RELEASE);
}   
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Skills() {
//1
    chassis.setPose(0, 0.5, 0);

        request_new_state_intake(SCORE);
        pros::delay(550);

        request_new_state_mogo(LOCATE);

        request_new_state_intake(BRAKE);
//2
    chassis.swingToHeading(-90, lemlib::DriveSide::LEFT, 850, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed = 80, .earlyExitRange = 10});   

    chassis.waitUntilDone();

    chassis.moveToPose(26, 13.5, -90, 1000, {.forwards = false, .maxSpeed = 80});
chassis.waitUntilDone();

pros::delay(500);

        request_new_state_intake(SCORE);

    chassis.turnToHeading(0, 500);
chassis.waitUntilDone();
//3
    chassis.moveToPose(23.5, 38, 0, 1000, {.lead = 0});
chassis.waitUntilDone();

pros::delay(500);

    chassis.turnToHeading(90, 500);
chassis.waitUntilDone();
//4
    chassis.moveToPose(44, 39, 90, 1000);
chassis.waitUntilDone();

pros::delay(500);

    chassis.turnToHeading(180, 500);
chassis.waitUntilDone();
//5
    chassis.moveToPose(48, 22, 180, 1000, {.lead = 0.1});
chassis.waitUntilDone();

pros::delay(500);
//6
    chassis.moveToPose(48, 4, 180, 1500, {.maxSpeed = 60});
chassis.waitUntilDone();

pros::delay(750);
//7
    chassis.moveToPose(48, 16, 180, 1500, {.maxSpeed = 95});
chassis.waitUntilDone();

    chassis.turnToHeading(-45, 850, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
chassis.waitUntilDone();

pros::delay(750);

        request_new_state_mogo(RELEASE);

        request_new_state_intake(BRAKE);

    chassis.moveToPose(59, 1, -45, 1000, {.forwards = false, .lead = 0});
chassis.waitUntilDone();
//8
    chassis.moveToPose(50, 16, -65, 1000);

    chassis.turnToHeading(90, 500);

        request_new_state_mogo(LOCATE);

    chassis.moveToPose(-26, 8, 90, 3000, {.forwards = false, .lead = 0.7, .maxSpeed = 80});
chassis.waitUntilDone();

pros::delay(350);

        request_new_state_intake(SCORE);

    chassis.turnToHeading(0, 500);
chassis.waitUntilDone();
//9
    chassis.moveToPose(-23.5, 30, 0, 1000, {.lead = 0});
chassis.waitUntilDone();

pros::delay(500);

    chassis.turnToHeading(-90, 500);
chassis.waitUntilDone();
//10
    chassis.moveToPose(-49, 32, -90, 1000);
chassis.waitUntilDone();

pros::delay(500);

    chassis.turnToHeading(180, 500);
chassis.waitUntilDone();
//11
    chassis.moveToPose(-49, 10, 180, 1000, {.lead = 0.1, .maxSpeed = 80});
chassis.waitUntilDone();

pros::delay(500);
//12
    chassis.moveToPose(-49, -1, 180, 1500, {.maxSpeed = 60});
chassis.waitUntilDone();

pros::delay(750);
//13
    chassis.moveToPose(-49, 12, 180, 1500, {.maxSpeed = 95});

    chassis.turnToHeading(45, 850, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
chassis.waitUntilDone();

pros::delay(750);

        request_new_state_mogo(RELEASE);

        request_new_state_intake(BRAKE);

    chassis.moveToPose(-64, -14, 45, 1000, {.forwards = false, .lead = 0.3});
//14
    chassis.moveToPose(-29, 87, 10, 4000, {.lead = 0.2, .minSpeed = 127});
chassis.waitUntilDone();

    chassis.turnToHeading(-90, 500);
chassis.waitUntilDone();

    chassis.swingToHeading(95, lemlib::DriveSide::RIGHT, 850, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
chassis.waitUntilDone();   
//15
    chassis.moveToPose(-68, 130, 130, 2500, {.forwards = false});

    chassis.moveToPose(-56, 110, 130, 1000);
}