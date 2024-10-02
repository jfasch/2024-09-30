#include <iostream>
#include <string>
#include <vector>


struct Foo
{
    Foo(int i) : i1(i) {}
    
    int i1{};
    int i2{42};

    std::string s{"blah"};
    std::vector<int> v = std::vector<int>(3, 4);
};

int main()
{
    Foo f(666);
    std::cout << "i1: " << f.i1 << std::endl;
    std::cout << "i2: " << f.i2 << std::endl;
    std::cout << "s:  " << f.s << std::endl;
    for (int elem: f.v)
        std::cout << "v:  " << elem << std::endl;
    
    return 0;
}
