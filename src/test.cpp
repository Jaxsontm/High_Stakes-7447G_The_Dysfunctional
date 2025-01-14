#include "test.hpp"

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
}

void basketTop() {
  basketMove(StateBasket::TOP);
}

void liftLoad() {
  
  setLiftPos(liftPos::autoLOAD);
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
      basketTop();
      break;
    case 5:
      liftLoad();
      break;
    }
}