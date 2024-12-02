#pragma once
#include "pros/adi.hpp"
using namespace pros;

// Yellow Ziptie
extern adi::Pneumatics liftPTO;

extern adi::Pneumatics extender;
//

void liftPTOToggle();

void extenderToggle();

void lift_to_target_position(int targetPosition, int timeout = 500);

void liftLoad();

void liftAlliance();

void liftScore();

void liftDriver();