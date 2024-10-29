#pragma once
#include "pros/motors.hpp"
using namespace pros;

// Yellow Ziptie
extern Motor Lift;
//

enum StateLift {
    LOWER = 0,
    ALLIANCE = 1,
    WALL = 2,
    STOP = 3
};

void state_machine_lift();
void request_new_state_lift(StateLift new_state);