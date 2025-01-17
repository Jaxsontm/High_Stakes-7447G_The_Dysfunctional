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

extern Rotation rotFinder;

extern adi::Button liftLimit;

inline int liftPosition = 0;
//
enum class liftPos {
  LOAD,
  autoLOAD,
  SCORE,
  RESET,
  STOP
};

void setLiftPos(liftPos requestedPos);

void liftMachine();

void liftDriver();