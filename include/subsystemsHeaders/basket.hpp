#pragma once
#include "lemlib/pid.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
using namespace pros;

extern Motor basket;

extern adi::Button basketLimit;

void basketPID(double basketTarget);

extern lemlib::PID basketControl();

void basketScore();

void basketSort();

void basketDriver();
