#include "device.h"
#include "auton.h"
#include "main.h"
#include "pros/rtos.hpp"
#include "../include/robodash/api.h"



void RightAWP() { //finished

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

    chassis.turnToHeading(-160, 800);

    chassis.moveToPose(24, 18, 180, 1000, {.forwards = false, .lead = 0}, false);
pros::delay(250);

      request_new_state(State::SCORE);
pros::delay(1000);

    chassis.moveToPose(20, -44, 135, 2000);
}

void LeftAWP() { //finished
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

    chassis.moveToPose(0, 4, 0, 450, {.minSpeed = 127});
}

void BlueRight() {
    chassis.setPose(0, 0, 0);

        request_new_state_mogo(StateMogo::LOCATE);

    chassis.moveToPoint(0, -27, 1200, {.forwards = false, .maxSpeed = 70, .minSpeed = 25, .earlyExitRange = 1});

    chassis.turnToHeading(-90, 500);

    chassis.moveToPose(-19, -25, -90, 1000, {.lead = 0});
    
      request_new_state(State::IDLE);
      
    chassis.turnToHeading(180, 800);

    chassis.moveToPoint(-22, -40, 1000 );

      request_new_state(State::SCORE);
pros::delay(1250);

    chassis.moveToPose(16, -6, 90, 10000);

          intakePiston.set_value(true);

chassis.waitUntilDone();

      request_new_state(State::LOAD);

    chassis.moveToPose(10, -6, 90, 1000, {.forwards = false});

          intakePiston.set_value(false);
}


/** top ring of the double stack
    intakePiston.set_value(true);

    request_new_state(State::LOAD);

    chassis.moveToPoint(0, 3, 1000);
    
    chassis.waitUntilDone();

    intakePiston.set_value(false);

    chassis.moveToPoint(0, -5, 1000, {.forwards = false});
 */

rd::Selector selector({
   {"Right AWP", &RightAWP},
   {"Left AWP", &LeftAWP},
   {"Blue SUPER SCORE", &BlueRight},
   {"Red SUPER SCORE", &Score},
   {"Forwards", &Forwards}, 
   {"Skills", &Skills},
   
   
}); 

rd::Console console;
