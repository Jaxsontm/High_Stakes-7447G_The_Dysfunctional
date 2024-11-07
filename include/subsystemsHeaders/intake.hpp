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

extern void intakePistonToggle();

enum StateIntake { 
    LOAD = 0,
    CHECK = 1, 
    BRAKE = 2
};

extern void state_machine_intake(bool two_rings);
