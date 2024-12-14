#include "lemlib/chassis/chassis.hpp"
#include "subsystemsHeaders/Lift.hpp"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "subsystemsHeaders/mogo.hpp"
#include "subsystemsHeaders/intake.hpp"
///////////////////////////////////////////////////////////////////////////////////////////
//!  General Params
float earlyExitRange = 4;
float doinkerDelay = 150;
float goalGrabMaxSpeed = 50;
float poleMaxSpeed = 50;
float normalMinSpeed = 60;
float normalMaxSpeed = 80;
float turnTimeout = 650;
float swingTimeout = 900;
float smallDriveTimout = 750;
float midDriveTimeout = 1200;
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
/*void redRight() { chassis.setPose(0, 0, 180);
	chassis.moveToPose(7.5, 37, -170, 1400, {.forwards = false, .lead = .3, .minSpeed = goalRushSpeed, .earlyExitRange = earlyExitRange});
chassis.waitUntilDone();

			doinker.set_value(true);

delay(doinkerDelay);

	chassis.moveToPoint(4, 30, 750);

			request_new_state_mogo(StateMogo::LOCATE);

			doinker.set_value(false);

	chassis.moveToPoint(8, 40, 750, {.maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

	chassis.turnToPoint(17, 35, 500, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});

		how_many_rings(StateIntake::ONE)

	chassis.moveToPoint(17, 35, 750);
chassis.waitUntilDone();

	chassis.turnToHeading(0, 850);

		basketScore(1000);

	chassis.moveToPose(17, -2, 0, 1200, {.forwards = false, .lead = 0});
chassis.waitUntilDone();

			request_new_state_mogo(StateMogo::RELEASE);

	chassis.moveToPoint(17, 4, 500, {.minSpeed = normalMinSpeed, .earlyExitRange = earlyExitRange});

	chassis.turnToHeading(135, 500);
chassis.waitUntilDone();

	chassis.moveToPose(-2, 17, 135, 1200);
chassis.waitUntilDone();

	chassis.moveToPose(33, 10, 180, 1500);

		how_many_rings(StateIntake::ONE)

	chassis.moveToPoint(33, -3, 600);

	chassis.swingToHeading(135, lemlib::DriveSide::LEFT, 650);
chassis.waitUntilDone();

	chassis.moveToPose(-22, 21, -62, midDriveTimeout, {.forwards = false, .lead = 0, .maxSpeed = normalMaxSpeed});
chassis.waitUntil(waitUntil);
chassis.cancelMotion();

	chassis.moveToPose(-22, 21, -62, midDriveTimeout, {.lead = 0, .maxSpeed = poleMaxSpeed});
}*/
void redRight() { chassis.setPose(0, 0, 90);
			extender.set_value(true);

			doinker.set_value(true);
delay(doinkerDelay);

	chassis.swingToHeading(135, lemlib::DriveSide::LEFT, swingTimeout);
chassis.waitUntilDone();

			doinker.set_value(false);
delay(500);
			
	chassis.turnToHeading(90, turnTimeout);
chassis.waitUntilDone();
	
	chassis.moveToPose(-15.5, 0, 90, midDriveTimeout, {.forwards = false, .minSpeed = normalMaxSpeed});
chassis.waitUntilDone();
	
	chassis.turnToHeading(180, turnTimeout, {.maxSpeed = static_cast<int>(normalMinSpeed)});
chassis.waitUntilDone();
	
	chassis.moveToPoint(-8, -2, midDriveTimeout, {.maxSpeed = normalMaxSpeed});
chassis.waitUntilDone();

			extender.set_value(false);
delay(100);

			Mogo.set_value(true);
			
	chassis.turnToHeading(-145, turnTimeout);
	
			extender.set_value(true);

			request_new_state_mogo(StateMogo::LOCATE);

	chassis.moveToPose(17, 33, -150, largeDriveTimeout, {.forwards = false, .lead = 0.1, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

		how_many_rings(StateIntake::ONE);
		
	chassis.turnToHeading(90, turnTimeout);
	chassis.waitUntilDone();
	
	chassis.moveToPoint(24, 32, midDriveTimeout);
chassis.waitUntilDone();

delay(500);

		basketScore(1000);

	chassis.turnToHeading(-110, turnTimeout);
chassis.waitUntilDone();

		how_many_rings(StateIntake::ONE);

	chassis.moveToPoint(-2, 26, largeDriveTimeout, {.maxSpeed = 100});
chassis.waitUntilDone();

delay(500);
		
	chassis.swingToHeading(-10, lemlib::DriveSide::LEFT, turnTimeout);
chassis.waitUntilDone();

	chassis.moveToPoint(-2, 33, midDriveTimeout);
	
		basketScore(1000);
		
delay(500);
			
		basketReset();
}
///////////////////////////////////////////////////////////////////////////////////////////
/*void redLeft() { chassis.setPose(0, 0, 0);
	chassis.turnToHeading(15, turnTimeout);

			doinker.set_value(true);

delay(doinkerDelay);

	chassis.turnToHeading(170, turnTimeout);

		how_many_rings(StateIntake::ONE)

	chassis.turnToHeading(0, turnTimeout);

	chassis.moveToPose(6, -17, -35, smallDriveTimout, {.forwards = false, .lead = 0, .minSpeed = normalMaxSpeed});
chassis.waitUntil(waitUntil);
chassis.cancelMotion();

			request_new_state_mogo(StateMogo::LOCATE);

	chassis.moveToPose(6, -17, -35, smallDriveTimout, {.forwards = false, .lead = 0, .maxSpeed = goalGrabMaxSpeed});

	chassis.turnToHeading(140, turnTimeout, {.maxSpeed = 70});

		basketScore(1000);

		how_many_rings(StateIntake::TWO)

	chassis.moveToPose(22, -41, 140, midDriveTimeout, {.lead = 0, .minSpeed = normalMinSpeed, .earlyExitRange = earlyExitRange});

	chassis.swingToHeading(90, lemlib::DriveSide::LEFT, swingTimeout);
chassis.waitUntilDone();

	chassis.moveToPose(38, -43, 90, midDriveTimeout, {.lead = 0, .maxSpeed = normalMaxSpeed});

delay(250);

		basketScore(1000);

	chassis.turnToPoint(35, -27, turnTimeout);

		how_many_rings(StateIntake::ONE)

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
}*/
void redLeft() { chassis.setPose(0, 0, -90);
			extender.set_value(true);
delay(doinkerDelay);
	
	chassis.moveToPose(15.5, 0, -90, midDriveTimeout, {.forwards = false, .minSpeed = normalMaxSpeed});
chassis.waitUntilDone();
	
	chassis.turnToHeading(-180, turnTimeout, {.maxSpeed = static_cast<int>(normalMinSpeed)});
chassis.waitUntilDone();
	
	chassis.moveToPoint(6.5, -3, midDriveTimeout, {.maxSpeed = normalMaxSpeed});
chassis.waitUntilDone();

			extender.set_value(false);
delay(100);

			Mogo.set_value(true);
			
	chassis.turnToHeading(145, turnTimeout);
	
			extender.set_value(true);
			
			request_new_state_mogo(StateMogo::LOCATE);

	chassis.moveToPose(-13, 32, 150, largeDriveTimeout - 500, {.forwards = false, .lead = 0.1, .maxSpeed = goalGrabMaxSpeed + 10});
chassis.waitUntilDone();

		how_many_rings(StateIntake::TWO);
		
	chassis.turnToHeading(-30, turnTimeout);
chassis.waitUntilDone(); 

	chassis.moveToPose(-24, 41.5, -30, midDriveTimeout, {.lead = 0, .maxSpeed = normalMaxSpeed});
chassis.waitUntilDone();

		basketReset();

	chassis.turnToHeading(-60, turnTimeout);
chassis.waitUntilDone();

	chassis.moveToPose(-100, 48.5, -89, 750, {.lead = 0.5});
chassis.waitUntilDone();

delay(1500);

		basketScore(1000);
		
	chassis.turnToHeading(165, turnTimeout, {.maxSpeed = 70});
	
		basketReset();
chassis.waitUntilDone();	

		how_many_rings(StateIntake::ONE);

	chassis.moveToPoint(-38, 38, midDriveTimeout, {.maxSpeed = poleMaxSpeed});
chassis.waitUntilDone();

	chassis.turnToHeading(-265, turnTimeout);
chassis.waitUntilDone();

		how_many_rings(StateIntake::REV);

		basketScore(1000);
		
	chassis.turnToHeading(45, turnTimeout);
chassis.waitUntilDone();

	chassis.moveToPoint(-0, 48, midDriveTimeout, {.maxSpeed = poleMaxSpeed + 20});
chassis.waitUntilDone();

			request_new_state_mogo(StateMogo::RELEASE);
			
		basketReset();
		
			extender.set_value(false);
				
}
///////////////////////////////////////////////////////////////////////////////////////////
/*void redSolo() { chassis.setPose(0, 0, 180); 
		how_many_rings(StateIntake::ONE)

	chassis.moveToPoint(0, 19.5, midDriveTimeout);
chassis.waitUntilDone();

			request_new_state_mogo(StateMogo::LOCATE);

	chassis.moveToPose(17.5, 18, 135, midDriveTimeout, {.forwards = false});

	chassis.turnToHeading(-15, turnTimeout);
chassis.waitUntilDone();

	chassis.moveToPose(11, 41, -15, smallDriveTimout);

	chassis.swingToHeading(-90, lemlib::DriveSide::LEFT, swingTimeout);
chassis.waitUntilDone();

		how_many_rings(StateIntake::TWO)

	chassis.moveToPose(3, 42.5, -90, midDriveTimeout, {.maxSpeed = normalMinSpeed});
chassis.waitUntilDone();

			request_new_state_mogo(StateMogo::RELEASE);

	chassis.moveToPose(40.5, 9.5, -50, midDriveTimeout);

	chassis.turnToHeading(110, turnTimeout);

	chassis.moveToPose(64.5, 17.5, 110, midDriveTimeout);

			request_new_state_mogo(StateMogo::LOCATE);

	chassis.turnToHeading(140, turnTimeout);
chassis.waitUntilDone();

	while (DistanceMogo.get() > 70) {
		DTLeft.move(60), DTRight.move(60);
	}

	chassis.moveToPose(103.5, -12, 90, largeDriveTimeout);
chassis.waitUntil(20);

		how_many_rings(StateIntake::ONE)
chassis.waitUntilDone();

	chassis.swingToHeading(-135, lemlib::DriveSide::RIGHT, swingTimeout);
chassis.waitUntilDone();

	chassis.moveToPoint(-6, 103.5, smallDriveTimout);

	chassis.turnToHeading(-15, turnTimeout);
chassis.waitUntil(100);

			request_new_state_mogo(StateMogo::RELEASE);

	chassis.turnToHeading(180, turnTimeout);
chassis.waitUntilDone();

	chassis.moveToPose(100, 41, 160, midDriveTimeout, {.lead = 0.3});
chassis.waitUntil(40);
chassis.cancelMotion();

			request_new_state_mogo(StateMogo::LOCATE);

	chassis.moveToPose(100, 41, 145, midDriveTimeout, {.lead = 0.3, .maxSpeed = goalGrabMaxSpeed});

		how_many_rings(StateIntake::TWO)

	chassis.moveToPose(97.5, 35, -160, smallDriveTimout);

	chassis.turnToPoint(29, 9, turnTimeout, {.minSpeed = static_cast<int>(normalMinSpeed), .earlyExitRange = earlyExitRange});

	chassis.moveToPoint(29, 9, midDriveTimeout);

		basketScore(1000);

	chassis.turnToPoint(54, 20.5, turnTimeout);

	chassis.moveToPoint(54, 20.5, midDriveTimeout, {.maxSpeed = poleMaxSpeed});
}*/
void redSolo() { chassis.setPose(0, 0, -90);
	chassis.moveToPoint(-6.5, 0, smallDriveTimout);
chassis.waitUntilDone();

		chassis.swingToHeading(180, lemlib::DriveSide::LEFT, swingTimeout);
chassis.waitUntilDone();
	
	chassis.moveToPose(-15, 7, 180, smallDriveTimout, {.forwards = false});
chassis.waitUntilDone();
}
///////////////////////////////////////////////////////////////////////////////////////////
void redRightElim() { chassis.setPose(0, 0, 0); 
	chassis.moveToPose(6.5, -40.5, -30, midDriveTimeout, {.forwards = false, .lead = 0.2});
chassis.waitUntil(20);

			request_new_state_mogo(StateMogo::LOCATE);
chassis.waitUntilDone();

	chassis.turnToHeading(20, turnTimeout);
chassis.waitUntilDone();

		how_many_rings(StateIntake::ONE);

	chassis.moveToPoint(8.5, -35.5, smallDriveTimout);
chassis.waitUntilDone();

		basketScore(1000);

	chassis.turnToHeading(155, turnTimeout);

			request_new_state_mogo(StateMogo::RELEASE);

	chassis.moveToPoint(-4, -10, midDriveTimeout);
chassis.waitUntilDone();

	chassis.swingToPoint(29.5, -17, lemlib::DriveSide::LEFT, swingTimeout, {.forwards = false, .minSpeed = 30, .earlyExitRange = 20});

			request_new_state_mogo(StateMogo::RELEASE);

	chassis.moveToPose(29.5, -17, -30, midDriveTimeout, {.forwards = false});
chassis.waitUntil(30);
chassis.cancelMotion();

	chassis.moveToPose(29.5, -17, -30, midDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

	chassis.moveToPoint(3.5, 3.5, midDriveTimeout);

			request_new_state_mogo(StateMogo::RELEASE);

	chassis.swingToHeading(110, lemlib::DriveSide::RIGHT, swingTimeout);

			doinker.set_value(true);
delay(doinkerDelay);

	chassis.turnToHeading(30, turnTimeout);

	doinker.set_value(false);
}
///////////////////////////////////////////////////////////////////////////////////////////
void redLeftElim() { chassis.setPose(0, 0, 0); }
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
//void blueRight() { chassis.setPose(-0, 0, -180); }
void blueRight() { chassis.setPose(0, 0, 90);
			extender.set_value(true);
delay(doinkerDelay);
	
	chassis.moveToPose(-15.5, 0, 90, midDriveTimeout, {.forwards = false, .minSpeed = normalMaxSpeed});
chassis.waitUntilDone();
	
	chassis.turnToHeading(180, turnTimeout, {.maxSpeed = static_cast<int>(normalMinSpeed)});
chassis.waitUntilDone();
	
	chassis.moveToPoint(-6.5, -3, midDriveTimeout, {.maxSpeed = normalMaxSpeed});
chassis.waitUntilDone();

			extender.set_value(false);
delay(100);

			Mogo.set_value(true);
			
	chassis.turnToHeading(-145, turnTimeout);
	
			extender.set_value(true);
			
			request_new_state_mogo(StateMogo::LOCATE);

	chassis.moveToPose(13, 32, -150, largeDriveTimeout - 500, {.forwards = false, .lead = 0.1, .maxSpeed = goalGrabMaxSpeed + 10});
chassis.waitUntilDone();

		how_many_rings(StateIntake::TWO);
		
	chassis.turnToHeading(30, turnTimeout);
chassis.waitUntilDone(); 

	chassis.moveToPose(24, 41.5, 30, midDriveTimeout, {.lead = 0, .maxSpeed = normalMaxSpeed});
chassis.waitUntilDone();

		basketReset();

	chassis.turnToHeading(60, turnTimeout);
chassis.waitUntilDone();

	chassis.moveToPose(100, 48.5, 89, 750, {.lead = 0.5});
chassis.waitUntilDone();

delay(1500);

		basketScore(1000);
		
	chassis.turnToHeading(-165, turnTimeout, {.maxSpeed = 70});
	
		basketReset();
chassis.waitUntilDone();	

		how_many_rings(StateIntake::ONE);

	chassis.moveToPoint(38, 38, midDriveTimeout, {.maxSpeed = poleMaxSpeed});
chassis.waitUntilDone();

	chassis.turnToHeading(265, turnTimeout);
chassis.waitUntilDone();

		how_many_rings(StateIntake::REV);

		basketScore(1000);
		
	chassis.turnToHeading(-45, turnTimeout);
chassis.waitUntilDone();

	chassis.moveToPoint(0, 48, midDriveTimeout, {.maxSpeed = poleMaxSpeed + 20});
chassis.waitUntilDone();

			request_new_state_mogo(StateMogo::RELEASE);
			
		basketReset();
		
			extender.set_value(false);
}

///////////////////////////////////////////////////////////////////////////////////////////
//void blueLeft() { chassis.setPose(-0, 0, -0); }
void blueLeft() { chassis.setPose(-0, 0, -90);
			extender.set_value(true);

			doinker.set_value(true);
delay(doinkerDelay);

	chassis.swingToHeading(-135, lemlib::DriveSide::RIGHT, swingTimeout);
chassis.waitUntilDone();

			doinker.set_value(false);
delay(500);
			
	chassis.turnToHeading(-90, turnTimeout);
chassis.waitUntilDone();
	
	chassis.moveToPose(15.5, 0, -90, midDriveTimeout, {.forwards = false, .minSpeed = normalMaxSpeed});
chassis.waitUntilDone();
	
	chassis.turnToHeading(-180, turnTimeout, {.maxSpeed = static_cast<int>(normalMinSpeed)});
chassis.waitUntilDone();
	
	chassis.moveToPoint(8, -2, midDriveTimeout, {.maxSpeed = normalMaxSpeed});
chassis.waitUntilDone();

			extender.set_value(false);
delay(100);

			Mogo.set_value(true);
			
	chassis.turnToHeading(145, turnTimeout);
	
			extender.set_value(true);

			request_new_state_mogo(StateMogo::LOCATE);

	chassis.moveToPose(-17, 33, 150, largeDriveTimeout, {.forwards = false, .lead = 0.1, .maxSpeed = goalGrabMaxSpeed});
chassis.waitUntilDone();

		how_many_rings(StateIntake::ONE);
		
	chassis.turnToHeading(-90, turnTimeout);
	chassis.waitUntilDone();
	
	chassis.moveToPoint(-24, 32, midDriveTimeout);
chassis.waitUntilDone();

delay(500);

		basketScore(1000);

	chassis.turnToHeading(110, turnTimeout);
chassis.waitUntilDone();

		how_many_rings(StateIntake::ONE);

	chassis.moveToPoint(2, 26, largeDriveTimeout, {.maxSpeed = 100});
chassis.waitUntilDone();

delay(500);
		
	chassis.swingToHeading(10, lemlib::DriveSide::LEFT, turnTimeout);
chassis.waitUntilDone();

	chassis.moveToPoint(2, 33, midDriveTimeout);
	
		basketScore(1000);
		
delay(500);
			
		basketReset();
}
///////////////////////////////////////////////////////////////////////////////////////////
void blueSolo() { chassis.setPose(-0, 0, -180); }
///////////////////////////////////////////////////////////////////////////////////////////
void blueRightElim() { chassis.setPose(-0, 0, -0); }
///////////////////////////////////////////////////////////////////////////////////////////
void blueLeftElim() { chassis.setPose(-0, 0, -0); }
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Skills() { chassis.setPose(0, 0, 180);
//!!! chassis.resetLocalPosition(); !!!//
			extender.set_value(true);

	chassis.moveToPose(0, -6, 180, midDriveTimeout, {.lead = 0});
chassis.waitUntilDone();

		basketReset();

			extender.set_value(false);
delay(50);

	chassis.moveToPose(0, 6.5, 180, midDriveTimeout, {.forwards = false, .lead = 0});
chassis.waitUntilDone();

			request_new_state_mogo(StateMogo::RELEASE);

	chassis.turnToHeading(270, turnTimeout);
chassis.waitUntilDone();

			request_new_state_mogo(StateMogo::LOCATE);

	chassis.moveToPoint(20.5, 3.5, largeDriveTimeout, {.forwards = false, .maxSpeed = goalGrabMaxSpeed - 10});
chassis.waitUntilDone();

		how_many_rings(StateIntake::ONE);
		
	chassis.turnToHeading(0, turnTimeout);
chassis.waitUntilDone();
	
	chassis.moveToPose(20, 20, -10, midDriveTimeout, {.lead = 0.4, .minSpeed = 70, .earlyExitRange = 2});
chassis.waitUntilDone();

delay(3000);
		basketScore(1000);

	chassis.turnToHeading(-35, turnTimeout);
chassis.waitUntilDone();

			request_new_state_mogo(StateMogo::RELEASE);
			
	chassis.moveToPoint(65, -13, largeDriveTimeout, {.forwards = false});
chassis.waitUntilDone();

	chassis.moveToPoint(58, -7.5, midDriveTimeout);
	
		basketReset();
chassis.waitUntilDone();

	chassis.turnToHeading(90, turnTimeout);
chassis.waitUntilDone();

	chassis.moveToPoint(-30, -5, largeDriveTimeout);
chassis.waitUntilDone();
	
	chassis.moveToPose(-95, -65, -120, largeDriveTimeout);
chassis.waitUntilDone();

	chassis.moveToPoint(-40, 0, midDriveTimeout, {.forwards = false});
}
