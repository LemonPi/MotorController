#include <Arduino.h>
#include "MotorController.h"

MotorController::MotorController(int logicC, int logicD, int enableA)
    : _logicCPin(logicC), _logicDPin(logicD), _enableAPin(enableA),
      _lastPWM(0) {
    pinMode(_logicCPin, OUTPUT);
    pinMode(_logicDPin, OUTPUT);
}

void MotorController::setVelocity(int pwm) {
    _lastPWM = pwm;
}

int MotorController::getVelocity() const {
    return _lastPWM;
}

void MotorController::go() const {
    if (_lastPWM < 0) {
        go(HIGH, LOW, -_lastPWM);
    } else {
        go(LOW, HIGH, _lastPWM);
    }
}

void MotorController::fastStop() const {
    go(LOW, LOW, 255);
}
void MotorController::floatStop() const {
    go(LOW, LOW, 0);
}

void MotorController::go(int C, int D, int pwm) const {
    digitalWrite(_logicCPin, C);
    digitalWrite(_logicDPin, D);
    analogWrite(_enableAPin, pwm);
}
