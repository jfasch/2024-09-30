#include "CanDataSink.h"

#include <cstring>

namespace dts {

void CanDataSink::write(double value){
    Frame frame;
    frame.id = _id;
    int32_t milliGrad = value * 1000.0;

    frame.dlc = 4;
    frame.data[0] = milliGrad & 0xff;
    frame.data[1] = (milliGrad >> 8) & 0xff;
    frame.data[2] = (milliGrad >> 16) & 0xff;
    frame.data[3] = (milliGrad >> 24) & 0xff;
    _iCan.SendFrame(frame);
}

}
