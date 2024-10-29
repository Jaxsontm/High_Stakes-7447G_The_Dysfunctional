#pragma once
#include "robodash/views/console.hpp"
#include "robodash/views/selector.hpp"

//These are the names of the autons we are using
void RightAWP();
void LeftAWP();
void BlueRight();
void BlueLeft();
void Forwards();
void Skills();

//these are the names next to the actual loop using the name
static rd::Selector selector({
   {"Red Right", &RightAWP},
   {"Red Left", &LeftAWP},
   {"Blue Right", &BlueRight},
   {"Bliue Left", &BlueLeft},
   {"Forwards", &Forwards}, 
   {"Skills", &Skills}
}); 

static rd::Console console;