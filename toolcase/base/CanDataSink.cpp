#include "CanDataSink.h"

#include <cstring>

void CanDataSink::write(double value){
    Frame frame;
    frame.id = _id;
    int32_t milliGrad = value * 1000.0;

    frame.data[0] = milliGrad & 0xff;
    frame.data[1] = (milliGrad >> 8) & 0xff;
    frame.data[2] = (milliGrad >> 16) & 0xff;
    frame.data[3] = (milliGrad >> 24) & 0xff;
    this->_iCan.SendFrame(frame);
}
