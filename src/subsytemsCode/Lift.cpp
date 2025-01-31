#include "subsystemsHeaders/Lift.hpp"

///////// global
Motor lift(7, MotorGearset::green, MotorEncoderUnits::degrees);

Rotation rotFinder(4);

adi::Button liftLimit('G');

pros::Task *lift_task = nullptr;
pros::Task *lift_PID_task = nullptr;
////////Macro
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

//* PF Loop
double Θ() {
  double raw = rotFinder.get_position() / 100.0;
  double start = 90 - 19;
  return raw - start;
}

void liftController(double target, int timeout, bool async = false) {
  if (async) {
    lift_PID_task = new pros::Task(liftController);
  }
  double kP = 1, kFF = 0.8;
  double error = target - Θ();
  double MAX_MV = 12000;
  double MAX_VELO = 100;
  double MAX_ACC = 1000;
  double prevVolt = 0;
  double υTotal;
  while (fabs(error) > 1 && timeout > 0) { 
    error = target - Θ();

    double υP = kP * error;

    double Θrad = Θ() * (M_PI / 180);
    double υFF = kFF * sin(Θrad);

    υTotal = (υP + υFF);

    double currVolt = lift.get_actual_velocity();

    if (fabs(υTotal) > MAX_VELO) {
      υTotal *= (MAX_VELO / fabs(currVolt));
    }

    υTotal = scaleVelo(υTotal, 1);

    double ΔV = υTotal - prevVolt;
    if (fabs(ΔV) > MAX_ACC) {
      υTotal = prevVolt + std::copysign(MAX_ACC, ΔV);
    }

    lift.move_voltage(υTotal);

    timeout -= 10;
    prevVolt = υTotal;
    pros::delay(10);
  }
  lift.move_voltage(0);
  if (async) {
    lift_PID_task->remove();
    delete lift_PID_task;
    lift_PID_task = nullptr;
  }
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
        liftPosition = 1;
        lift.set_brake_mode(MotorBrake::hold);
        liftController(27.5, 350);
        delay(250);
        basketMove(StateBasket::LOAD);
        delay(500);
        liftController(100, 600);
        delay(250);
        currentPos = liftPos::RESET;
      break;
      case liftPos::LOAD:
        liftPosition = 1;
        lift.set_brake_mode(MotorBrake::hold);
        liftController(29, 400, true);
        basketMove(StateBasket::LOAD);
        currentPos = liftPos::STOP;
      break;
      case liftPos::SCORE:
        liftPosition = 2;
        liftController(129, 700);
        lift.set_brake_mode(MotorBrake::hold);
        currentPos = liftPos::STOP;
      break;
      case liftPos::RESET:
        liftPosition = 3;
        while (liftLimit.get_value() == 0) lift.move(-127);
        lift.set_brake_mode(MotorBrake::brake);
        lift.brake();
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

void startLift() {
  stopLift();

  lift_task = new pros::Task(liftMachine);
}

void stopLift() {
  if (lift_task != nullptr) {
    lift_task->remove();
    delete lift_task;
    lift_task = nullptr;
  }
}

void resetLift() {
  startLift();

  liftPos currentPos = liftPos::STOP;
}
//////// Driver Control
void liftDriver() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT) && liftPosition != 2) setLiftPos(liftPos::LOAD);
  
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) setLiftPos(liftPos::SCORE);

  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) setLiftPos(liftPos::RESET);
}
