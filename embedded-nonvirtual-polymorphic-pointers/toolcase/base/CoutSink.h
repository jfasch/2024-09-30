#pragma once

#include "DataSinkPointerAlternative.h"

#include <iostream>

namespace dts {

class CoutSink
{
public:
    void write(double value)
    {
        std::cout << value << std::endl;
    }
};

}
