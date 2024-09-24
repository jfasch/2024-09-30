#pragma once

#include <string>
#include <map>


class Container
{
public:
    Container(std::initializer_list<std::pair<int, std::string>>);

    std::size_t n_elements() const { return _container.size(); }
    bool has(int key) const { return _container.find(key) != _container.end(); }

    auto begin() const { return _container.begin(); }
    auto end() const { return _container.end(); }

private:
    std::map<int, std::string> _container;
};
