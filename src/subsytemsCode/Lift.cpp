#include "pros/adi.hpp"
#include "subsystemsHeaders/Lift.hpp"
#include "subsystemsHeaders/drive.hpp"
using namespace pros;

///////// global
adi::Pneumatics Lift('A', true);

bool liftActuated = true;

//////// Driver Control
void liftToggle() {
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)){
        if (!liftActuated){
            liftActuated = !liftActuated;
            Lift.set_value(true);
        } else {
            liftActuated = !liftActuated;
            Lift.set_value(false);
        }
    }
}