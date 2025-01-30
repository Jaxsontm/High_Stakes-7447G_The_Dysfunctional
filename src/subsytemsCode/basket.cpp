#include "subsystemsHeaders/basket.hpp"

/// globals
Motor basket(-6, MotorGearset::red, MotorEncoderUnits::deg);

adi::Button basketLimit('H');

pros::Task* basket_task = nullptr;
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
        basketState = 1;
        basket.move(127);
        for (int t = 0; t < timeoutCalc; t++) {
          if (basket.get_position() > 270) {
            t = timeoutCalc;
          }
          delay(10);
        }
        currentBasketState = StateBasket::RESET;
      break;
      case StateBasket::TOP:
        basketState = 2;
          basket.move(127);
          for (int t = 0; t < timeoutCalc; t++) {
            if (basket.get_position() > 239) {
              t = timeoutCalc;
            }
            delay(10);
          }
          currentBasketState = StateBasket::RESET;
      break;
      case StateBasket::LOAD:
        basketState = 3;
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
        basketState = 4;
        basket.move(-127);
        for (int t = 0; t < timeoutCalc; t++) {
          if (basketLimit.get_value() == 1) {
            t = timeoutCalc;
          }
          delay(10);
        }
        if (basketLimit.get_value() == 1) {
          currentBasketState = StateBasket::STOP;
        } else {
          currentBasketState = StateBasket::RESET2;
        }
      break;
      case StateBasket::RESET2:
        basketState = 5;
        basket.move(127);
        for (int t = 0; t < timeoutCalc; t++) {
          if (basket.get_position() > 272) {
            t = timeoutCalc;
          }
          delay(10);
        }
        currentBasketState = StateBasket::STOP;
      break;
      case StateBasket::STOP:
        basketState = 0;
        basket.brake();
        basket.tare_position();
      break;
    }
    delay(10); 
  }
}

void startBasket() {
  stopBasket();

  basket_task = new pros::Task(basketControl);
}

void stopBasket() {
  if (basket_task != nullptr) {
    basket_task->remove();
    delete basket_task;
    basket_task = nullptr;
  }
}

void resetBasket() {
  startBasket();
  
  StateBasket currentBasketState = StateBasket::STOP;
}

//driver
void basketDriver() {
  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) basketMove(StateBasket::SCORE);

  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) basketMove(StateBasket::RESET);

  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) basketMove(StateBasket::TOP);

  if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) basketMove(StateBasket::RESET2);
}