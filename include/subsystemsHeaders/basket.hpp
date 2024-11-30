#pragma once
#include "pros/adi.hpp"
#include "pros/motors.hpp"
using namespace pros;

//controllable objects
extern Motor basket;

extern adi::Button basketLimit;

//doing the controlling
void basketScore(int timeout);

void basketReset();

void basketDriver();

void basketResetDriver();