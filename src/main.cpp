#include <Arduino.h>

#ifdef ESP32
    #include "HardwareTimers/Esp32HardwareClock.h"

    auto esp32HardwareClock = *new Esp32HardwareClock(5, 100);
#endif

void setup()
{
    Serial.begin(115200);

#ifdef ESP32
    auto  = *new ThermostatStateMachine(&currentStatus, &hvacController, &mqttLogistics);
#endif

    pinMode(17, HIGH);
}

void loop()
{
    pinMode(17, OUTPUT); // That tracks

//#ifdef ARDUINO_AVR_LEONARDO
//    Serial.println("I am a leonardo!");
//#endif

    delay(1000);
}

