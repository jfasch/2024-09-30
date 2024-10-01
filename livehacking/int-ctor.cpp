#include <iostream>

int main()
{
    int mein_integer{666};
    std::cout << mein_integer << std::endl;

    float mein_float{666.42345674345675432346754334565434565434565434567};
    std::cout << mein_float << std::endl;

    int mein_zweiter_integer{mein_float};
    std::cout << mein_zweiter_integer << std::endl;

    return 0;
}
