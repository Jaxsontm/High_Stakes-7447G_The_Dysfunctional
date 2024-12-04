#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
#include "pros/rtos.hpp"
#include <cmath>
using namespace pros;

// controller
Controller controller(E_CONTROLLER_MASTER);

// Green Ziptie
MotorGroup DTLeft({-16, -15, 14}, MotorGearset::blue);
MotorGroup DTRight({20, 19, -18}, MotorGearset::blue);

Imu inertial_sensor(13);

/*MotorGroup DTLeft({11, -14, -5, 2}, MotorGearset::blue);
MotorGroup DTRight({-20, 18, 7, -3}, MotorGearset::blue);

Imu inertial_sensor(6);*/
//

// drivetrain settings
lemlib::Drivetrain drivetrain(
		&DTLeft,                    // left motor group
		&DTRight,                   // right motor group
		11,                         // 40 inch track width
		lemlib::Omniwheel::NEW_275, // using new 2.75" omnis
		450,                        // drivetrain rpm is 450
		2 // horizontal drift is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings
		linearController(11.95,    // proportional gain (kP)
										 0.00000001,     // integral gain (kI)
										 24,    // derivative gain (kD)
										 10,    // anti windup
										 1,     // small error range, in inches
										 100,   // small error range timeout, in milliseconds
										 30,    // large error range, in inches
										 30000, // large error range timeout, in milliseconds
										 10     // maximum acceleration (slew)
		);

// angular motion controller
lemlib::ControllerSettings
		angularController(1.043, // proportional gain (kP)
											0.0000000001,     // integral gain (kI)
											6,     // derivative gain (kD)
											2,     // anti windup
											1,     // small error range, in degrees
											500,   // small error range timeout, in milliseconds
											15,    // large error range, in degrees
											950,   // large error range timeout, in milliseconds
											5      // maximum acceleration (slew)
		);

// Rotation Sensors
Rotation horizontal_sensor(12);
Rotation vertical_sensor(1);

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_sensor,
																								lemlib::Omniwheel::NEW_2, 3.25);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_sensor,
																							lemlib::Omniwheel::NEW_275, 0.5);
// sensors for odometry
// note that in this example we use internal motor encoders (IMEs), so we don't
// pass vertical tracking wheels
lemlib::OdomSensors sensors(
		&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
		nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
		&horizontal_tracking_wheel, // horizontal tracking wheel 1
		nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a
						 // second one
		&inertial_sensor // inertial sensor
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController,
												sensors);

void lemlib::Chassis::drive(float distance, int timeout, driveParams params) {
	params.earlyExitRange = std::fabs(params.earlyExitRange);
	if (!this -> motionRunning) return;

	lateralPID.reset();
	lateralLargeExit.reset();
	lateralSmallExit.reset();
	distTraveled = 0;
	float startTime = pros::millis();
	lemlib::Pose lastPose = getPose();
	float target = distance;
	float changeDist = std::fabs(distance) * std::fabs(params.percentage/100);

	while (distTraveled < std::fabs(distance) && this -> motionRunning && 
				(lateralLargeExit.getExit() && lateralSmallExit.getExit()) && (pros::millis() - startTime) < timeout) {
		if (distTraveled < std::fabs(distance) - changeDist){
			distTraveled += chassis.getPose().distance(lastPose);
			lastPose = chassis.getPose();
			float distLeft = target - distTraveled;

			float lateralError = target;
			lateralLargeExit.update(lateralError);
			lateralSmallExit.update(lateralError);
			float lateralOut = lateralPID.update(lateralError);
			lateralOut = std::clamp(lateralOut, -params.maxSpeed, params.maxSpeed);

			if (params.forwards && lateralOut < fabs(params.minSpeed) && lateralOut > 0) lateralOut = fabs(params.minSpeed);
			if (!params.forwards && -lateralOut < fabs(params.minSpeed) && lateralOut < 0) lateralOut = -fabs(params.minSpeed);

			const float ratio = std::max(std::fabs(lateralOut), std::fabs(lateralOut)) / params.maxSpeed;
			if (ratio > 1) {
				lateralOut /= ratio;
			}

			DTLeft.move(lateralOut);
			DTRight.move(lateralOut);

			delay(10);
		} else if (distTraveled < distTraveled + changeDist){
			distTraveled += chassis.getPose().distance(lastPose);
			lastPose = chassis.getPose();
			float distLeft = target - distTraveled;

			float lateralError = target;
			lateralLargeExit.update(lateralError);
			lateralSmallExit.update(lateralError);
			float lateralOut = lateralPID.update(lateralError);
			lateralOut = std::clamp(lateralOut, -params.maxSpeed, params.maxSpeed);

			if (params.forwards && lateralOut < fabs(params.minSpeed) && lateralOut > 0) lateralOut = fabs(params.minSpeed);
			if (!params.forwards && -lateralOut < fabs(params.minSpeed) && lateralOut < 0) lateralOut = -fabs(params.minSpeed);

			const float ratio = std::max(std::fabs(lateralOut), std::fabs(lateralOut)) / params.maxSpeed;
			if (ratio > 1) {
				lateralOut /= ratio;
			}

			DTLeft.move(lateralOut / 2);
			DTRight.move(lateralOut / 2);
		}
	}
	DTLeft.move(0);
	DTRight.move(0);
	distTraveled = -1;
	this -> endMotion();
}

void tank() {
	int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

	chassis.tank(leftY, rightY);
}

void arcade() {
	int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

	chassis.arcade(leftY, rightX);
}