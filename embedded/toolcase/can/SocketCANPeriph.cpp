#include "SocketCANPeriph.h"

#ifdef __linux__
#  include <sys/socket.h>
#  include <net/if.h>
#  include <linux/can.h>
#  include <string.h>
#  include <sys/ioctl.h>
#  include <unistd.h>
#endif
#include <cassert>


namespace dts {

SocketCAN::SocketCAN(const std::string& iface)
{
#ifdef __linux__
    _socket = socket(PF_CAN, SOCK_RAW, CAN_RAW);       // <-- acquire resource

    ifreq ifr;
    strcpy(ifr.ifr_name, iface.c_str());
    int error = ioctl(_socket, SIOCGIFINDEX, &ifr);
    assert(!error);
    (void)error;

    sockaddr_can addr;
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    error = bind(_socket, (struct sockaddr *)&addr, sizeof(addr));
    assert(!error);
#else
    assert(false);
#endif
}

SocketCAN::~SocketCAN()
{
#ifdef __linux__
    close(_socket);                                    // <-- release resource
#endif
}
        
void SocketCAN::SendFrame(const Frame& frame)
{
#ifdef __linux__
    can_frame f{};
    f.can_id = frame.id;
    f.can_dlc = frame.dlc;
    memcpy(f.data, frame.data, frame.dlc);

    size_t nwritten = write(_socket, &f, sizeof(f));
    assert(nwritten == sizeof(f));
    (void)nwritten;
#else
    assert(false);
#endif
}

}
