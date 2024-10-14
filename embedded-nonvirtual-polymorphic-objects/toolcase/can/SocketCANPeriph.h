#pragma once

#include "frame.h"
#include <string>

namespace dts {

class SocketCAN
{
public:
    SocketCAN(const std::string& iface);
    ~SocketCAN();

    SocketCAN(const SocketCAN&) = delete;
    SocketCAN& operator=(const SocketCAN&) = delete;

    SocketCAN(SocketCAN&& s);
    SocketCAN& operator=(SocketCAN&& s);
        
    void SendFrame(const Frame& frame);

private:
    int _socket;                                       // <-- requires resource management!
};

}
