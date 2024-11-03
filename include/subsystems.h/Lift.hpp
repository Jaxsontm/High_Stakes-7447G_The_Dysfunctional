#pragma once
#include "lemlib/pid.hpp"
#include "pros/motors.hpp"
using namespace pros;

// Yellow Ziptie
extern Motor Lift;
//

void LiftPID(double liftTarget);

extern lemlib::PID liftController();

enum StateLift {
    MOVE = 0,
    BOTTOM = 1,
    NEUTRAL = 3
};

//void state_machine_lift();


//void liftControl();