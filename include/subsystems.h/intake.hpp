#pragma once
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/motors.hpp"  
using namespace pros;

// Blue Ziptie
extern Motor Intake;

extern Distance BasketCheck;

extern Distance RingCounter;

extern adi::Pneumatics intakePiston;
//

void intakeControl();

void intakePistonToggle();

enum StateIntake { 
    LOAD = 0,
    CHECK = 1, 
    BRAKE = 2
};

void state_machine_intake(StateIntake new_state_lift, bool two_rings);

static Task state_machine_task_intake(state_machine_intake);