#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "subsystemsHeaders/intake.hpp"
#include "subsystemsHeaders/mogo.hpp"
///////////////////////////////////////////////////////////////////////////////////////////
//!  General Params
float earlyExitRange = 4;
float doinkerDelay = 150;
float goalGrabMaxSpeed = 50;
float poleMaxSpeed = 70;
float normalMinSpeed = 60;
float normalMaxSpeed = 80;
float turnTimeout = 650;
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
void redGoal() { chassis.setPose(0, 0, 180);
  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(0, 30, midDriveTimeout,
                     {.forwards = false, .maxSpeed = goalRushSpeed});

  chassis.swingToHeading(152.5, lemlib::DriveSide::RIGHT,swingTimeout, {.minSpeed = 50, .earlyExitRange = 10});

  chassis.moveToPoint(-8, 43, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
  delay(250);

  while (basketState != 0) delay(5);

  chassis.turnToPoint(-10, 32, turnTimeout, {.minSpeed = 50, .earlyExitRange = 5});

  spinFor(StateIntake::ONE);
  
  chassis.moveToPoint(-11, 28, largeDriveTimeout, {.minSpeed = 60, .earlyExitRange = 5});
delay(500);
  
  chassis.moveToPose(0, 0, 220, midDriveTimeout, {.lead = 0.3});
chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
  delay(250);

  while (basketState != 0) delay(5);

  request_new_state_mogo(StateMogo::LOCATE);
}
///////////////////////////////////////////////////////////////////////////////////////////
void redRing() { chassis.setPose(0, 0, 90);
  spinFor(StateIntake::REV);

  chassis.moveToPoint(15.5, 0, smallDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(0, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToPoint(15.5, -2.5, smallDriveTimeout, {.forwards = false});
chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
delay(350);

  while (basketLimit.get_value() == 0) delay(10);

  spinFor(StateIntake::ONE);

  chassis.moveToPoint(-31.75, 35, smallDriveTimeout);
chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.turnToHeading(270, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToPose(-17.5, 35, 270, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  spinFor(StateIntake::TWO);

  chassis.turnToPoint(-25.75, 47, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToPoint(-25.75, 47, midDriveTimeout);
chassis.waitUntilDone();

  chassis.swingToPoint(-31, 48, lemlib::DriveSide::LEFT, swingTimeout);
chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
  delay(350);

  chassis.swingToPoint(4.5, 38, lemlib::DriveSide::LEFT, swingTimeout, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
chassis.waitUntilDone();

  chassis.moveToPoint(4.5, 38, largeDriveTimeout);
}
///////////////////////////////////////////////////////////////////////////////////////////
void redSolo() { chassis.setPose(0, 0, 270); 
		spinFor(StateIntake::ONE);

	chassis.moveToPoint(-8.75, 0, midDriveTimeout);
chassis.waitUntilDone();

			request_new_state_mogo(StateMogo::LOCATE);

	chassis.swingToHeading(210, lemlib::DriveSide::RIGHT, swingTimeout);
  chassis.waitUntilDone();

  chassis.moveToPose(3, 20.5, 210, midDriveTimeout, {.forwards = false});
  chassis.waitUntilDone();

  while (DistanceMogo.get() > 30) delay(10);

  basketMove(StateBasket::SCORE);
delay(250);

  while (basketLimit.get_value() == 0) delay(10);

  spinFor(StateIntake::ONE);

  chassis.moveToPose(-8.5, 26, 295, midDriveTimeout, {.lead = 0.4, .minSpeed = ringStackSpeed});
  chassis.waitUntilDone();

  chassis.turnToHeading(135, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToPoint(18.5, 0, midDriveTimeout, {.minSpeed = ringStackSpeed});
  chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::RELEASE);

  chassis.turnToHeading(90, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToPoint(31.5, 0, smallDriveTimeout);
  chassis.waitUntilDone();

  chassis.turnToHeading(0, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToPoint(31.5, -8, smallDriveTimeout, {.forwards = false});
  chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
  delay(250);

  while (basketLimit.get_value() == 0) delay(10);

  chassis.moveToPoint(31.5, -4.25, smallDriveTimeout);
  chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.turnToHeading(215, turnTimeout);

  chassis.moveToPose(49.5, 20, 215, largeDriveTimeout,
                     {.lead = 0, .maxSpeed = goalGrabMaxSpeed});
  chassis.waitUntilDone();

  spinFor(StateIntake::ONE);

  chassis.turnToHeading(70, turnTimeout, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
  chassis.waitUntilDone();

  chassis.moveToPose(73.25, 28, 72, midDriveTimeout, {.minSpeed = ringStackSpeed, .earlyExitRange = earlyExitRange});

  chassis.swingToHeading(0, lemlib::DriveSide::LEFT, swingTimeout, {.minSpeed = normalMinSpeed, .earlyExitRange = 10});

  chassis.turnToHeading(270, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToPose(41, 30, 265, largeDriveTimeout, {.maxSpeed = poleMaxSpeed});
}
///////////////////////////////////////////////////////////////////////////////////////////
void redGoalElim() { chassis.setPose(0, 0, 180); 
	request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPose(-10, 41, 150, midDriveTimeout,
                     {.forwards =  false, .lead = 0.25, .maxSpeed = goalRushSpeed, .earlyExitRange = 12});

  chassis.moveToPose(-10, 41, 145, smallDriveTimeout,
                     {.forwards = false, .lead = 0.15, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);

  chassis.turnToHeading(0, turnTimeout);
chassis.waitUntilDone();

  while (basketLimit.get_value() == 0) delay(10);

  chassis.moveToPoint(0, 0, midDriveTimeout, {.minSpeed = soloSpeed});

  request_new_state_mogo(StateMogo::RELEASE);
chassis.waitUntilDone();

  spinFor(StateIntake::ONE);

  chassis.turnToPoint(-9, 20.75, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToPoint(-9, 20.75, midDriveTimeout, {.minSpeed = ringStackSpeed});
chassis.waitUntilDone();

  while (basketCheck.get() > 200) delay(20);

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.swingToHeading(90, lemlib::DriveSide::RIGHT, swingTimeout);
chassis.waitUntilDone();

  chassis.moveToPose(-24, 26.75, 90, midDriveTimeout, {.maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
  delay(250);

  while (basketLimit.get_value() == 0) delay(10);
  
  chassis.turnToHeading(335, swingTimeout);
chassis.waitUntilDone();

  chassis.moveToPose(-9.5, -4.75, 325, midDriveTimeout, {.forwards = false, .maxSpeed = poleMaxSpeed});
chassis.waitUntilDone();
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

  chassis.drive(-65, -60, 200);
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
void blueRing() { chassis.setPose(-0, 0, -180); }
///////////////////////////////////////////////////////////////////////////////////////////
void blueGoal() { chassis.setPose(-0, 0, -0); }
///////////////////////////////////////////////////////////////////////////////////////////
void blueSolo() { chassis.setPose(-0, 0, -180); }
///////////////////////////////////////////////////////////////////////////////////////////
void blueRingElim() { chassis.setPose(-0, 0, -0); }
///////////////////////////////////////////////////////////////////////////////////////////
void blueGoalElim() { chassis.setPose(-0, 0, -0); }
///////////////////////////////////////////////////////////////////////////////////////////
void Skills() { chassis.setPose(0, 0, 0);
  //!!! chassis.resetLocalPosition(); !!!//
	/*chassis.moveToPose(0, -6, 180, midDriveTimeout, {.lead = 0});
chassis.waitUntilDone();

		

delay(50);

	chassis.moveToPose(0, 6.5, 180, midDriveTimeout, {.forwards = false, .lead = 0});
chassis.waitUntilDone();

			request_new_state_mogo(StateMogo::RELEASE);

	chassis.turnToHeading(270, turnTimeout);
chassis.waitUntilDone();

			request_new_state_mogo(StateMogo::LOCATE);

	chassis.moveToPoint(20.5, 3.5, largeDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed - 10});
chassis.waitUntilDone();

		spinFor(StateIntake::ONE);
		
	chassis.turnToHeading(0, turnTimeout);
chassis.waitUntilDone();
	
	chassis.moveToPose(20, 20, -10, midDriveTimeout, {.lead = 0.4, .minSpeed = 70, .earlyExitRange = 2});
chassis.waitUntilDone();

delay(3000);
		

	chassis.turnToHeading(-35, turnTimeout);
chassis.waitUntilDone();

			request_new_state_mogo(StateMogo::RELEASE);
			
	chassis.moveToPoint(65, -13, largeDriveTimeout, {.forwards = false});
chassis.waitUntilDone();

	chassis.moveToPoint(58, -7.5, midDriveTimeout);
	
chassis.waitUntilDone();

	chassis.turnToHeading(90, turnTimeout);
chassis.waitUntilDone();

	chassis.moveToPoint(-30, -5, largeDriveTimeout);
chassis.waitUntilDone();
	
	chassis.moveToPose(-95, -65, -120, largeDriveTimeout);
chassis.waitUntilDone();

	chassis.moveToPoint(-40, 0, midDriveTimeout, {.forwards = false});*/
}