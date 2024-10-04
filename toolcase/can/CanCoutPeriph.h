#pragma once

#include "ICan.h"

namespace dts {

class CanCout: public ICan{
    public:
    void SendFrame(const Frame& frame) override ;
};

}
