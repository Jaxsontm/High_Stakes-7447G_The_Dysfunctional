#include "subsystemsHeaders/Lift.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "subsystemsHeaders/drive.hpp"
using namespace pros;

///////// global
adi::Pneumatics lift('D', false);

adi::Pneumatics grabber('E', false);

bool liftActuated = false;
bool grabberActuated = false;
////////Macros
//////// Driver Control
void liftToggle() {
	if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) {
		liftActuated = !liftActuated;
		lift.set_value(liftActuated);
	}
	
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
		grabberActuated = !grabberActuated;
		grabber.set_value(grabberActuated);
	}
}