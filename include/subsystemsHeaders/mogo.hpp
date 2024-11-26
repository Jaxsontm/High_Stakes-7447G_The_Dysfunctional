#pragma once
#include "pros/adi.hpp"
#include "pros/distance.hpp"
using namespace pros;

// Red Ziptie
extern Distance DistanceMogo;

extern adi::Pneumatics Mogo;
//

void mogoToggle();

enum class StateMogo { 
  LOCATE, 
  GRAB, 
  RELEASE 
};

void request_new_state_mogo(StateMogo new_state);
void state_machine_mogo();