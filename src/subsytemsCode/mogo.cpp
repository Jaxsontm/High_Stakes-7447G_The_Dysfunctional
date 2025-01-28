#include "subsystemsHeaders/mogo.hpp"
#include "pros/rtos.hpp"

/////// Globals
Distance DistanceMogo(2);

adi::Pneumatics Mogo('D', false);

adi::Pneumatics doinker('C', false);

bool doinkerActuated = false;

pros::Task* mogo_task = nullptr;
////// State Machine
bool mogoActuated = false;
StateMogo current_state_mogo = StateMogo::GRAB;

void request_new_state_mogo(StateMogo request_new_state_mogo) {
	if (request_new_state_mogo != current_state_mogo) {
		current_state_mogo = request_new_state_mogo;
	}
}

void state_machine_mogo() {
	while (true) {
		switch (current_state_mogo) {
      case StateMogo::LOCATE:
        Mogo.set_value(true);
        delay(250);
        while (DistanceMogo.get() > 39) delay(10);
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
    }
		delay(10);
	}
}

void startMogo() {
  stopMogo();

  mogo_task = new pros::Task(state_machine_mogo);
}

void stopMogo() {
  if (mogo_task != nullptr) {
    mogo_task->remove();
    delete mogo_task;
    mogo_task = nullptr;
  }
}

void resetMogo() {
  startMogo();

  StateMogo current_state_mogo = StateMogo::GRAB;
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
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
		doinkerActuated = !doinkerActuated;
		doinker.set_value(doinkerActuated);
	}
}

pros::Task text_task([]{
  const char *status = mogoActuated ? "GRAB" : "OPEN";
  controller.print(1, 7, status);
});
