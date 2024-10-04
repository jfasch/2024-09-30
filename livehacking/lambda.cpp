#include <string>
#include <iostream>
#include <sstream>


class Callable
{
public:
    Callable(const std::string& s) : _s(s) {}
    std::string operator()(int i) const
    {
        std::ostringstream ss;
        ss << _s << ": " << i << std::ends;
        return ss.str();
    }
private:
    std::string _s;
};

int main()
{
    // old school
    Callable c1("blah");
    auto output1 = c1(42);
    std::cout << output1 << std::endl;

    // >=11
    auto c2 = [s="blah"](int i) -> std::string
    {
        std::ostringstream ss;
        ss << s << ": " << i << std::ends;
        return ss.str();
    };
    auto output2 = c2(42);
    std::cout << output2 << std::endl;

    return 0;
}
