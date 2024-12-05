#include "subsystemsHeaders/mogo.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/misc.h"
#include "subsystemsHeaders/drive.hpp"

using namespace pros;

/////// Globals
Distance DistanceMogo(8);

adi::Pneumatics Mogo('B', false);

adi::Pneumatics doinker('C', false);

bool doinkerActuated = false;

bool mogoActuated = false;

////// State Machine
StateMogo current_state_mogo = StateMogo::RELEASE;

void request_new_state_mogo(StateMogo request_new_state_mogo) {
  if (request_new_state_mogo != current_state_mogo) {
    current_state_mogo = request_new_state_mogo;
  }
}

void state_machine_mogo() {
  while (true) {
    switch (current_state_mogo) {
    case StateMogo::LOCATE:
      if (DistanceMogo.get() <= 87) {
        current_state_mogo = StateMogo::GRAB;
      } else {
        Mogo.set_value(false);
      }
      break;
    case StateMogo::GRAB:
      delay(100);
      Mogo.set_value(true);
      current_state_mogo = StateMogo::RELEASE;
      break;
    case StateMogo::RELEASE:
      Mogo.set_value(false);
      break;
    }
    delay(5);
  }
}

////// Driver Control
void mogoToggle() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
    mogoActuated = !mogoActuated;
    Mogo.set_value(mogoActuated);
  }
}

void doinkerToggle() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
    doinkerActuated = !doinkerActuated;
    doinker.set_value(doinkerActuated);
  }
}