#pragma once

#include <variant>
#include <cassert>
#include <iostream>


namespace dts {

template <typename... AlternativeTypes>
class DataSinkObjectAlternative
{
public:
    // ctor for copyable Alternative types
    template <typename AlternativeType>
    DataSinkObjectAlternative(const AlternativeType& alt)
    : _alternatives(alt) {}

    // ctor for movable types
    template <typename AlternativeType>
    DataSinkObjectAlternative(AlternativeType&& alt)
    : _alternatives(std::move(alt)) {}

    // assignment for copyable types
    template <typename AlternativeType>
    DataSinkObjectAlternative& operator=(const AlternativeType& alt)
    {
        _alternatives = alt;
        return *this;
    }

    // assignment for movable types
    template <typename AlternativeType>
    DataSinkObjectAlternative& operator=(AlternativeType&& alt)
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

        auto operator()(auto& alt)   // <-- abbreviated function template
        {
            alt.write(value);
        }

        // ... is the same as:

        // template <typename Alternative>
        // void operator()(Alternative alt)
        // {
        //     alt.write(value);
        // }


        double value;
    };

    std::variant<AlternativeTypes...> _alternatives;
};
 
}
