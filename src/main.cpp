#include "nah/main.h"
#include "liblvgl/core/lv_disp.h"
#include "liblvgl/core/lv_obj_pos.h"
#include "liblvgl/llemu.hpp"
#include "liblvgl/misc/lv_area.h"
#include "liblvgl/widgets/lv_label.h"
#include "pros/abstract_motor.hpp"
#include "pros/llemu.hpp"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/intake.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"
#include "auton_selector.hpp"
#include "auton.h"
#include "subsystemsHeaders/mogo.hpp"


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    pros::lcd::set_text(2, "I was pressed!");
  } else {
    pros::lcd::clear_line(2);
  }
}

void screen() {
    while (true) {
        pros::lcd::print(0, "X: %f", chassis.getPose().x);
        pros::lcd::print(1, "Y: %f", chassis.getPose().y);
        pros::lcd::print(2, "Theta: %f", chassis.getPose().theta);
        pros::delay(50);
    }
}

void initialize() {
    Intake.set_brake_mode(pros::MotorBrake::coast);
    basket.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
    basket.set_brake_mode(MotorBrake::hold);
    pros::Task auton_selector_task(selector);
    Task stats_task([&]() {
        char text[150];
        lv_obj_t * stats_label = lv_label_create(lv_scr_act());
        lv_obj_align(stats_label, LV_ALIGN_BOTTOM_MID, 50, -10);
        while (true) {
            lemlib::Pose trackerPos = chassis.getPose();

            sprintf(text, "Switch: %i", basketLimit.get_value());
            lv_label_set_text(stats_label, text);

            pros::delay(10);
        }
    });
}   

void disabled() {}

void competition_initialize() {
    selector();
}

void autonomous() {
    if (autonSelection == 0) {
        Skills();
    } else if (autonSelection == 1) {
        redRight();
    } else if (autonSelection == 2) {
        redLeft();
    } else if (autonSelection == 3) {
        redSolo();
    } else if (autonSelection == 4) {
        redRightElim();
    } else if (autonSelection == 5) {
        redLeftElim();
    } else if (autonSelection == 6) {
        blueRight();
    } else if (autonSelection == 7) {
        blueLeft();
    } else if (autonSelection == 8) {
        blueSolo();
    } else if (autonSelection == 9) {
        blueRightElim();
    } else if (autonSelection == 10) {
        blueLeftElim();
    }
}

void opcontrol() {
    Intake.set_brake_mode(pros::MotorBrake::coast);
	while (true) {
    ///////////////////////////////////////////////////////////////

		intakeControl();

    /////////////////////////////////////////////////////////////////

        mogoToggle();

    /////////////////////////////////////////////////////////////////    
       


    /////////////////////////////////////////////////////////////////
        
        //liftToggle();

    /////////////////////////////////////////////////////////////////

        basketDriver();
    
    /////////////////////////////////////////////////////////////////
    
        tank();

        // delay to save resources
        pros::delay(20);
     }
	}
