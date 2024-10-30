#include "subsystems.h/intake.hpp"
#include "pros/misc.h"
#include "subsystems.h/flipper.hpp"
#include "subsystems.h/drive.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/motors.hpp"
using namespace pros;
/////// globals

Motor Intake(11, MotorGearset::blue);

Distance BasketCheck(19);

Distance RingCounter(21);

adi::Pneumatics intakePiston('B', false);
////// Driver Control
void intakeControl() {
    if (controller.get_digital(E_CONTROLLER_DIGITAL_L1) && (flipperLimit.get_value() == 1) && BasketCheck.get() < 120) {
        Intake.move(127);
    } else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2)) {
        Intake.move(-127);
    } else {
        Intake.brake();
    }
}

//////// state machine
StateIntake current_state_intake = BRAKE;

void request_new_state_intake(StateIntake requested_new_state_intake, bool two_rings) {
    if (requested_new_state_intake != current_state_intake) {
        requested_new_state_intake = current_state_intake;
    }

    while (true) {
        switch(current_state_intake) {
        case LOAD:
            if (RingCounter.get() > 20 && flipperLimit.get_value() == 1) {
                Intake.move(127);
            } else {
                current_state_intake = CHECK;
            }
            break;
        case CHECK:
            if (flipperLimit.get_value() == 0) {
                current_state_intake = BRAKE;
            } else {
                if (two_rings) {
                    if (BasketCheck.get() < 120) {
                        current_state_intake = LOAD;
                    } else {
                        current_state_intake = BRAKE;
                    }
                } else {
                    current_state_intake = BRAKE;
                }
            }
            break;
        case BRAKE:
            Intake.brake();

            break;
        }
    }
}