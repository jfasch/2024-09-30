#pragma once

#include "stdint.h"

namespace dts {

class ICan{
    public:
        struct Frame{
            uint8_t id{};
            uint8_t dlc{};
            uint8_t data[8]{};
        };
    virtual ~ICan(void) = default;
    virtual void SendFrame(const Frame& frame) = 0;
};

// and payload equality?

// inline bool operator == (ICan::Frame l, ICan::Frame r){
//     return l.id == r.id;
// }

}
