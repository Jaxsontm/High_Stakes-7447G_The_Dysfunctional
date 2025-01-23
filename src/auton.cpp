#include "auton.h"
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
float goalRushSpeed = 127;

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
void redGoal() { chassis.setPose(0,0,180);
  doinker.set_value(true);

  chassis.moveToPoint(9, 33, midDriveTimeout, {.forwards = false, .minSpeed = goalRushSpeed});
  chassis.waitUntilDone();

  doinker.set_value(false);

  chassis.moveToDist(12, smallDriveTimeout);
}
void redRing() { chassis.setPose(-0, 0, 90);
  spinFor(StateIntake::REV);
  
  chassis.moveToPoint(6, 0, smallDriveTimeout);
  chassis.waitUntilDone();

  chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 700);
chassis.waitUntilDone();

  chassis.moveToPoint(16, -6, smallDriveTimeout, {.forwards = false});
chassis.waitUntil(2.5);

  basketMove(StateBasket::SCORE);
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

  chassis.turnToHeading(-90, 800);
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
  delay(300);

  chassis.moveToDist(-6, smallDriveTimeout);

  chassis.turnToHeading(-35, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToDist(11, smallDriveTimeout);
  chassis.waitUntilDone();
  delay(600);

  chassis.swingToHeading(60, lemlib::DriveSide::LEFT, swingTimeout);
  chassis.waitUntilDone();
  delay(100);

  basketMove(StateBasket::SCORE);

  chassis.moveToDist(18, smallDriveTimeout);
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

  chassis.moveToPoint(-16, -6, smallDriveTimeout, {.forwards = false});
chassis.waitUntil(2.5);

  basketMove(StateBasket::SCORE);
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

  chassis.moveToDist(12, smallDriveTimeout);
  chassis.waitUntilDone();
  delay(500);

  chassis.swingToHeading(-65, lemlib::DriveSide::RIGHT, swingTimeout);
  chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);

  chassis.moveToDist(18, smallDriveTimeout);
}
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

  chassis.moveToPoint(50, 38, midDriveTimeout, {.maxSpeed = skillsSpeed});
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

  chassis.moveToPoint(0, 61, largeDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(0, turnTimeout);
chassis.waitUntilDone();

chassis.setPose(0, 61, 0);

  chassis.turnToHeading(-55, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToDist(38, midDriveTimeout);
  chassis.waitUntilDone();

  chassis.turnToHeading(-130, turnTimeout);
  chassis.waitUntilDone();

  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToDist(-30, largeDriveTimeout, {.maxSpeed = goalGrabMaxSpeed});
  chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);
delay(250);

  while (basketState != 0) delay(10);

  chassis.swingToHeading(-60, lemlib::DriveSide::LEFT, swingTimeout);
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

  chassis.moveToDist(-12, smallDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(-165, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToDist(20, smallDriveTimeout);
chassis.waitUntilDone();

  chassis.turnToHeading(45, turnTimeout);
chassis.waitUntilDone();

  setLiftPos(liftPos::SCORE);

  chassis.moveToDist(-38, 4000, {.maxSpeed = skillsSpeed});
}

void rgAWP() { chassis.setPose(0, -5.5, 0);
  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(0, -20.5, 800, {.forwards = false, .minSpeed = goalRushSpeed});

  chassis.moveToPoint(0, -38.5, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed + 5});
chassis.waitUntilDone();

  spinFor(StateIntake::ONE);

  chassis.turnToHeading(270, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToPoint(-19.5, -37.5, midDriveTimeout);
chassis.waitUntilDone();

while (intakeState != 0) delay(10);

  chassis.moveToPoint(0, -37.5, midDriveTimeout, {.forwards = false});
chassis.waitUntilDone();
  
delay(1000);

  basketMove(StateBasket::SCORE);
delay(500);

  chassis.turnToHeading(180, turnTimeout);
chassis.waitUntilDone();

  basketMove(StateBasket::RESET);

  chassis.moveToPoint(2, -50, midDriveTimeout, {.maxSpeed = poleMaxSpeed});
}

void rrAWP() { chassis.setPose(0, -5.5, 0);
  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(0, -20.5, 800, {.forwards = false, .minSpeed = goalRushSpeed});

  chassis.moveToPoint(0, -38.5, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed + 5});
chassis.waitUntilDone();

  spinFor(StateIntake::ONE);

  chassis.turnToHeading(270, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToPoint(19.5, -37.5, midDriveTimeout);
chassis.waitUntilDone();

while (intakeState != 0) delay(10);

  basketMove(StateBasket::SCORE);
delay(500);

  chassis.turnToHeading(180, turnTimeout);
chassis.waitUntilDone();

  spinFor(StateIntake::TWO);

  chassis.moveToPoint(20, -52, midDriveTimeout);
  chassis.waitUntilDone();
  delay(200);

  chassis.moveToDist(-6, smallDriveTimeout);
  chassis.waitUntilDone();

  chassis.turnToHeading(150, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToDist(9, smallDriveTimeout);
  chassis.waitUntilDone();
  delay(500);

  chassis.swingToHeading(-115, lemlib::DriveSide::LEFT, swingTimeout);
  chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);

  chassis.moveToDist(17.5, smallDriveTimeout);
}

void brAWP() { chassis.setPose(0, -5.5, 0);
  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(0, -20.5, 800, {.forwards = false, .minSpeed = goalRushSpeed});

  chassis.moveToPoint(0, -38.5, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed + 5});
chassis.waitUntilDone();

  spinFor(StateIntake::ONE);

  chassis.turnToHeading(270, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToPoint(-19.5, -37.5, midDriveTimeout);
chassis.waitUntilDone();

while (intakeState != 0) delay(10);

  basketMove(StateBasket::SCORE);
delay(500);

  chassis.turnToHeading(180, turnTimeout);
chassis.waitUntilDone();

  spinFor(StateIntake::TWO);

  chassis.moveToPoint(-20, -52, midDriveTimeout);
  chassis.waitUntilDone();
  delay(200);

  chassis.moveToDist(-6, smallDriveTimeout);
  chassis.waitUntilDone();

  chassis.turnToHeading(-150, turnTimeout);
  chassis.waitUntilDone();

  chassis.moveToDist(9, smallDriveTimeout);
  chassis.waitUntilDone();
  delay(500);

  chassis.swingToHeading(115, lemlib::DriveSide::RIGHT, swingTimeout);
  chassis.waitUntilDone();

  basketMove(StateBasket::SCORE);

  chassis.moveToDist(17.5, smallDriveTimeout);
}

void bgAWP() { chassis.setPose(0, -5.5, 0);
  request_new_state_mogo(StateMogo::LOCATE);

  chassis.moveToPoint(0, -20.5, 800, {.forwards = false, .minSpeed = goalRushSpeed});

  chassis.moveToPoint(0, -38.5, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed + 5});
chassis.waitUntilDone();

  spinFor(StateIntake::ONE);

  chassis.turnToHeading(90, turnTimeout);
chassis.waitUntilDone();

  chassis.moveToPoint(19.5, -37.5, midDriveTimeout);
chassis.waitUntilDone();

while (intakeState != 0) delay(10);

  chassis.moveToPoint(0, -37.5, midDriveTimeout, {.forwards = false});
chassis.waitUntilDone();
  
delay(1000);

  basketMove(StateBasket::SCORE);
delay(500);

  chassis.turnToHeading(180, turnTimeout);
chassis.waitUntilDone();

  basketMove(StateBasket::RESET);

  chassis.moveToPoint(-2, -50, midDriveTimeout, {.maxSpeed = poleMaxSpeed});
}