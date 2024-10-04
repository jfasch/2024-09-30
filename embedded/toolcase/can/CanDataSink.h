#pragma once

#include "ICan.h"
#include <base/IDataSink.h>

namespace dts {

class CanDataSink : public IDataSink{
public:
    CanDataSink(ICan & iCan, const uint8_t id): _iCan(iCan), _id(id){}
    ~CanDataSink(void){}
    void write(double value) override;
private:
    ICan&                       _iCan;
    const uint8_t               _id;
};

}
