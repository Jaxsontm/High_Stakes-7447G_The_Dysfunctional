#pragma once
#include "pros/distance.hpp"
#include "pros/motors.hpp"
using namespace pros;

// Blue Ziptie
extern Motor Intake;

extern Distance basketCheck;
//

void intakeControl();

enum class StateIntake {
	ONE,
	TWO,
	CHECK,
	BRAKE,
};

void how_many_rings(StateIntake request_number);

void state_machine_intake();