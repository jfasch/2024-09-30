#pragma once

#include "sensor.h"
#include "plat.h"

#include <cstdint>


class RawMemorySensor : public Sensor
{
public:
    RawMemorySensor(char* mem)
    {
        _mem = mem;
    }

    double get_temperature() override;

private:
    char* _mem;
};
