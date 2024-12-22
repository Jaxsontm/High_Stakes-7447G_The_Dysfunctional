#include "subsystemsHeaders/Lift.hpp"

///////// global
Motor lift(10, MotorGearset::green, MotorEncoderUnits::degrees);

adi::Pneumatics grabber('E', false);

bool liftActuated = false;
bool grabberActuated = false;
////////Macro
void setLiftPos(int targetPos) {
  lift.move_absolute(targetPos, 127);
}
//////// Driver Control
void liftDriver() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) {
    grabber.set_value(true);
    setLiftPos(500);
  }

  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) {
    grabber.set_value(false);
    setLiftPos(1200);
  }
}

void grabberToggle() {
	if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) {
		grabberActuated = !grabberActuated;
		grabber.set_value(grabberActuated);
	}
}