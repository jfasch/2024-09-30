#pragma once

#include "sensor.h"

namespace dts {

class TestSensor : public Sensor
{
public:
    void set_temperature(int temp) {
        _temp = temp;
    }
    double get_temperature() override {
        return (double)_temp/1000;
    }

private:
    int _temp{};
};

}
