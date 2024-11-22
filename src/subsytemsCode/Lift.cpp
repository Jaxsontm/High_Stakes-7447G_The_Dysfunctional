#include "pros/adi.hpp"
#include "subsystemsHeaders/Lift.hpp"
#include "subsystemsHeaders/drive.hpp"
using namespace pros;

///////// global
adi::Pneumatics liftPTO('A', true);

bool liftPTOActuated = true;

//////// Driver Control
void liftPTOToggle() {
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)){
        if (!liftPTOActuated){
            liftPTOActuated = !liftPTOActuated;
            liftPTO.set_value(true);
        } else {
            liftPTOActuated = !liftPTOActuated;
            liftPTO.set_value(false);
        }
    }
}