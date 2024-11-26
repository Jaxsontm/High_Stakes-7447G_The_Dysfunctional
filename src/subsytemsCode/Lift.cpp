#include "subsystemsHeaders/Lift.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "subsystemsHeaders/drive.hpp"
#include "subsystemsHeaders/intake.hpp"

using namespace pros;

///////// global
adi::Pneumatics liftPTO('A', false);

bool liftPTOActuated = false;
////////PID
lemlib::PID lbPID(0.6, 0, 0, 5, false);

void lift_to_target_position(int targetPosition) {
  double currentPosition = Intake.get_position();
  if (liftPTOActuated == true) {
    double lbPos = lbPID.update(targetPosition - currentPosition);
    Intake.move(lbPos);
  }
}

void liftScore() {
  lift_to_target_position(400);
  delay(50);
  lift_to_target_position(0);
}
//////// Driver Control
void liftPTOToggle() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) {
    liftPTOActuated = !liftPTOActuated;
    liftPTO.set_value(liftPTOActuated);
  }
}

void liftDriver() {
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
    lift_to_target_position(-120);
  } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
    liftScore();
  }
}