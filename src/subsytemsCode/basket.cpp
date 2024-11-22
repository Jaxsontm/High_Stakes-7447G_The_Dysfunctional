#include "subsystemsHeaders/basket.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"

using namespace pros;
/////// globals
Motor basket(-6, MotorGearset::green);

adi::Button basketLimit('H');
/////// Score
void basketScore(void* param) {
    int timeout = *(int*)param;
    int startTime = pros::millis();
    while (basket.get_position() < 380) {
        if (pros::millis() - startTime < timeout) {
          basket.move(127);  
        } else {
            break;
        }
        delay(5);
    }
    delay(75);
    while (basketLimit.get_value() == 0) {
        if (pros::millis() - startTime < timeout) {
          basket.move(-127);  
        } else {
            break;
        }
        delay(5);
    }
    basket.brake();
    basket.tare_position();  
}

//////// Driver Control
void basketDriver() {
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_R2)) {
        static int timeout = 1000;
        pros::Task basketTask(basketScore, &timeout, "Basket Scoring");
    }
}