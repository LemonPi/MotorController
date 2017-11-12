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
     * @brief Select how fast to turn and in which direction.
     * @param pwm Pulse width modulation value [-255,255], with higher value
     * corresponding to higher speed.
     */
    void setVelocity(int pwm);
    int getVelocity() const;

    /**
     * @brief Rotate at last set speed.
     * Motor will continue rotating until another rotation command is sent.
     */
    void go() const;

    void fastStop() const;
    void floatStop() const;

  private:
    void go(int C, int D, int pwm) const;

    const int _logicCPin, _logicDPin, _enableAPin;
    int _lastPWM;
};

#endif // MOTORCONTROLLER_H
