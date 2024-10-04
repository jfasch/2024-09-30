#pragma once

#include "ICan.h"
#include <string>

namespace dts {

class SocketCAN : public ICan 
{
public:
    SocketCAN(const std::string& iface);
    ~SocketCAN();

    SocketCAN(const SocketCAN&) = delete;
    SocketCAN& operator=(const SocketCAN&) = delete;
        
    void SendFrame(const Frame& frame) override;

private:
    int _socket;                                       // <-- requires resource management!
};

}
