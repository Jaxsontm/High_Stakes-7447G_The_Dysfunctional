#pragma once
#include "pros/adi.hpp"
#include "pros/motors.hpp"
using namespace pros;

extern Motor basket;

extern adi::Button basketLimit;

void basketScore(int timeout);

void basketDriver();

enum BasketState {
    IDLE,
    UP,
    PAUSE,
    DOWN,
    DONE
};