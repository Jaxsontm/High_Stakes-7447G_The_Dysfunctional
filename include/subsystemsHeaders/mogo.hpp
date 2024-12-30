#pragma once
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/misc.h"
#include "subsystemsHeaders/drive.hpp"
using namespace pros;

// controllables
extern Distance DistanceMogo;

extern adi::Pneumatics Mogo;

extern adi::Pneumatics doinker;

//macros
void mogoToggle();

void doinkerToggle();

enum class StateMogo { 
	LOCATE,
	GRAB,
	RELEASE
};

/////
void request_new_state_mogo(StateMogo new_state);

void state_machine_mogo();

void text();