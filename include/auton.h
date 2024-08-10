#pragma once
#include "robodash/views/selector.hpp"

enum State { 
    LOAD = 0, 
    IDLE = 1, 
    SCORE = 2, 
    UNLOAD = 3, 
    BRAKE = 4
    };

enum StateMogo {
    LOCATE = 0, 
    GRAB = 1,
    RELEASE = 2
};

void state_machine();
void state_machine_mogo();
void request_new_state(State new_state);
void request_new_state_mogo(StateMogo new_state);

void RightAWP();
void LeftAWP();
void BlueRight();
void Score();
void Forwards();
void Skills();

static rd::Selector selector({
   {"Right AWP", &RightAWP},
   {"Left AWP", &LeftAWP},
   {"Blue SUPER SCORE", &BlueRight},
   {"Red SUPER SCORE", &Score},
   {"Forwards", &Forwards}, 
   {"Skills", &Skills},
   
   
}); 

static rd::Console console;