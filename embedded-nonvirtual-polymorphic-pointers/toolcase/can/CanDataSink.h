#pragma once

#include <base/DataSinkPointerAlternative.h>

namespace dts {

template <class CAN_Controller>
class CanDataSink
{
public:
    CanDataSink(const CAN_Controller& ctrlr, const uint8_t id)
    : _ctrlr(ctrlr), _id(id) {}

    CanDataSink(CAN_Controller&& ctrlr, const uint8_t id)
    : _ctrlr(std::move(ctrlr)), _id(id) {}

    CanDataSink(CanDataSink&& rhs)
    : _ctrlr(std::move(rhs._ctrlr)),
      _id(rhs._id)
    {}

    ~CanDataSink(void){}
    void write(double value)
    {
        Frame frame;
        frame.id = _id;
        int32_t milliGrad = value * 1000.0;

        frame.dlc = 4;
        frame.data[0] = milliGrad & 0xff;
        frame.data[1] = (milliGrad >> 8) & 0xff;
        frame.data[2] = (milliGrad >> 16) & 0xff;
        frame.data[3] = (milliGrad >> 24) & 0xff;
        _ctrlr.SendFrame(frame);
    }
private:
    CAN_Controller _ctrlr;
    const uint8_t _id;
};

}
