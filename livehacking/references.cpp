#include <iostream>

void f(int& i)
{
    i = 666;
}

int main()
{
    int i = 42;
    f(i);
    std::cout << i << std::endl;
    
    return 0;
}
