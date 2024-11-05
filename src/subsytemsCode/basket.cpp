#include "subsystemsHeaders/basket.hpp"
#include "pros/misc.h"
#include "subsystemsHeaders/drive.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
using namespace pros;
/////// globals
Motor basket(10, MotorGearset::green);

adi::Button basketLimit('C');
////////// PID
void basketPID(double basketTarget) {
    while (true) {
        lemlib::PID basketControl (
            0.6, 
            0, 
            0,
            5, 
            true
        );

        double basketOutput = basketControl.update(basketTarget - basket.get_position());
        basket.move(basketOutput);

        delay(5);
    }
}
/////// Score
void basketScore() {
    basketPID(200);
    delay(50);
    while (basketLimit.get_value() == 0) {
        basket.move(-100);
    basket.tare_position();
    basket.brake();
    }
}
//////// Driver Control
void basketDriver() {
    if (controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
        basketScore();
    }
}