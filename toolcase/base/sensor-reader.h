#pragma once

#include "ISensor.h"
#include "IDataSink.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;


class SensorReader
{
    public:
    SensorReader(ISensor& sensor, IDataSink& sink) :
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
            _sink.write(_sensor.get_temperature());
            std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
        }
        ISensor& _sensor;
        IDataSink& _sink;
};
