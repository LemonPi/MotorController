#include <Arduino.h>
#include "MotorController.h"

MotorController::MotorController(int logicC, int logicD, int enableA)
    : _logicCPin(logicC), _logicDPin(logicD), _enableAPin(enableA),
      _lastPWM(0) {
    pinMode(_logicCPin, OUTPUT);
    pinMode(_logicDPin, OUTPUT);
}

void MotorController::setSpeed(uint8_t pwm) {
    _lastPWM = pwm;
}

void MotorController::goCounterClockWise() const {
    go(LOW, HIGH);
}
void MotorController::goClockWise() const {
    go(HIGH, LOW);
}
void MotorController::fastStop() const {
    go(LOW, LOW);
}
void MotorController::floatStop() const {
    go(LOW, LOW, 0);
}

void MotorController::go(int C, int D, int pwm) const {
    digitalWrite(_logicCPin, C);
    digitalWrite(_logicDPin, D);
    if (pwm == NO_VALUE) {
        pwm = _lastPWM;
    }
    analogWrite(_enableAPin, pwm);
}
