#include <iostream>

int main()
{
    const int container[] = { 2, 1, 4, 6, 8, 666, 0 };

    for (auto elem: container)
        std::cout << elem << std::endl;

    return 0;
}
