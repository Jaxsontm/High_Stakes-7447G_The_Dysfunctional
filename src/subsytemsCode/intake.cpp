#include "subsystemsHeaders/intake.hpp"
#include "pros/misc.h"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/motors.hpp"
#include "auton_selector.hpp"
using namespace pros;

/////// globals
Motor Intake(11, MotorGearset::blue);

Distance BasketCheck(19);

adi::Pneumatics intakePiston('B', false);

Optical color (10);

bool up = false;

//////// state machine
StateIntake current_state_intake = BRAKE;

void state_machine_intake(bool two_rings, bool color_sort) {
    while (true) {
        switch(current_state_intake) {
            case LOAD:
                if (color_sort == true){
                    current_state_intake = COLOR;
                } else {
                    if (two_rings == true) {
                        if (BasketCheck.get() > 120) {
                            while (BasketCheck.get() > 120 && basketLimit.get_value() == 1) {
                                Intake.move(127);
                            } 
                            current_state_intake = CHECK;
                        } else if (BasketCheck.get() > 70) {
                            while (BasketCheck.get() > 70 && basketLimit.get_value() == 1) {
                                Intake.move(127);
                            } 
                            current_state_intake = CHECK;
                        }
                    } else {
                        while (BasketCheck.get() > 70 && basketLimit.get_value() == 1 || BasketCheck.get() > 120 && basketLimit.get_value() == 1) {
                            Intake.move(127);
                        }
                        current_state_intake = CHECK;
                    }
                }
                break;
            case CHECK:
                if (basketLimit.get_value() == 0) {
                    current_state_intake = BRAKE;
                } else {
                    if (two_rings == true) {
                        if (BasketCheck.get() < 120) {
                            current_state_intake = LOAD;
                        } else if (BasketCheck.get() < 70) {
                            current_state_intake = BRAKE;
                        }
                    } else {
                        current_state_intake = BRAKE;
                    }
                }
                break;
            case COLOR:
                if (blue == true) {
                    while (color.get_hue() > 315) {
                        if (two_rings == true) {
                            if (BasketCheck.get() > 120) {
                                while (BasketCheck.get() > 120 && basketLimit.get_value() == 1) {
                                    Intake.move(127);
                                }
                                current_state_intake = CHECK;
                            } else if (BasketCheck.get() > 70) {
                                while (BasketCheck.get() > 70 && basketLimit.get_value() == 1) {
                                    Intake.move(127);
                                } 
                                current_state_intake = CHECK;
                            }
                        } else {
                            while (BasketCheck.get() > 70 && basketLimit.get_value() == 1 || BasketCheck.get() > 120 && basketLimit.get_value() == 1) {
                                Intake.move(127);
                            }
                            current_state_intake = CHECK;
                        }
                    }
                    basketSort();
                }       
                break;
            case BRAKE:
                Intake.brake();

                break;
            }
            delay(10);
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