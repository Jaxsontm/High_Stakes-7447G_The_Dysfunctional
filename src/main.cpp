#include "main.h"


void initialize() {
  chassis.calibrate();
  //pros::lcd::initialize();
  pros::Task auton_selector_task(selector);
  Intake.set_brake_mode(pros::MotorBrake::coast);
  basket.set_brake_mode(MotorBrake::brake);
  lift.set_brake_mode(MotorBrake::hold);
  setLiftPos(liftPos::RESET);
  pros::Task mogo_machine(state_machine_mogo);
  pros::Task intake_machine(state_machine_intake);
  pros::Task basket_machine(basketControl);
  pros::Task lift_machine(liftMachine);
  Task screenTask([&]() {
    lemlib::Pose pose(0, 0, 0);
    while (true) {
      // print robot location to the brain screen
      lcd::print(0, "X: %f", chassis.getPose().x);         // x
      lcd::print(1, "Y: %f", chassis.getPose().y);         // y
      lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
      pros::lcd::print(4, "Lift %f", rotFinder.get_position() / 100.0);

      // delay to save resources
      delay(50);
    }
  });
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  basketMove(StateBasket::RESET);
  switch (autonSelection) {
  case 0:
    redGoal();
    break;
  case 1:
    redRing();
    break;
  case 2:
    redSolo();
    break;
  case 3:
    redGoalElim();
    break;
  case 4:
    redRingElim();
    break;
  case 5:
    blueGoal();
    break;
  case 6:
    blueRing();
    break;
  case 7:
    blueSolo();
    break;
  case 8:
    blueRingElim();
    break;
  case 9:
    blueGoalElim();
    break;
  case 10:
    rgAWP();
    break;
  case 11:
    rrAWP();
    break;
  case 12:
    brAWP();
    break;
  case 13:
    bgAWP();
    break;
  default:
    Skills();
    break;
  }
}

void opcontrol() {
  basket.set_brake_mode(MotorBrake::brake);
  Intake.set_brake_mode(pros::MotorBrake::coast);
  Intake.brake();
  pros::Task display(text);
  while (true) {
    intakeControl();
    mogoToggle();
    doinkerToggle();
    liftDriver();
    basketDriver();
    tank();

    text();

    // delay to save resources
    pros::delay(20);
  }
}