#pragma once
#include "pros/distance.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"
using namespace pros;

// Blue Ziptie
extern Motor Intake;

extern Distance basketCheck;

extern Distance RingCounter;

extern Optical color;
//

void intakeControl();

enum class StateIntake {
  LOAD,
  CHECK,
  BRAKE,
};

void state_machine_intake(bool two_rings, bool color_sort);