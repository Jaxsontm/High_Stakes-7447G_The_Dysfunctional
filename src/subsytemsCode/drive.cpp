#include "subsystemsHeaders/drive.hpp"
#include "lemlib/chassis/chassis.hpp"

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
										 0,     // integral gain (kI)
										 24,    // derivative gain (kD)
										 10,    // anti windup
										 1,     // small error range, in inches
										 100,   // small error range timeout, in milliseconds
										 3,    // large error range, in inches
										 300, // large error range timeout, in milliseconds
										 30     // maximum acceleration (slew)
		);

// angular motion controller
lemlib::ControllerSettings
		angularController(1.043, // proportional gain (kP)
											0,     // integral gain (kI)
											6,     // derivative gain (kD)
											5,     // anti windup
											1,     // small error range, in degrees
											100,   // small error range timeout, in milliseconds
											15,    // large error range, in degrees
											650,   // large error range timeout, in milliseconds
											30      // maximum acceleration (slew)
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

void lemlib::Chassis::drive(int Lspeed, int Rspeed, int timeout) {
  timeout /= 10;
  for (int i = 0; i < timeout; i++) {
    DTLeft.move(Lspeed), DTRight.move(Rspeed);
    delay(9);
  }
  DTLeft.brake(), DTRight.brake();
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

bool manual = true;
/*void manualToggle() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
    manual = !manual;
  }
    if (manual) {
      basket_machine -> suspend();
      intake_machine -> suspend();
      mogo_machine -> suspend();
      lift_load -> suspend();
    } else {
      basket_machine -> resume();
      intake_machine -> resume();
      mogo_machine -> resume();
      lift_load -> resume();
    }
}*/