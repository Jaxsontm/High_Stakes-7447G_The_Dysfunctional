#include "auton.h"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "subsystemsHeaders/intake.hpp"
#include "subsystemsHeaders/mogo.hpp"
///////////////////////////////////////////////////////////////////////////////////////////
//!  General Params
float earlyExitRange = 4;
float doinkerDelay = 150;
float goalGrabMaxSpeed = 55;
float poleMaxSpeed = 70;
float normalMinSpeed = 60;
float normalMaxSpeed = 80;
float turnTimeout = 600;
float swingTimeout = 900;
float smallDriveTimeout = 600;
float midDriveTimeout = 1200;
float largeDriveTimeout = 2400;
float waitUntil = 10;

//!  Goal Rush Specific Params
float goalRushSpeed = 100;

//! Ring Stack Specifc Params
float ringStackSpeed = 100;

//! Solo Specific Params
float soloSpeed = 80;

//! Skills Specific Params
float skillsSpeed = 80;
///////////////////////////////////////////////////////////////////////////////////////////
/*void redGoal() { chassis.setPose(0, 0, 180);
  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(0, 30, midDriveTimeout,
                     {.forwards = false, .minSpeed = normalMaxSpeed});

  chassis.swingToHeading(150, lemlib::DriveSide::RIGHT, swingTimeout, {.minSpeed = 70, .earlyExitRange = 10});

  chassis.moveToPoint(-7, 42.5, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();
delay(250);

  chassis.turnToPoint(-11, 34, turnTimeout, {.minSpeed = 50, .earlyExitRange = 5});

  spinFor(StateIntake::ONE);
  
  chassis.moveToPoint(-11, 34, largeDriveTimeout, {.minSpeed = 80});
delay(1500);
  
  while (intakeState != 0) delay(10);

  delay(550);

  basketMove(StateBasket::SCORE);
  delay(250);

  while(basketState != 0) delay(10);

  spinFor(StateIntake::REV);

  chassis.moveToPoint(-19, 5, midDriveTimeout, {.minSpeed = 80});
chassis.waitUntil(25);

  request_new_state_mogo(StateMogo::RELEASE);
chassis.waitUntilDone();

  chassis.turnToHeading(152.5, turnTimeout);
chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(-27.8, 14, 700, {.minSpeed = 90});

  chassis.moveToPoint(-30, 17.5, smallDriveTimeout, {.maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  chassis.turnToPoint(-44.35, 10.5, turnTimeout);
  chassis.waitUntilDone();

  spinFor(StateIntake::TWO);

  chassis.moveToPoint(-44.35, 10.5, 700, {.minSpeed = goalRushSpeed});

  chassis.moveToPoint(-50.5, 7.5, smallDriveTimeout, {.maxSpeed = normalMinSpeed});

  chassis.moveToPoint(-56.65, 4.5, smallDriveTimeout, {.minSpeed = normalMaxSpeed});
  chassis.waitUntilDone();

  chassis.turnToHeading(-10, turnTimeout);
  chassis.waitUntilDone();

  basketMove(StateBasket::TOP);
  delay(250);

  chassis.moveToPoint(-57.75, 15.5, midDriveTimeout, {.maxSpeed = poleMaxSpeed});
  chassis.turnToHeading(-90, turnTimeout, {.maxSpeed = 80});
chassis.waitUntilDone();
delay(150);

  request_new_state_mogo(StateMogo::RELEASE);

  chassis.turnToHeading(180, turnTimeout, {.maxSpeed = 70});
chassis.waitUntilDone();
delay(250);

  spinFor(StateIntake::REV);

  chassis.moveToPoint(-10, 7, midDriveTimeout, {.minSpeed = 50, .earlyExitRange = 5});

  chassis.turnToHeading(-90, turnTimeout, {.minSpeed = 50, .earlyExitRange = 5});
  
  spinFor(StateIntake::TWO);

  chassis.moveToPose(-38, 2.5, -89, 900, {.lead = 0, .minSpeed = 90, .earlyExitRange = 5});

  chassis.moveToPoint(-58, 2.5, midDriveTimeout, {.maxSpeed = 60});
  chassis.waitUntilDone();

delay(500);
  
  chassis.moveToPoint(-65, 2.5, midDriveTimeout);

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.swingToHeading(230 , lemlib::DriveSide::RIGHT, turnTimeout, {.maxSpeed = 80});
chassis.waitUntilDone();

  chassis.moveToPoint(-38, 22, largeDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  delay(500);

  basketMove(StateBasket::TOP);
delay(1250);

  while(basketState != 0) delay(10);  

  chassis.swingToHeading(300, lemlib::DriveSide::RIGHT, swingTimeout, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
chassis.waitUntilDone();

  chassis.moveToTime(61, 60, 475);
chassis.waitUntilDone();
}*/
///////////////////////////////////////////////////////////////////////////////////////////
void redGoal() { chassis.setPose(0,-7,0);
  spinFor(StateIntake::ONE);

  chassis.moveToPoint(12.25, 20, midDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(180, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToPoint(12.25, 34.5, midDriveTimeout, {.forwards = false, .maxSpeed = 80});
chassis.waitUntilDone();

  doinker.set_value(true);
  delay(50);

  chassis.moveToPoint(12.25, 26.5, midDriveTimeout);
chassis.waitUntilDone();

  doinker.set_value(false);

  chassis.turnToHeading(90, turnTimeout);
chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(-7.5, 26.5, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
delay(250);

  while (basketState != 0) delay(10);

  chassis.moveToPoint(-7.5, 40, midDriveTimeout);
}
///////////////////////////////////////////////////////////////////////////////////////////
void redRing() { chassis.setPose(-0, 0, 90);
  spinFor(StateIntake::REV);
  
  chassis.moveToPoint(6, 0, smallDriveTimeout);
  chassis.waitUntilDone();

  chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 700);
chassis.waitUntilDone();

  chassis.moveToPoint(15.5, -6, smallDriveTimeout, {.forwards = false});
chassis.waitUntil(2.5);

  basketMove(StateBasket::TOP);
  delay(50);

  spinFor(StateIntake::BRAKE);

  while(basketState != 0) delay(10);

  chassis.moveToPoint(16, 2.5, smallDriveTimeout);

  chassis.turnToHeading(120, turnTimeout);
  chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  spinFor(StateIntake::ONE);

  chassis.moveToPoint(-0.55, 26.475, smallDriveTimeout, {.forwards = false, .minSpeed = 100});

  chassis.moveToPoint(-6, 36.75, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
  chassis.waitUntilDone();

  chassis.turnToHeading(-90, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToPoint(-25, 36.5, midDriveTimeout);
  delay(50);

  while (intakeState != 0) delay(10);
  
  basketMove(StateBasket::SCORE);
  delay(50);

  while (basketState != 0) delay(10);

  chassis.turnToPoint(-24.5, 48.5, smallDriveTimeout, {}, false);

  spinFor(StateIntake::TWO);

  chassis.moveToPoint(-25, 48.5, smallDriveTimeout);
  chassis.waitUntilDone();
  delay(200);

  chassis.moveToDist(-6, smallDriveTimeout);

  chassis.turnToHeading(-35, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToDist(11, smallDriveTimeout);
  chassis.waitUntilDone();
  delay(500);

  chassis.swingToHeading(58, lemlib::DriveSide::LEFT, swingTimeout);
  chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);

  chassis.moveToDist(18.5, midDriveTimeout, {.maxSpeed = 70});
}
///////////////////////////////////////////////////////////////////////////////////////////
void redSolo() { chassis.setPose(0, 0, 0); 
		spinFor(StateIntake::ONE);

  chassis.moveToPoint(15.25, 32, midDriveTimeout);
chassis.waitUntilDone();
delay(350);

  chassis.turnToHeading(95, turnTimeout);
chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(-1.5, 33, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();
delay(250);

  basketMove(StateBasket::SCORE);
delay(250);

  intakeP.set_value(true);

  chassis.moveToPoint(-10.5, 13, midDriveTimeout);
chassis.waitUntilDone();

  while (basketState != 0) delay(10);

  request_new_state_mogo(StateMogo::RELEASE);

  basketMove(StateBasket::RESET);

  chassis.turnToHeading(270, turnTimeout);
chassis.waitUntilDone();

  spinFor(StateIntake::ONE);

  chassis.moveToPoint(-20, 10, smallDriveTimeout, {.minSpeed = 90});
chassis.waitUntilDone();

  intakeP.set_value(false);

  chassis.moveToPoint(-17, 10, smallDriveTimeout, {.maxSpeed = 60});
  chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::GRAB);

  chassis.moveToPoint(-29, 10, 800);
chassis.waitUntilDone();

  doinker.set_value(true);

  chassis.turnToHeading(0, 450);
chassis.waitUntilDone();

  doinker.set_value(false);

  spinFor(StateIntake::REV);

  chassis.moveToPoint(-29, -5, midDriveTimeout, {.forwards = false, .minSpeed = 90});
chassis.waitUntilDone();

  while (intakeState != 0) delay(10);

  basketMove(StateBasket::SCORE);
  delay(250);

  while (basketState != 0) delay(10);

  chassis.swingToPoint(-79, 33, lemlib::DriveSide::LEFT, swingTimeout, {.minSpeed = 90}, false);

  spinFor(StateIntake::ONE);

  chassis.moveToPoint(-69, 25.4, midDriveTimeout, {.minSpeed = 90}, false);

  chassis.moveToPoint(-79, 33, 800, {.maxSpeed = 70});
  chassis.waitUntilDone();

  chassis.turnToHeading(275, 400);
  chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(-57, 33, midDriveTimeout, {.forwards = false, .maxSpeed = 65});
  chassis.waitUntilDone();
  delay(200);

  basketMove(StateBasket::SCORE);

  chassis.moveToPoint(-55.75, 44, midDriveTimeout);
}
///////////////////////////////////////////////////////////////////////////////////////////
void redGoalElim() { chassis.setPose(0, 0, 180); 
	doinker.set_value(true);

  chassis.moveToPoint(8, 32, midDriveTimeout,{.forwards = false, .minSpeed = goalRushSpeed});
  chassis.waitUntilDone();

  doinker.set_value(false);
  delay(150);

  chassis.turnToHeading(160, turnTimeout);
  chassis.waitUntilDone();

  spinFor(StateIntake::ONE);

  chassis.moveToPoint(18, 26, midDriveTimeout);
  chassis.waitUntilDone();

  while (intakeState != 0) delay(10);

  doinker.set_value(true);

  chassis.turnToHeading(90, turnTimeout);
  chassis.waitUntilDone();

  doinker.set_value(false);

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToDist(-27, midDriveTimeout, {.maxSpeed = 65});
  chassis.waitUntilDone();
  delay(200);

  basketMove(StateBasket::SCORE);
  delay(200);

  chassis.moveToPoint(18, 3, midDriveTimeout);
}
///////////////////////////////////////////////////////////////////////////////////////////
void redRingElim() { chassis.setPose(0, 0, 0);
  spinFor(StateIntake::ONE);

  chassis.moveToPoint(0, 20, midDriveTimeout);

  chassis.swingToHeading(270, lemlib::DriveSide::LEFT, swingTimeout);
chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(13.5, 27.25, midDriveTimeout, {.maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
delay(250);

  while (basketLimit.get_value() == 0) delay(10);

  spinFor(StateIntake::TWO);

  chassis.turnToHeading(345, turnTimeout);

  chassis.moveToPose(0, 41.5, 270, midDriveTimeout);
chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
delay(250);

  while (basketLimit.get_value() == 0) delay(10);

  spinFor(StateIntake::ONE);

  chassis.moveToPose(-14, -5.25, 180, largeDriveTimeout);
chassis.waitUntilDone();

  chassis.swingToHeading(225, lemlib::DriveSide::RIGHT, swingTimeout);
chassis.waitUntilDone();

  chassis.moveToTime(-65, -60, 200);
chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
delay(250);

  while (basketLimit.get_value() == 0) delay(10);

  spinFor(StateIntake::TWO);

  chassis.turnToHeading(100, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToPose(43.5, 3, 77.5, largeDriveTimeout);
chassis.waitUntilDone();

  basketMove(StateBasket::TOP);
}
///////////////////////////////////////////////////////////////////////////////////////////
void blueRing() { chassis.setPose(-0, 0, -90);
  spinFor(StateIntake::REV);
  
  chassis.moveToPoint(-6, 0, smallDriveTimeout);
  chassis.waitUntilDone();

  chassis.swingToHeading(0, lemlib::DriveSide::RIGHT, 700);
chassis.waitUntilDone();

  chassis.moveToPoint(-15.5, -6, smallDriveTimeout, {.forwards = false});
chassis.waitUntil(2.5);

  basketMove(StateBasket::TOP);
  delay(50);

  spinFor(StateIntake::BRAKE);

  while(basketState != 0) delay(10);

  chassis.moveToPoint(-16, 2.5, smallDriveTimeout);

  chassis.turnToHeading(-120, turnTimeout);
  chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  spinFor(StateIntake::ONE);

  chassis.moveToPoint(0.55, 26.475, smallDriveTimeout, {.forwards = false, .minSpeed = 100});

  chassis.moveToPoint(6, 36.75, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
  chassis.waitUntilDone();

  chassis.turnToHeading(90, 800);
  chassis.waitUntilDone();

  chassis.moveToPoint(25, 36.5, midDriveTimeout);
  delay(50);

  while (intakeState != 0) delay(10);
  
  basketMove(StateBasket::SCORE);
  delay(50);

  while (basketState != 0) delay(10);

  chassis.turnToPoint(24.5, 48.5, smallDriveTimeout, {}, false);

  spinFor(StateIntake::TWO);

  chassis.moveToPoint(25, 48.5, smallDriveTimeout);
  chassis.waitUntilDone();
  delay(200);

  chassis.moveToDist(-6, smallDriveTimeout);

  chassis.turnToHeading(35, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToDist(11, smallDriveTimeout);
  chassis.waitUntilDone();
  delay(500);

  chassis.swingToHeading(-58, lemlib::DriveSide::RIGHT, swingTimeout);
  chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);

  chassis.moveToDist(18.5, midDriveTimeout, {.maxSpeed = 70});
}
///////////////////////////////////////////////////////////////////////////////////////////
void blueGoal() { chassis.setPose(0,-7,0);
  spinFor(StateIntake::ONE);

  chassis.moveToPoint(-12.25, 20, midDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(180, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToPoint(-15.25, 33.5, midDriveTimeout, {.forwards = false, .maxSpeed = 80});
chassis.waitUntilDone();

  doinker.set_value(true);
  delay(50);

  chassis.moveToPoint(-12.25, 26.5, midDriveTimeout);
chassis.waitUntilDone();

  doinker.set_value(false);

  chassis.turnToHeading(-90, turnTimeout);
chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(7.5, 26.5, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
delay(250);

  while (basketState != 0) delay(10);

  chassis.moveToPoint(7.5, 40, midDriveTimeout);
}
///////////////////////////////////////////////////////////////////////////////////////////
void blueSolo() { chassis.setPose(-0, 0, -0); }
///////////////////////////////////////////////////////////////////////////////////////////
void blueRingElim() { chassis.setPose(-0, 0, -0); }
///////////////////////////////////////////////////////////////////////////////////////////
void blueGoalElim() { chassis.setPose(-0, 0, -0); }
///////////////////////////////////////////////////////////////////////////////////////////
void Skills() { chassis.setPose(0, 0, 0);
	basketMove(StateBasket::TOP);
delay(250);
  
  while (basketState != 0) delay(10);

  chassis.moveToPoint(0, 13, smallDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(270, turnTimeout);
chassis.waitUntilDone();

      request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(20, 13, midDriveTimeout, {.forwards = false, .maxSpeed = 50});
chassis.waitUntilDone();
delay(500);

  chassis.turnToHeading(5, 200);
chassis.waitUntilDone();

    spinFor(StateIntake::TWO);

  chassis.moveToPoint(23, 36, midDriveTimeout, {.maxSpeed = skillsSpeed});
chassis.waitUntilDone();
delay(500);

  chassis.turnToHeading(90, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToPoint(49, 38, midDriveTimeout, {.maxSpeed = skillsSpeed});
  chassis.waitUntilDone();

  while (intakeState != 0) delay(10);
delay(500);

    basketMove(StateBasket::SCORE);
delay(250);

  while (basketState != 0) delay(10);

  chassis.turnToHeading(180, turnTimeout);
chassis.waitUntilDone();

  spinFor(StateIntake::TWO);

  chassis.moveToPoint(49, 12, midDriveTimeout);
chassis.waitUntilDone();
delay(750);


  chassis.moveToPoint(48, 5, midDriveTimeout);
chassis.waitUntilDone();

  while (intakeState != 0) delay(10);
delay(750);

    basketMove(StateBasket::SCORE);
delay(250);

  while (basketState != 0) delay(10);

  chassis.turnToHeading(295, turnTimeout);
  chassis.waitUntilDone();

      request_new_state_mogo(StateMogo::RELEASE);

  chassis.moveToDist(-8, smallDriveTimeout);
chassis.waitUntilDone();

  chassis.moveToPoint(0, 13, largeDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(90, turnTimeout);
chassis.waitUntilDone();

      request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(-20, 12, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();
delay(500);

  chassis.turnToHeading(-5, 200);
chassis.waitUntilDone();

    spinFor(StateIntake::TWO);

  chassis.moveToPoint(-21, 36, midDriveTimeout, {.maxSpeed = skillsSpeed});
chassis.waitUntilDone();
delay(500);

  chassis.turnToHeading(-90, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToPoint(-48, 35.5, midDriveTimeout, {.maxSpeed = skillsSpeed});
chassis.waitUntilDone();
delay(500);

  while (intakeState != 0) delay(10);
delay(500);

    basketMove(StateBasket::SCORE);
delay(250);

  while (basketState != 0) delay(10);

  chassis.turnToHeading(180, turnTimeout);
chassis.waitUntilDone();

  spinFor(StateIntake::TWO);

  chassis.moveToPoint(-48, 12, midDriveTimeout);
chassis.waitUntilDone();
delay(750);

  chassis.moveToPoint(-47, 4, midDriveTimeout);
chassis.waitUntilDone();

  while (intakeState != 0) delay(10);
delay(500);

    basketMove(StateBasket::SCORE);
delay(250);

  while (basketState != 0) delay(10);

  chassis.turnToHeading(-295, turnTimeout);
  chassis.waitUntilDone();

      request_new_state_mogo(StateMogo::RELEASE);

  chassis.moveToDist(-10, smallDriveTimeout);
chassis.waitUntilDone();

  spinFor(StateIntake::TWO);

  chassis.moveToPoint(0, 60, largeDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(0, turnTimeout);
chassis.waitUntilDone();

chassis.setPose(0, 60, 0);

  chassis.turnToHeading(-45, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToPoint(-23.5,83.5 , midDriveTimeout);
  chassis.waitUntilDone();

  chassis.turnToHeading(0, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToPoint(-23.5, 107, midDriveTimeout);
  chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.turnToHeading(268, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToPoint(0, 107, largeDriveTimeout, {.maxSpeed = goalGrabMaxSpeed});
  chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
delay(250);

  while (basketState != 0) delay(10);

  chassis.swingToHeading(-50, lemlib::DriveSide::LEFT, swingTimeout);
  chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::RELEASE);

  chassis.moveToPoint(-51, 118, largeDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(-93, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToDist(-98, largeDriveTimeout);
  chassis.waitUntilDone();

  chassis.swingToHeading(-135, lemlib::DriveSide::LEFT, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToDist(-14, smallDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(-165, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToDist(20, smallDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(45, turnTimeout);
chassis.waitUntilDone();

  setLiftPos(liftPos::SCORE);

  chassis.moveToDist(-41, 4000, {.maxSpeed = skillsSpeed});
  chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
}

void rgAWP() { chassis.setPose(0, -7, 0);
  spinFor(StateIntake::ONE);

  chassis.moveToPoint(12.25, 20, midDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(90, turnTimeout);
chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(-7.5, 26.5, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  if (DistanceMogo.get() < 30) basketMove(StateBasket::SCORE);
delay(250);

  while (basketState != 0) delay(10);

  chassis.moveToPoint(-8, 42, 5000, {.maxSpeed = 60});
}

void rrAWP() { chassis.setPose(0, -7, 0);
  spinFor(StateIntake::ONE);

  chassis.moveToPoint(0, 20, largeDriveTimeout, {.maxSpeed = 40});

  chassis.turnToHeading(-90, turnTimeout);
chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(17, 26.5, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  if (DistanceMogo.get() < 30) {
    while (intakeState != 0) delay(10);
    basketMove(StateBasket::SCORE);
    delay(200);

    chassis.turnToHeading(-33.5, turnTimeout);
    chassis.waitUntilDone();

    while (basketState != 0) delay(10);

    spinFor(StateIntake::ONE);

    chassis.moveToPoint(8.5, 39, 800, {.minSpeed = 90});
    chassis.waitUntilDone();

    chassis.moveToDist(-6, smallDriveTimeout);
    chassis.waitUntilDone();

    chassis.turnToHeading(45, turnTimeout);
    chassis.waitUntilDone();

    while (intakeState != 0) delay(10);

    basketMove(StateBasket::SCORE);
    delay(200);

    chassis.moveToPoint(15, 42.5, 1500);
  } else {
    chassis.turnToHeading(10, turnTimeout);
    chassis.waitUntilDone();

    chassis.moveToDist(20, 5000, {.maxSpeed = 60});
  }
}

void brAWP() { chassis.setPose(0, -7, 0);
  spinFor(StateIntake::ONE);

  chassis.moveToPoint(0, 20, largeDriveTimeout, {.maxSpeed = 40});

  chassis.turnToHeading(90, turnTimeout);
chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(-17, 26.5, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  if (DistanceMogo.get() < 30) {
    while (intakeState != 0) delay(10);
    basketMove(StateBasket::SCORE);
    delay(200);

    chassis.turnToHeading(33.5, turnTimeout);
    chassis.waitUntilDone();

    while (basketState != 0) delay(10);

    spinFor(StateIntake::ONE);

    chassis.moveToPoint(-8.5, 39, 800, {.minSpeed = 90});
    chassis.waitUntilDone();

    chassis.moveToDist(-6, smallDriveTimeout);
    chassis.waitUntilDone();

    chassis.turnToHeading(-45, turnTimeout);
    chassis.waitUntilDone();

    while (intakeState != 0) delay(10);

    basketMove(StateBasket::SCORE);
    delay(200);

    chassis.moveToPoint(-15, 42.5, 1500);
  } else {
    chassis.turnToHeading(-10, turnTimeout);
    chassis.waitUntilDone();

    chassis.moveToDist(20, 5000, {.maxSpeed = 60});
  }
}

void bgAWP() { chassis.setPose(0, -7, 0);
  spinFor(StateIntake::ONE);

  chassis.moveToPoint(-12.25, 20, midDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(-90, turnTimeout);
chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(7.5, 26.5, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  if (DistanceMogo.get() < 30) basketMove(StateBasket::SCORE);
delay(250);

  while (basketState != 0) delay(10);

  chassis.moveToPoint(8, 42, 5000, {.maxSpeed = 60});
}