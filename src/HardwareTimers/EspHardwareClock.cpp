#ifdef ESP32


#include "Esp32HardwareClock.h"

Esp32HardwareClock::Esp32HardwareClock()
{
    //_outputPin = outputPin;
    //_microsecondsForFullCycle = microsecondsForFullCycle;

    _outputPin = 17;
    _microsecondsForFullCycle = 100;
    _currentClockPinState = true;

    thisInstanceAddress = this;

    pinMode(_outputPin, OUTPUT);

    digitalWrite(_outputPin, _currentClockPinState);
}

void Esp32HardwareClock::Start()
{
    timerAlarmEnable(_timerConfiguration);
}

void Esp32HardwareClock::Stop()
{
    timerAlarmDisable(_timerConfiguration);
}

void Esp32HardwareClock::ClockPinStateAction()
{
    digitalWrite(thisInstanceAddress->_outputPin, thisInstanceAddress->_currentClockPinState);

    thisInstanceAddress->_currentClockPinState = !thisInstanceAddress->_currentClockPinState;
}

void Esp32HardwareClock::InitializeHardwareTimer()
{
    int halfCycleMicroseconds = _microsecondsForFullCycle / 2;

    _timerConfiguration = timerBegin(0, 80, true);

    const void (*fn)() = thisInstanceAddress->ClockPinStateAction();

    //timerAttachInterrupt(_timerConfiguration, &(*thisInstanceAddress).ClockPinStateAction, true);

    timerAlarmWrite(_timerConfiguration, halfCycleMicroseconds, true); // Cycle on/off totals 100 uS. 50us on then 50us off
}


#endif