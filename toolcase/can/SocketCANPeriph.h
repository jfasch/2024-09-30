#pragma once

#include "ICan.h"
#include <string>

namespace dts {

class SocketCAN : public ICan 
{
public:
    SocketCAN(const std::string& iface);
    ~SocketCAN();
        
    void SendFrame(const Frame& frame) override;

private:
    int _socket;                                       // <-- requires resource management!
};

}
