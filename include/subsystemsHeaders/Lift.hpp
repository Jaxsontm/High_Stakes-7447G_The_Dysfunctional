#pragma once
#include "pros/abstract_motor.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/misc.h" // IWYU pragma: keep
#include "pros/motors.hpp"
#include "subsystemsHeaders/drive.hpp" // IWYU pragma: keep
#include "subsystemsHeaders/basket.hpp" // IWYU pragma: keep
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