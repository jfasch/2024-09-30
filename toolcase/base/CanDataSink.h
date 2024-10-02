#pragma once

#include "base/ICan.h"
#include "IDataSink.h"

class CanDataSink : public IDataSink{
public:
    using Frame             = ICan::Frame;
    CanDataSink(ICan & iCan, const uint8_t id): _iCan(iCan), _id(id){}
    ~CanDataSink(void){}
    void write(double value) override;
private:
    ICan&                       _iCan;
    const uint8_t               _id;
};