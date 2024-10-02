#pragma once

#include "ICan.h"

class CanCout: public ICan{
    public:
        ~CanCout(void){}
        
    void SendFrame(const Frame& frame) override ;
};