#pragma once
#include "pros/adi.hpp"
#include "pros/motors.hpp"
using namespace pros;

// Yellow Ziptie
extern Motor lift;

extern adi::Pneumatics grabber;
//
void liftDriver();

void setLiftPos();

void grabberToggle();