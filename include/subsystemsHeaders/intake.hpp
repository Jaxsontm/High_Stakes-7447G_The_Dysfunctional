#pragma once
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/motors.hpp" 
#include "pros/optical.hpp" 
using namespace pros;

// Blue Ziptie
extern Motor Intake;

extern Distance BasketCheck;

extern Distance RingCounter;

extern adi::Pneumatics intakePiston;

extern Optical color;
//

void intakeControl();

extern void intakePistonToggle();

enum StateIntake { 
    LOAD = 0,
    CHECK = 1, 
    BRAKE = 2,
    COLOR = 3
};

extern void state_machine_intake(bool two_rings, bool color_sort);
