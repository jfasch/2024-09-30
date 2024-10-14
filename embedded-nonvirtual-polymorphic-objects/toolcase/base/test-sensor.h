#pragma once

#include "ISensor.h"

#include <iostream>

namespace dts {

class TestSensor : public ISensor
{
public:
    TestSensor(int temp) : _temp(temp) {}

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
