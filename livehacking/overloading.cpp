#include <iostream>

extern "C" void do_something_with(int par)
{
    std::cout << __PRETTY_FUNCTION__ << ": " << par << std::endl;
}

void do_something_with(double par)
{
    std::cout << __PRETTY_FUNCTION__ << ": " << par << std::endl;
}

void do_something_with(double par1, int par2)
{
    std::cout << __PRETTY_FUNCTION__ << ": " << par1 << ',' << par2 << std::endl;
}

void do_something_with(int par1, double par2)
{
    std::cout << __PRETTY_FUNCTION__ << ": " << par1 << ',' << par2 << std::endl;
}

int main()
{
    do_something_with(42);
    do_something_with(42.666);
    do_something_with(42.666, 7);
    do_something_with(7, 42.666);
    // do_something_with(42, 666); // <-- ambiguous
    
    return 0;
}
