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

extern IMU rotFinder;

extern adi::Button liftLimit;
//
enum class liftPos {
  LOAD,
  SCORE,
  RESET,
  STOP
};

void setLiftPos(liftPos requestedPos);

void liftMachine();

void liftDriver();