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
    ALLIANCE = 2,
    NEUTRAL = 3
};

void state_machine_lift(int position);

static Task state_machine_task_lift(state_machine_lift);

void liftControl();