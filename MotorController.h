#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

/**
 * @brief Control a single motor that's connected to an H-bridge, such as the
 * ST L298
 */
class MotorController {
    static constexpr auto NO_VALUE = -1;

  public:
    /**
     * @brief Set up the pins of the H-bridge (for this motor)
     * @param logicC Digital output pin
     * @param logicD Digital output pin
     * @param enableA Analog output pin
     */
    MotorController(int logicC, int logicD, int enableA);

    /**
     * @brief Select how fast to turn.
     * @param pwm Pulse width modulation value [0,255], with higher value
     * corresponding to higher speed.
     */
    void setSpeed(uint8_t pwm);

    /**
     * @brief Rotate counterclockwise at last set speed.
     * Motor will continue rotating until another rotation command is sent.
     */
    void goCounterClockWise() const;
    void goClockWise() const;
    void fastStop() const;
    void floatStop() const;

  private:
    void go(int C, int D, int pwm = NO_VALUE) const;

    const int _logicCPin, _logicDPin, _enableAPin;
    uint8_t _lastPWM;
};

#endif // MOTORCONTROLLER_H
