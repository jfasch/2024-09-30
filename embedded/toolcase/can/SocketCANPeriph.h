#pragma once

#include "frame.h"
#include <string>

namespace dts {

class SocketCAN
{
public:
    SocketCAN(const std::string& iface);
    ~SocketCAN();
        
    void SendFrame(const Frame& frame);

private:
    int _socket;                                       // <-- requires resource management!
};

}
