
#pragma once

#include "stdint.h"
class ICan{
    public:
        struct Frame{
            uint8_t id;
            uint8_t data[7];
        };
    virtual ~ICan(void) = default;
    virtual void SendFrame(const Frame& frame) = 0;
};

inline bool operator == (ICan::Frame l, ICan::Frame r){
    return l.id == r.id;
}