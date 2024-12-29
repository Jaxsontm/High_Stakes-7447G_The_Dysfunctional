#include "subsystemsHeaders/mogo.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "subsystemsHeaders/drive.hpp"

/////// Globals
Distance DistanceMogo(2);

adi::Pneumatics Mogo('D', false);

adi::Pneumatics doinker('C', false);

bool doinkerActuated = false;
bool mogoActuated = false;
////// State Machine
StateMogo current_state_mogo;

void request_new_state_mogo(StateMogo request_new_state_mogo) {
	if (request_new_state_mogo != current_state_mogo) {
		current_state_mogo = request_new_state_mogo;
	}
}

void state_machine_mogo() {
	while (true) {
		switch (current_state_mogo) {
      case StateMogo::LOCATE:
        while (DistanceMogo.get() > 32) delay(10);
        delay(50);
        current_state_mogo = StateMogo::GRAB;
        break;
      case StateMogo::GRAB:
        Mogo.set_value(false);
        mogoActuated = true;
        break;
      case StateMogo::RELEASE:
        Mogo.set_value(true);
        mogoActuated = false;
        break;
      case StateMogo::opGRAB:
        Mogo.set_value(false);
        mogoActuated = true;
        break;
    }
		delay(5);
	}
}

////// Driver Control
void mogoToggle() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
    if (mogoActuated) {
      request_new_state_mogo(StateMogo::RELEASE);
    } else {
      request_new_state_mogo(StateMogo::GRAB);
    }
  }
}

void doinkerToggle() {
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
		doinkerActuated = !doinkerActuated;
		doinker.set_value(doinkerActuated);
	}
}
