#pragma once
#include "pros/adi.hpp"
#include "pros/motors.hpp"
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

void basketScore(int timeout);

void basketReset();

pros::Task basketScoreTask();
void basketDriver();

void basketResetDriver();