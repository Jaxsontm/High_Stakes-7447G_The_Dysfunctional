#pragma once
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"
#include "subsystemsHeaders/drive.hpp"
using namespace pros;

//controllable objects
extern Motor basket;

extern adi::Button basketLimit;

// doing the controlling
enum class StateBasket {
	SCORE,
	RESET,
	STOP
};

void basketMove(StateBasket requestBasketState);

void basketControl();

void basketDriver();

void basketResetDriver();