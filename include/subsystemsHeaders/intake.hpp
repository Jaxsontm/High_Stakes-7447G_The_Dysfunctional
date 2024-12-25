#pragma once
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/drive.hpp"
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

inline pros::Task* intake_machine;