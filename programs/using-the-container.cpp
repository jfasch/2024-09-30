#include <base/container.h>

#include <iostream>


int main()
{
    Container c{{1, "eins"}, {2, "zwei"}};
    for (const auto& elem: c)
        std::cout << elem.first << ':' << elem.second << '\n';
    return 0;
}
