#pragma once

#include "IDataSink.h"

#include <iostream>

namespace dts {

class CoutSink : public IDataSink
{
public:
    void write(double value) override
    {
        std::cout << value << std::endl;
    }
};

}
