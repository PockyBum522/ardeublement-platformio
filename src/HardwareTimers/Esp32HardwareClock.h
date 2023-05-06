#ifdef ESP32


#ifndef ARDEUBLEMENT_PLATFORMIO_ESP32_HARDWARE_CLOCK_H
#define ARDEUBLEMENT_PLATFORMIO_ESP32_HARDWARE_CLOCK_H

#include <esp_attr.h>
#include <esp32-hal-timer.h>
#include <functional>

class Esp32HardwareClock
{
public:
    Esp32HardwareClock();

    IRAM_ATTR void Start();

    IRAM_ATTR void Stop();

    Esp32HardwareClock* thisInstanceAddress;

    void ClockPinStateAction();

    void (*ToggleClockPinState)();

private:
    int _outputPin;

    int _microsecondsForFullCycle;

    bool _isEnabled = false;

    bool _currentClockPinState;

    hw_timer_t *_timerConfiguration = nullptr;

    void InitializeHardwareTimer();

};

#endif //ARDEUBLEMENT_PLATFORMIO_ESP32_HARDWARE_CLOCK_H


#endif