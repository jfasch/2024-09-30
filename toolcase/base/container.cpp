#include "container.h"


Container::Container(std::initializer_list<std::pair<int, std::string>> elems)
{
    for (auto elem: elems)
        _container[elem.first] = elem.second;
}
