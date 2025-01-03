#include "test.hpp"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/intake.hpp"

void goalGrab() {
  request_new_state_mogo(StateMogo::RELEASE);
  delay(10);
  request_new_state_mogo(StateMogo::LOCATE);
}

void intakeOne() {
  spinFor(StateIntake::ONE);
}

void intakeTwo() {
  spinFor(StateIntake::TWO);
}

void basketScore() {
  basketMove(StateBasket::SCORE);
  delay(250);
  while (basketState != 0) {
    delay(10);
  }
  spinFor(StateIntake::ONE);
}

void liftLoad() {
  setLiftPos(liftPos::LOAD);
}

void test() {
    switch (testSelection) {
    case 0:
      goalGrab();
      break;
    case 1:
      intakeOne();
      break;
    case 2:
      intakeTwo();
      break;
    case 3:
      basketScore();
      break;
    case 4:
      liftLoad();
      break;
    }
}