#pragma once

#include "frame.h"

namespace dts {

class ICan{
    public:
    virtual ~ICan(void) = default;
    virtual void SendFrame(const Frame& frame) = 0;
};

// and payload equality?

// inline bool operator == (ICan::Frame l, ICan::Frame r){
//     return l.id == r.id;
// }

}
