#include "subsystemsHeaders/basket.hpp"

/// globals
Motor basket(-6, MotorGearset::red, pros::v5::MotorEncoderUnits::deg);

adi::Button basketLimit('H');

/// Actions
//scores and resets the basket within double the timeout time
/*void basketScore(int timeout) {
	int startTime = pros::millis();
	while (pros::millis() - startTime < timeout) {
	if (basketLimit.get_value() == 0) {
		basketReset();
	} else {
			basket.move_relative(10, 127);
			while (basketLimit.get_value() == 0) {
				basket.move(127);
			}
			basket.brake();
		}
	}
}

// resets the basket in desperate situations
void basketReset()  {
	while (basketLimit.get_value() == 0) {
		basket.move(-127); // resets the basket
		delay(5);
	}
	basket.brake(); // Stop the motor and reset the position to zero
	basket.tare_position();
}
void basketDrive(void *param) {
	int timeout = *(int *)param;
	int startTime = pros::millis();
	if (basketLimit.get_value() == 0) {
		basketReset();
	} else {
		while (pros::millis() - startTime < timeout) {
			basket.move_relative(10, 127);
			while (basketLimit.get_value() == 0) {
				basket.move(127);
			}
			basket.brake();
		}
	}
}

void basketDrive(void *param) {
	int timeout = *(int *)param;
	int startTime = pros::millis();
	while (pros::millis() - startTime < timeout) {
		while (basket.get_position() <= 380) {
			basket.move(127);
			delay(5);
		}
	}
	delay(75);
	while (basketLimit.get_value() == 0) {
		basket.move(-127);
		delay(5);
	}
	basket.brake();
	basket.tare_position();
	basket.move_relative(-10, 127);
}

void basketResetDrive(void *param) {
	int timeoutR = *(int *)param;
	int startTime = pros::millis();
	while (basketLimit.get_value() == 0 && pros::millis() - startTime < timeoutR) {
		basket.move(-127);
		delay(5);
	}
	basket.brake();
	basket.tare_position();
	basket.move_relative(-10, 127);
        // Driver Control
}
void basketDriver() {
	if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) {
		static int timeout = 2000;
		pros::Task basketScoreTask(basketDrive, &timeout, "Basket Scoring");
	}
}

void basketResetDriver() {
	if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
		static int timeoutR = 1000;
		pros::Task basketResetTask(basketResetDrive, &timeoutR, "Basket Reset");
	}
}*/

StateBasket currentBasketState = StateBasket::STOP;

void basketMove(StateBasket requestBasketState) {
	if (requestBasketState != currentBasketState) {
		currentBasketState = requestBasketState;
	}
}

void basketControl() {
  int timeNum = 1000;
  int timeoutCalc = timeNum / 10;
  while (true) {
    switch (currentBasketState) {
      case StateBasket::SCORE:
        basket.move(127);
        for (int t = 0; t < timeoutCalc; t++) {
          if (basket.get_position() > 287) {
            t = timeoutCalc;
          }
          delay(10);
        }
        currentBasketState = StateBasket::RESET;
        break;
      case StateBasket::RESET:
        while (basketLimit.get_value() == 0) basket.move(-127);
        currentBasketState = StateBasket::STOP;
        break;
      case StateBasket::STOP:
        basket.brake();
        basket.tare_position();
        break;
    }
     delay(10); 
  }
}

void basketDriver() {
	if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
		basketMove(StateBasket::SCORE);
	}
}

void basketResetDriver() {
	if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
		basketMove(StateBasket::RESET);
	}
}