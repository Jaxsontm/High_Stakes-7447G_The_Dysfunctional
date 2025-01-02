#pragma once
#include "pros/abstract_motor.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/rtos.hpp" // IWYU pragma: keep
#include "subsystemsHeaders/drive.hpp" // IWYU pragma: keep
#include "subsystemsHeaders/intake.hpp" // IWYU pragma: keep
using namespace pros;

//controllable objects
extern Motor basket;

extern adi::Button basketLimit;

// doing the controlling
enum class StateBasket {
  SCORE,
  TOP,
  LOAD,
	RESET,
	STOP
};

void basketMove(StateBasket requestBasketState);

void basketControl();

void basketDriver();