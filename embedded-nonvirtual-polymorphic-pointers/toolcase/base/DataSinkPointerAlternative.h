#pragma once

#include <variant>
#include <cassert>
#include <iostream>


namespace dts {

template <typename... AlternativePointerTypes>
class DataSinkPointerAlternative
{
public:
    template <typename AlternativePointerType>
    DataSinkPointerAlternative(const AlternativePointerType& alt)
    : _alternatives(alt) {}

    template <typename AlternativePointerType>
    DataSinkPointerAlternative& operator=(const AlternativePointerType& alt)
    {
        _alternatives = alt;
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
        auto operator()(auto& alt)   // <-- abbreviated function template
        {
            alt->write(value);
        }
        double value;
    };

    std::variant<AlternativePointerTypes...> _alternatives;
};
 
}
