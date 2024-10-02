#pragma once

#include "IDataSink.h"
#include <vector>


class CompositeSink : public IDataSink
{
public:
    void write(double value) override
    {
        for (IDataSink* sink: _sinks)
            sink->write(value);
    }

    void add_sink(IDataSink* sink)
    {
        _sinks.push_back(sink);
    }

private:
    std::vector<IDataSink*> _sinks;
};
