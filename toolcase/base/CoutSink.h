#pragma once

#include "IDataSink.h"

#include <iostream>

class CoutSink : public IDataSink
{
public:
    void write(double value) override
    {
        std::cout << value << std::endl;
    }
};
