#pragma once

#include "ISensor.h"
#include "plat.h"

#include <cstdint>


class RawMemorySensor : public ISensor
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
