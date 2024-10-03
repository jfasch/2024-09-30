#include <expected>
#include <iostream>
#include <cstdint>

int main()
{
    std::expected<char, char> exp = 3;
    std::cout << sizeof(exp) << std::endl;
    
    return 0;
}
