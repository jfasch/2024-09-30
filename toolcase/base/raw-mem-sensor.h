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

    double get_temperature();

private:
    char* _mem;
};
