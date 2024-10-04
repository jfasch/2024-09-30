#pragma once

namespace dts {

class ISensor
{
public:
    virtual ~ISensor() = default;
    virtual double get_temperature() = 0;
};

}
