#include "importants.h"
#include "auton.h"
#include "pros/abstract_motor.hpp"
#include "pros/rtos.hpp"



void RightAWP() { 

    chassis.setPose(0, 0, 0);

            request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPoint(0, -30, 1200, {.forwards = false, .maxSpeed = 70, .minSpeed = 25, .earlyExitRange = 1});

    chassis.turnToHeading(-90, 500);

    chassis.moveToPose(-24, -25, -90, 1000, {.lead = 0});
    
      request_new_state(State::IDLE);
pros::delay(2250);

    chassis.moveToPose(16, -6, 90, 2500, {.lead = 0.2, .maxSpeed = 80});

            request_new_state_mogo(StateMogo::RELEASE);
      request_new_state(State::BRAKE);

              intakePiston.set_value(true);
              
      request_new_state(State::LOAD);

    chassis.moveToPoint(18, -6, 1000);
chassis.waitUntilDone();

              intakePiston.set_value(false);
      request_new_state(BRAKE);


    chassis.moveToPoint(15, -6, 1000, {.minSpeed = 100});

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
    Lift.set_brake_mode(pros::MotorBrake::hold);
    Lift.move(127);
    pros::delay(625);
    Lift.brake();
}

void Score() {
    chassis.setPose(0,0,0);
}

void Forwards() { //finished
    chassis.setPose(0,0,0); //sets robot position to 0 on every axes

    chassis.moveToPose(0, 6, 0, 450, {.forwards = false, .minSpeed = 127}); //goes reverse 6 inches at max speed

    Intake.move(127); //spins the Intake to release the rubber band
pros::delay(1500);
    Lift.set_brake_mode(pros::MotorBrake::hold); //sets the brake mode to ho;ld the lift instead of flowing back down

    Intake.brake();//stops the intake from moving
    Lift.tare_position();
}

void BlueRight() {
    chassis.setPose(0, 0, 0);
}


/** top ring of the double stack
    intakePiston.set_value(true);

    request_new_state(State::LOAD);

    chassis.moveToPoint(0, 3, 1000);
    
    chassis.waitUntilDone();

    intakePiston.set_value(false);
    
    chassis.moveToPoint(0, -5, 1000, {.forwards = false});
 */
