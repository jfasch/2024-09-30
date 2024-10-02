#include <iostream>

int main()
{
    int mein_integer{666};
    std::cout << mein_integer << std::endl;

    int mein_default_integer{};                        // <-- default 0
    std::cout << mein_default_integer << std::endl;

    return 0;
}
