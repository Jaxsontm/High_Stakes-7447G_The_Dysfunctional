#pragma once
#include "pros/abstract_motor.hpp" // IWYU pragma: keep
#include "pros/adi.hpp" // IWYU pragma: keep
#include "pros/distance.hpp"
#include "pros/misc.h" // IWYU pragma: keep
#include "pros/motors.hpp"
#include "subsystemsHeaders/basket.hpp" // IWYU pragma: keep
#include "subsystemsHeaders/drive.hpp" // IWYU pragma: keep
using namespace pros;

// Blue Ziptie
extern Motor Intake;

extern Distance basketCheck;

inline int intakeState = 0;
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

void startIntake();
void stopIntake();
void resetIntake();

/////
void intakeControl();

void spinFor(StateIntake request_number);

