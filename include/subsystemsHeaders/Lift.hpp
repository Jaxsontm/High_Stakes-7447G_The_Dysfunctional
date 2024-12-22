#pragma once
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp"
#include "subsystemsHeaders/drive.hpp"
using namespace pros;
using namespace std;

// Yellow Ziptie
extern Motor lift;

extern adi::Pneumatics grabber;
//
void liftDriver();

void setLiftPos();

void grabberToggle();