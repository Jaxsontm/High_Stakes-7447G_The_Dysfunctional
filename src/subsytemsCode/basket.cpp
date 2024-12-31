#include "subsystemsHeaders/basket.hpp"

/// globals
Motor basket(-6, MotorGearset::red, MotorEncoderUnits::deg);

adi::Button basketLimit('H');
///machine
StateBasket currentBasketState = StateBasket::STOP;

void basketMove(StateBasket requestBasketState) {
	if (requestBasketState != currentBasketState) {
		currentBasketState = requestBasketState;
	}
}

void basketControl() {
  int timeNum = 900;
  int timeoutCalc = timeNum / 10;
  while (true) {
    switch (currentBasketState) {
      case StateBasket::SCORE:
        basket.move(127);
        for (int t = 0; t < timeoutCalc; t++) {
          if (basket.get_position() > 272) {
            t = timeoutCalc;
          }
          delay(10);
        }
        currentBasketState = StateBasket::RESET;
      break;
      case StateBasket::TOP:
        if (basketCheck.get() > 120) {
          basket.move(127);
          for (int t = 0; t < timeoutCalc; t++) {
            if (basket.get_position() > 227) {
              t = timeoutCalc;
            }
            delay(10);
          }
        currentBasketState = StateBasket::RESET;
        } else if (basketCheck.get() < 120) {
          basket.move(127);
          for (int t = 0; t < timeoutCalc; t++) {
            if (basket.get_position() > 177) {
              t = timeoutCalc;
            }
            delay(10);
          }
        currentBasketState = StateBasket::RESET;
        }
      break;
      case StateBasket::LOAD:
        basket.move(110);
        for (int t = 0; t < timeoutCalc; t++) {
          if (basket.get_position() > 224) {
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

//driver
void basketDriver() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) basketMove(StateBasket::SCORE);

  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) basketMove(StateBasket::RESET);
}