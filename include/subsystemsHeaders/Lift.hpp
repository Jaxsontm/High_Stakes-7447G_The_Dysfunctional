#pragma once
#include "pros/adi.hpp"
using namespace pros;

// Yellow Ziptie
extern adi::Pneumatics lift;

extern adi::Pneumatics grabber;
//
void liftLoad();

void liftToggle();