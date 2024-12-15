#pragma once
#include "pros/distance.hpp"
#include "pros/motors.hpp"
using namespace pros;

// Blue Ziptie
extern Motor Intake;

extern Distance basketCheck;
/////

enum class StateIntake {
	ONE,
	TWO,
	CHECK,
	REV,
	FWD,
	BRAKE,
};

void state_machine_intake();

/////
void intakeControl();

void spinFor(StateIntake request_number);