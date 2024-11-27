#include "lemlib/chassis/chassis.hpp"
#include "subsystemsHeaders/Lift.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "subsystemsHeaders/mogo.hpp"
#include "subsystemsHeaders/intake.hpp"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/Lift.hpp"
///////////////////////////////////////////////////////////////////////////////////////////
//!  General Params
float earlyExitRange = 4;
float doinkerDelay = 50;
float goalGrabMaxSpeed = 50;
float poleMaxSpeed = 50;
float normalMinSpeed = 60;
float normalMaxSpeed = 80;
float turnTimeout = 650;
float swingTimeout = 900;
float smallDriveTimout = 750;
float midDriveTimeout = 1000;
float largeDriveTimeout = 2200;
float waitUntil = 10;

//!  Goal Rush Specific Params
float goalRushSpeed = 100;

//! Ring Stack Specifc Params
float ringStackSpeed = 80;

//! Solo Specific Params
float soloSpeed = 80;

//! Skills Specific Params
float skillsSpeed = 80;
///////////////////////////////////////////////////////////////////////////////////////////
void redRight() { chassis.setPose(0, 0, 180);
  chassis.moveToPose(7.5, 37, -170, 1400, {.forwards = false, .minSpeed = goalRushSpeed, .earlyExitRange = earlyExitRange});
chassis.waitUntilDone();

      doinker.set_value(true);

delay(doinkerDelay);

  chassis.moveToPoint(4, 30, 750);

      request_new_state_mogo(StateMogo::LOCATE);

      doinker.set_value(false);

  chassis.moveToPoint(8, 40, 750, {.maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  chassis.turnToPoint(17, 35, 500, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});

    state_machine_intake(false);

  chassis.moveToPoint(17, 35, 750);
chassis.waitUntilDone();

  chassis.turnToHeading(0, 850);

    basketScore(1000);

  chassis.moveToPose(17, -2, 0, 1200, {.forwards = false});
chassis.waitUntilDone();

      request_new_state_mogo(StateMogo::RELEASE);

  chassis.moveToPoint(17, 4, 500, {.minSpeed = normalMinSpeed, .earlyExitRange = earlyExitRange});

  chassis.turnToHeading(135, 500);
chassis.waitUntilDone();

  chassis.moveToPose(-2, 17, 135, 1200);
chassis.waitUntilDone();

  chassis.moveToPose(33, 10, 180, 1500);

    state_machine_intake(false);

  chassis.moveToPoint(33, -3, 600);

  chassis.swingToHeading(135, lemlib::DriveSide::LEFT, 650);
chassis.waitUntilDone();

  chassis.moveToPose(-22, 21, -62, 1000, {.forwards = false, .maxSpeed = normalMaxSpeed});
chassis.waitUntil(waitUntil);
chassis.cancelMotion();

  chassis.moveToPose(-22, 21, -62, 1000, {.maxSpeed = poleMaxSpeed});
}
///////////////////////////////////////////////////////////////////////////////////////////
void redLeft() { chassis.setPose(0, 0, 0);
  chassis.turnToHeading(15, turnTimeout);

      doinker.set_value(true);

delay(doinkerDelay);

  chassis.turnToHeading(170, turnTimeout);

    state_machine_intake(false);

  chassis.turnToHeading(0, turnTimeout);

  chassis.moveToPose(6, -17, -35, smallDriveTimout, {.forwards = false, .minSpeed = normalMaxSpeed});
chassis.waitUntil(waitUntil);
chassis.cancelMotion();

      request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPose(6, -17, -35, smallDriveTimout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});

  chassis.turnToHeading(140, turnTimeout, {.maxSpeed = 70});

    basketScore(1000);

    state_machine_intake(true);

  chassis.moveToPose(22, -41, 140, midDriveTimeout, {.minSpeed = normalMinSpeed, .earlyExitRange = earlyExitRange});

  chassis.swingToHeading(90, lemlib::DriveSide::LEFT, swingTimeout);
chassis.waitUntilDone();

  chassis.moveToPose(38, -43, 90, midDriveTimeout, {.maxSpeed = normalMaxSpeed});

delay(250);

    basketScore(1000);

  chassis.turnToPoint(35, -27, turnTimeout);

    state_machine_intake(false);

  chassis.moveToPoint(35, -27, smallDriveTimout, {.minSpeed = normalMaxSpeed});

  chassis.moveToPose(11, 8, -90, largeDriveTimeout);

      request_new_state_mogo(StateMogo::RELEASE);

    liftLoad();

  chassis.moveToPoint(24, 8, midDriveTimeout);
chassis.waitUntilDone();

  chassis.moveToPoint(12, 8, midDriveTimeout, {.forwards = false});

  while (DistanceMogo.get() > 130) {
    DTLeft.move(-60), DTRight.move(-60);
  }

    lift_to_target_position(0);

  chassis.moveToPoint(12, -16, smallDriveTimout);
chassis.waitUntil(waitUntil);
chassis.cancelMotion();

  chassis.moveToPoint(12, -16, smallDriveTimout, {.maxSpeed = poleMaxSpeed});
}
///////////////////////////////////////////////////////////////////////////////////////////
void redSolo() { chassis.setPose(0, 0, 0); }
///////////////////////////////////////////////////////////////////////////////////////////
void redRightElim() { chassis.setPose(0, 0, 0); }
///////////////////////////////////////////////////////////////////////////////////////////
void redLeftElim() { chassis.setPose(0, 0, 0); }
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void blueRight() { chassis.setPose(0, 0, 0); }
///////////////////////////////////////////////////////////////////////////////////////////
void blueLeft() { chassis.setPose(0, 0, -180); 
  chassis.moveToPose(-7.5, 37, 170, 1400, {.forwards = false, .minSpeed = goalRushSpeed, .earlyExitRange = earlyExitRange});
chassis.waitUntilDone();

      doinker.set_value(true);

delay(doinkerDelay);

  chassis.moveToPoint(-4, 30, 750);

      request_new_state_mogo(StateMogo::LOCATE);

      doinker.set_value(false);

  chassis.moveToPoint(-8, 40, 750, {.maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  chassis.turnToPoint(-17, 35, 500, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});

    state_machine_intake(false);

  chassis.moveToPoint(-17, 35, 750);
chassis.waitUntilDone();

  chassis.turnToHeading(-0, 850);

    basketScore(1000);

  chassis.moveToPose(-17, -2, -0, 1200, {.forwards = false});
chassis.waitUntilDone();

      request_new_state_mogo(StateMogo::RELEASE);

  chassis.moveToPoint(-17, 4, 500, {.minSpeed = normalMinSpeed, .earlyExitRange = earlyExitRange});

  chassis.turnToHeading(-135, 500);
chassis.waitUntilDone();

  chassis.moveToPose(2, 17, -135, 1200);
chassis.waitUntilDone();

  chassis.moveToPose(-33, 10, -180, 1500);

    state_machine_intake(false);

  chassis.moveToPoint(-33, -3, 600);

  chassis.swingToHeading(-135, lemlib::DriveSide::RIGHT, 650);
chassis.waitUntilDone();

  chassis.moveToPose(22, 21, 62, 1000, {.forwards = false, .maxSpeed = normalMaxSpeed});
chassis.waitUntil(10);
chassis.cancelMotion();

  chassis.moveToPose(22, 21, 62, 1000, {.maxSpeed = poleMaxSpeed}); 
}
///////////////////////////////////////////////////////////////////////////////////////////
void blueSolo() { chassis.setPose(0, 0, 0); }
///////////////////////////////////////////////////////////////////////////////////////////
void blueRightElim() { chassis.setPose(0, 0, 0); }
///////////////////////////////////////////////////////////////////////////////////////////
void blueLeftElim() { chassis.setPose(0, 0, 0); }
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Skills() { chassis.setPose(0, 0, 0);
//!!! chassis.resetLocalPosition(); !!!//
}
