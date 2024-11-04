#include "pros/adi.hpp"
#include "subsystems.h/Lift.hpp"
#include "subsystems.h/drive.hpp"
using namespace pros;

///////// global
adi::Pneumatics Lift('A', true);

bool actuated = true;
//////// Driver Control
void liftToggle() {
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)){
        if (!actuated){
            actuated = !actuated;
            Lift.set_value(true);
        } else {
            actuated = !actuated;
            Lift.set_value(false);
        }
    }
}