#pragma once

#include <variant>
#include <cassert>
#include <iostream>


namespace dts {

template <typename... Alternatives>
class DataSinkAlternative
{
public:
    template <typename Alternative>
    DataSinkAlternative(const Alternative& alt)
    : _alternatives(alt) {}

    template <typename Alternative>
    DataSinkAlternative(Alternative&& alt)
    : _alternatives(std::move(alt)) {}

    template <typename Alternative>
    DataSinkAlternative& operator=(const Alternative& alt)
    {
        _alternatives = alt;
        return *this;
    }

    template <typename Alternative>
    DataSinkAlternative& operator=(Alternative&& alt)
    {
        _alternatives = std::move(alt);
        return *this;
    }

    void write(double v) 
    {
        Visitor vis(v);
        std::visit(vis, _alternatives);
    }

private:
    struct Visitor
    {
        Visitor(double v) : value(v) {}

        // template <typename Alternative>
        // void operator()(Alternative alt)
        // {
        //     alt.write(value);
        // }
        auto operator()(auto& alt)   // <-- abbreviated function template
        {
            alt.write(value);
        }

        double value;
    };

    std::variant<Alternatives...> _alternatives;
};
 
// class IDataSink
// {
// public:
//     virtual ~IDataSink() = default;
//     virtual void write(double value) = 0;
// };

}
