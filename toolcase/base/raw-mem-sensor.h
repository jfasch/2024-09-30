#pragma once

#include "plat.h"

#include <cstdint>


class RawMemorySensor
{
public:
    RawMemorySensor(char* mem)
    {
        _mem = mem;
    }

    double get_temperature()
    {
        return *((int32_t*)(_mem + RAW_MEM_SENSOR_TEMP_OFFSET)) / 1000.0d;
    }

private:
    char* _mem;
};
