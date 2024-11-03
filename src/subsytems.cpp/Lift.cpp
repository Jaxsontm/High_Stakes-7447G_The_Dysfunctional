#include "pros/misc.h"
#include "subsystems.h/drive.hpp"
#include "subsystems.h/Lift.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/motors.hpp"
using namespace pros;

///////// global
Motor Lift(20, MotorGearset::green, MotorEncoderUnits::degrees);

//////// PID
void LiftPID(double liftTarget) {
    while (true) {
        lemlib::PID liftController (
            0.6, 
            0, 
            0,
            5, 
            true
        );

        double liftOutput = liftController.update(liftTarget - Lift.get_position());
        Lift.move(liftOutput);

        delay(5);
    }
}

/////// State Machine
/*StateLift current_state_lift = BOTTOM;

void state_machine_lift() {
    current_state_lift = MOVE;
    while (true) {
        switch (current_state_lift) {
            case MOVE:
                if (position == 0) {
                    current_state_lift = BOTTOM;
                } else if (position == 1) {
                    current_state_lift = NEUTRAL;
                }
            case BOTTOM:
                LiftPID(0);

                break;
            case NEUTRAL:
                LiftPID(800);

                break;
        }
    }
}

//////// Driver Control
void liftControl() {
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
        state_machine_lift();       
    } else if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) {
        state_machine_lift();
    }
}*/