#include "drive.cpp"
#include "subsystems.h/mogo.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/misc.h"
using namespace pros;
/////// Globals
Distance DistanceMogo(8);

adi::Pneumatics Mogo('A', false);

bool actuated = false;
////// Driver Control
void mogoToggle() {
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)){
        if (actuated){
            actuated = true;
            Mogo.set_value(!actuated);
        } else {
            actuated = false;
            Mogo.set_value(actuated);
        }
    }
}
////// State Machine
StateMogo current_state_mogo = RELEASE;

void request_new_state_mogo(StateMogo request_new_state_mogo) {
    if (request_new_state_mogo != current_state_mogo){
        request_new_state_mogo = current_state_mogo;
    }
}

void state_machine_mogo() {
    while(true) {
        switch(current_state_mogo) {
            case LOCATE: 
                if (DistanceMogo.get() <= 87) {
                    current_state_mogo = StateMogo::GRAB;
                } else {
                    Mogo.set_value(actuated);
                }

                break;
            case GRAB:
                delay(100);
                
                Mogo.set_value(!actuated);

                break;
            case RELEASE:
                Mogo.set_value(actuated);

              break;
            }
        delay(10);
    }
}