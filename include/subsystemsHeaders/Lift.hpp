#pragma once
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "subsystemsHeaders/basket.hpp"
using namespace pros;
using namespace std;

// Yellow Ziptie
extern Motor lift;
//
void liftDriver();

void setLiftPos();

void liftLoad();

void liftScore();

pros::Task lift_load();
pros::Task lift_score();