## Arduino library for a H-Bridge motor controller (driver) of a single motor

Two ways to use this:
1. Drop directory directly inside sketch

or

1. Move directory under Arudino libraries directory
2. In Arduino IDE with sketch open select Sketch > Include Library > WheelEncoder (should be under Contributed Libraries)

## Usage

Connect pins according to data sheet

```c++
#include <Arduino.h>
#include <MotorController.h>

// H-Bridge pins
constexpr auto LOGIC_C = 8;
constexpr auto LOGIC_D = 9;
constexpr auto ENABLE_A = 3;

MotorController mc(LOGIC_C, LOGIC_D, ENABLE_A);

void setup() { 
    mc.setSpeed(50U);
}

void loop() {
    // clockwise for 1s
    mc.goClockWise();
    delay(1000);
    // coast stop (give 2 seconds)
    mc.floatStop();
    delay(2000);
    // counterclockwise for 1s
    mc.goCounterClockWise();
    delay(1000);
    // hard stop (give 2 seconds and compare difference with float stop)
    mc.fastStop();
    delay(2000);
}
```
