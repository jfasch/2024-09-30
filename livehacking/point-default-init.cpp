#include <iostream>

class point
{
public:
    point() = default;                                 // <-- initialize members as given below
    point(int x, int y)
    : _x{x}, _y{y}                                     // <-- otherwise initialized
    {}

    int x() const { return _x; }
    int y() const { return _y; }

private:
    int _x{};                                          // <-- default unless otherwise initialized
    int _y{};                                          // <-- default unless otherwise initialized
};

int main()
{
    point p_default;
    std::cout << "default: " << '(' << p_default.x() << ',' << p_default.y() << ')' << std::endl;

    point p_explicit(42, 666);
    std::cout << "explicit: " << '(' << p_explicit.x() << ',' << p_explicit.y() << ')' << std::endl;
    
    return 0;
}
