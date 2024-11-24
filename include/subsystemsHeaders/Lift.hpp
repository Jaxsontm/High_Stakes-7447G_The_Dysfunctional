#pragma once
#include "pros/adi.hpp"
using namespace pros;

// Yellow Ziptie
extern adi::Pneumatics liftPTO;
//

void liftPTOToggle();

void lift_to_target_position(int targetPosition);

void liftDriver();

void liftScore();