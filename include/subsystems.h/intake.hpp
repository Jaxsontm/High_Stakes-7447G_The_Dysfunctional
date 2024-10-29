#pragma once
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/motors.hpp"
using namespace pros;

// Blue Ziptie
extern Motor Intake;

extern Distance DistanceIntakeTop;

extern Distance DistanceIntakeBottom;

extern adi::Pneumatics intakePiston;
//

enum StateIntake { 
    LOAD = 0, 
    IDLE = 1, 
    SCORE = 2, 
    UNLOAD = 3, 
    BRAKE = 4,
};

void state_machine_intake();
void request_new_state_intake(StateIntake new_state_lift);