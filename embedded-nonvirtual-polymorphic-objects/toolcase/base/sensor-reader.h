#pragma once

#include "ISensor.h"
#include <chrono>
#include <thread>
#include <iostream>

namespace dts {

template <class Sink>
class SensorReader
{
    public:
    SensorReader(ISensor& sensor, Sink& sink) :
    _sensor(sensor), _sink(sink)
    {
        
    }
    void loop(uint32_t milliseconds) {
        for (;;) {
            iloop(milliseconds);
        }
    }
    void loop(uint32_t milliseconds, uint32_t cycles) {
        for (uint32_t i=0; i < cycles; i++) {
            iloop(milliseconds);
        }
    }
    private:
        void iloop(uint32_t milliseconds) {
            double temp = _sensor.get_temperature();
            _sink.write(temp);
            std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
        }
        ISensor& _sensor;
        Sink& _sink;
};

}
