#pragma once
#include "robodash/views/selector.hpp"
using namespace rd;

void RightAWP();
void LeftAWP();
void BlueRight();
void Score();
void Forwards();
void Skills();

static Selector selector({
   {"Right AWP", &RightAWP},
   {"Left AWP", &LeftAWP},
   {"Blue SUPER SCORE", &BlueRight},
   {"Red SUPER SCORE", &Score},
   {"Forwards", &Forwards}, 
   {"Skills", &Skills},
   
   
}); 

static Console console;