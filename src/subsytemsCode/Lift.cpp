#include "subsystemsHeaders/Lift.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "subsystemsHeaders/intake.hpp"
using namespace pros;

///////// global
adi::Pneumatics liftPTO('D', false);

adi::Pneumatics extender('C', false);

bool liftPTOActuated = false;
bool extenderActuated = false;
////////PID
lemlib::PID lbPID(0.6, 0, 0, 5, false);

void lift_to_target_position(int targetPosition, int timeout) {
  double currentPosition = Intake.get_position();
  double startTime = pros::millis();
  while (pros::millis() - startTime < timeout) {
    if (liftPTOActuated == true) {
      double lbPos = lbPID.update(targetPosition - currentPosition);
      Intake.move(lbPos);
    }
  }
}

void liftScore() {
  lift_to_target_position(480, 1000);
}

void liftLoad() {
  extender.set_value(true);
  lift_to_target_position(100);
  basketScore(1000);
}

void liftReset() {
  lift_to_target_position(0, 1200);
  extender.set_value(false);
}
//////// Driver Control
void liftPTOToggle() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
    liftPTOActuated = !liftPTOActuated;
    liftPTO.set_value(liftPTOActuated);
    Intake.set_brake_mode(liftPTOActuated ? E_MOTOR_BRAKE_HOLD : E_MOTOR_BRAKE_COAST);
  }
}

void extenderToggle() {
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
    extenderActuated = !extenderActuated;
    extender.set_value(extenderActuated);
  }
}

void liftDriver() {
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
    liftScore();
  } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
    liftReset();
  } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    liftLoad();
  }
}