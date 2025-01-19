#include "subsystemsHeaders/Lift.hpp"
#include <cmath>

///////// global
Motor lift(-7, MotorGearset::green, MotorEncoderUnits::degrees);

Rotation rotFinder(4);

adi::Button liftLimit('G');

bool once = true;
////////Macro
int sgn(int x) {
  if (x > 0) {
    return 1;
  } else if (x < 0) {
    return -1;
  } else {
    return 0;
  }
}

int scaleVelo(int velo) {
  if (velo > 127) {
    return 127;
  } else if (velo < -127) {
    return -127;
  } else {
    return velo;
  }
}

liftPos currentPos = liftPos::STOP;

void setLiftPos(liftPos requestedPos) {
  if (requestedPos != currentPos) {
    currentPos = requestedPos;
  }
}

/*void liftController(double target) {
  double kP = 50;
  double kF = 1;
  double currPos = 0;
  double error = target;
  while (fabs(error) >= 1) {
    currPos = rotFinder.get_angle();
    error = target - (currPos / 100);

    double υP = kP * error;

    double υF = kF * target;

    double υOutput = υP + υF;

    scaleVelo(υOutput);

    lift.move(υOutput);

    delay(9);
  }
  lift.move(0);
}*/

/*double triangularMemb(double x, double a, double b, double c) {
    if (x <= a || x >= c) return 0;
    else if (x <= b) return (x - a) / (b - a);
    else return (c - x) / (c - b);
}

void fuzzyAdjust(double e, double Δe, double &kP, double &kI, double &kD) {
  double NL = triangularMemb(e, -400, -200, 0);
  double NS = triangularMemb(e, -200, -50, 0);
  double Z = triangularMemb(e, -10, 0, 10);
  double PS = triangularMemb(e, 0, 50, 200);
  double PL = triangularMemb(e, 0, 200, 400);

  double N_Δe = triangularMemb(Δe, -200, -100, 0);
  double Z_Δe = triangularMemb(Δe, -5, 0, 5);
  double P_Δe = triangularMemb(Δe, 0, 100, 200);

  kP = (PL * 2.0 + PS * 1.5 + Z * 1.0 + NS * 0.8 + NL * 1.2)
       + (P_Δe * 1.2 + Z_Δe * 1.0 + N_Δe * 0.8);

  kI = (PL * 0.1 + PS * 0.08 + Z * 0.05 + NS * 0.03 + NL * 0.02)
       + (P_Δe * 0.05 + Z_Δe * 0.03 + N_Δe * 0.01);

  kD = (PL * 0.3 + PS * 0.2 + Z * 0.1 + NS * 0.15 + NL * 0.2)
       + (P_Δe * 0.25 + Z_Δe * 0.15 + N_Δe * 0.3);
}

void liftController(double target) {
    double kP = 0, kI = 0, kD = 0;

    double error = target, prevError = 0.0, integral = 0.0;

    while (fabs(error) > 2) {
        double currPos = lift.get_position();
        error = target - currPos;
        double Δerror = error - prevError;

        fuzzyAdjust(error, Δerror, kP, kI, kD);

        integral += error * 0.01;
        double Δerivative = Δerror / 0.01;
        double output = kP * error + kI * integral + kD * Δerivative;

        lift.move_voltage(output * 12000 / 100);

        prevError = error;
        pros::delay(10);
    }
}*/

/*void liftController(float target) {
  float error = target - lift.get_position();
  while (fabs(error) >= 5) {
    if (fabs(error) > 2) {
      lift.move_voltage(12000 * sgn(error));
    } else {
      lift.move_voltage(0);
    }
    delay(10);
  }
}*/

void liftMachine() {
  while (true) {
    switch (currentPos) {
      case liftPos::autoLOAD:
        liftPosition = 1;
        lift.set_brake_mode(MotorBrake::hold);
        if (once == true) {
          liftController(95);
          once = !once;
        } else {
          liftController(95);
        }
        delay(250);
        basketMove(StateBasket::LOAD);
        delay(500);
        liftController(500);
        delay(250);
        currentPos = liftPos::RESET;
      break;
      case liftPos::LOAD:
        liftPosition = 1;
        lift.set_brake_mode(MotorBrake::hold);
        if (once == true) {
          liftController(90);
          once = !once;
        } else {
          liftController(93);
        }
        delay(250);
        basketMove(StateBasket::LOAD);
        currentPos = liftPos::STOP;
      break;
      case liftPos::SCORE:
        liftPosition = 2;
        liftController(250);
        lift.set_brake_mode(MotorBrake::hold);
        currentPos = liftPos::STOP;
      break;
      case liftPos::RESET:
        liftPosition = 3;
        while (liftLimit.get_value() == 0) lift.move(-60);
        lift.set_brake_mode(MotorBrake::brake);
        lift.brake();
        lift.tare_position();
        currentPos = liftPos::STOP;
      break;
      case liftPos::STOP:
        liftPosition = 0;
        lift.brake();
        lift.tare_position();
        rotFinder.reset_position();
      break;
      }
    delay(10);
  }
}
//////// Driver Control
void liftDriver() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) setLiftPos(liftPos::LOAD);
  
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) setLiftPos(liftPos::SCORE);

  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) setLiftPos(liftPos::RESET);

}