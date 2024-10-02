#pragma once
 
class IDataSink
{
public:
    virtual ~IDataSink() = default;
    virtual void write(double value) = 0;
};