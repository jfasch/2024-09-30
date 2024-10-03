#pragma once

#include "ICan.h"

namespace dts {

class CanCout: public ICan{
    public:
        ~CanCout(void){}
        
    void SendFrame(const Frame& frame) override ;
};

}
