#include "subsystemsHeaders/intake.hpp"
#include "pros/misc.h"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/drive.hpp"
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

bool up = false;

//////// state machine
StateIntake current_state_intake = BRAKE;

void state_machine_intake(bool two_rings) {
    while (true) {
        switch(current_state_intake) {
            case LOAD:
                if (RingCounter.get() > 20 && basketLimit.get_value() == 1) {
                    Intake.move(127);
                } else {
                    current_state_intake = CHECK;
                }
                break;
            case CHECK:
                if (basketLimit.get_value() == 0) {
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

////// Driver Control
void intakeControl() {
    if (controller.get_digital(E_CONTROLLER_DIGITAL_R1) /*&& (basketLimit.get_value() == 1) && BasketCheck.get() < 120*/) {
        Intake.move(127);
    } else {
        Intake.brake();
    }
}

void intakePistonToggle() {
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)){
        if (up){
            up = !up;
            intakePiston.set_value(true);
        } else {
            up = !up;
            intakePiston.set_value(false);
        }
    }
}