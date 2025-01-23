#include "subsystemsHeaders/Lift.hpp"

///////// global
Motor lift(7, MotorGearset::green, MotorEncoderUnits::degrees);

Rotation rotFinder(4);

adi::Button liftLimit('G');

bool score = false;
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

int scaleVelo(int velo, int scale) {
  if (scale == 1) {
    if (velo > 12000) {
      return 12000;
    } else if (velo < -12000) {
      return -12000;
    } else {
      return velo;
    }
  } else if (scale == 2) {
    if (velo > 100) {
      return 100;
    } else if (velo < -100) {
      return -100;
    } else {
      return velo;
    }
  } else if (scale == 3) {
    if (velo > 127) {
      return 127;
    } else if (velo < -127) {
      return -127;
    } else {
      return velo;
    }
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

//* PD Loop
void liftController(double target, int timeout) {
  double kP = 2.2, kFF = 0.25;
  double curPos = rotFinder.get_position() / 100.0; 
  double error = target - curPos; 
  double υTotal;
  while (fabs(error) > 1 && timeout > 0) { 
    curPos = rotFinder.get_position() / 100.0;
    error = target - curPos;

    double υP = kP * error;
    double υFF = kFF * target;

    υTotal = (υP + υFF) * 100;

    scaleVelo(υTotal, 1);

    lift.move_voltage(υTotal);

    timeout -= 10;
    pros::delay(10);
  }
  lift.move_voltage(0);
}


//* Fuzzy-PID Loop
/*double triFuzzifier(double x, double a, double b, double c) {
    if (x <= a || x >= c) return 0;
    else if (x <= b) return (x - a) / (b - a);
    else return (c - x) / (c - b);
}

void fuzzyAdjust(double e, double Δe, double &kP, double &kI, double &kD) {
  double NL = triFuzzifier(e, -400, -200, 0);
  double NS = triFuzzifier(e, -200, -100, 0);
  double Z = triFuzzifier(e, -1, 0, 1);
  double PS = triFuzzifier(e, 0, 100, 200);
  double PL = triFuzzifier(e, 0, 200, 400);

  double N_Δe = triFuzzifier(Δe, -200, -100, 0);
  double Z_Δe = triFuzzifier(Δe, -5, 0, 5);
  double P_Δe = triFuzzifier(Δe, 0, 100, 200);

//! Weighted Average and Weighted Sum hybrid defuzzification
//! Favors Sum for fast actions in big errors
//! Favors Average for smooth actions in small errors
  double K = 20;
  double α = fabs(e) / fabs(e) + K;

  double sumMemb = NL + NS + Z + PS + PL;
  double sumKP = (PL * 10.0 + PS * 8.5 + Z * 1.0 + NS * 8 + NL * 9.2);
  double sumKI = (PL * 0.1 + PS * 0.02 + Z * 0.0 + NS * 0.01 + NL * 0.02);
  double sumKD = (PL * 0.3 + PS * 0.2 + Z * 0.1 + NS * 0.15 + NL * 0.2);
  double weightAvgKP = sumKP / sumMemb;
  double weightAvgKI = sumKI / sumMemb;
  double weightAvgKD = sumKD / sumMemb;
  double weightSumKP = sumKP + (P_Δe * 1.2 + Z_Δe * 1.0 + N_Δe * 0.8);
  double weightSumKI = sumKI + (P_Δe * 0.05 + Z_Δe * 0.03 + N_Δe * 0.01);
  double weightSumKD = sumKD + (P_Δe * 0.25 + Z_Δe * 0.15 + N_Δe * 0.3);

  kP = (1 - α) * weightAvgKP + α * weightSumKP;

  kI = (1 - α) * weightAvgKI + α * weightSumKI;

  kD = (1 - α) * weightAvgKD + α * weightSumKD;
}

void liftController(double target) {
  double kP = 0, kI = 0, kD = 0;

  double error = target, prevError = 0.0, integral = 0.0, derivative = 0.0;

  while (fabs(error) > 2) {
    double currPos = lift.get_position();
    error = target - currPos;
    double Δerror = error - prevError;

    fuzzyAdjust(error, Δerror, kP, kI, kD);

    integral += error;
    double derivative = Δerror;
    double output = kP * error + kI * integral + kD * derivative;

    scaleVelo(output * 100, 1);

    lift.move_voltage(output);

    prevError = error;
    pros::delay(10);
  }
  lift.move_voltage(0);
}*/



void liftMachine() {
  while (true) {
    switch (currentPos) {
      case liftPos::autoLOAD:
        /*liftPosition = 1;
        lift.set_brake_mode(MotorBrake::hold);
        if (once == true) {
          liftController(95, 1);
          once = !once;
        } else {
          liftController(95, 1);
        }
        delay(250);
        basketMove(StateBasket::LOAD);
        delay(500);
        liftController(500);
        delay(250);
        currentPos = liftPos::RESET;*/
      break;
      case liftPos::LOAD:
        liftPosition = 1;
        lift.set_brake_mode(MotorBrake::hold);
        liftController(27.5, 350);
        if (score == true) delay(300);
        basketMove(StateBasket::LOAD);
        score = false;
        currentPos = liftPos::STOP;
      break;
      case liftPos::SCORE:
        liftPosition = 2;
        liftController(100, 600);
        lift.set_brake_mode(MotorBrake::hold);
        score = true;
        currentPos = liftPos::STOP;
      break;
      case liftPos::RESET:
        liftPosition = 3;
        while (liftLimit.get_value() == 0) lift.move(-127);
        lift.set_brake_mode(MotorBrake::brake);
        lift.brake();
        score = false;
        currentPos = liftPos::STOP;
      break;
      case liftPos::STOP:
        liftPosition = 0;
        lift.brake();
      break;
      }
    delay(10);
  }
}
//////// Driver Control
void liftDriver() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT) && liftPosition != 2) {
    setLiftPos(liftPos::LOAD);
  } else if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT) && liftPosition == 2) {
    setLiftPos(liftPos::RESET);
  }
  
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) setLiftPos(liftPos::SCORE);

  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) setLiftPos(liftPos::RESET);
}
