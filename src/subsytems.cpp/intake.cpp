#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/motors.hpp"
using namespace pros;

// Blue Ziptie
Motor Intake(11, MotorGearset::blue);

Distance DistanceIntakeTop(19);

Distance DistanceIntakeBottom(21);

adi::Pneumatics intakePiston('B', false);
//