#include "subsystemsHeaders/basket.hpp"
#include "pros/misc.h"
#include "subsystemsHeaders/drive.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
using namespace pros;
/////// globals
Motor basket(-6, MotorGearset::green);

adi::Button basketLimit('H');
/////// Score
void basketScore() {
    while (basket.get_position() < 425){
        basket.move(127);
        delay(5);
    }
    delay(150);
    while (basketLimit.get_value() == 0) {
        basket.move(-127);
        delay(5);
    }
    basket.brake();
    basket.tare_position();
}
//////// Driver Control
void basketDriver() {
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_R2)) {
        basketScore();
    }
}