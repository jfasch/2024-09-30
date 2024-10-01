#include <iostream>

class point
{
public:
    point() = default;
    point(int x, int y)
    {
        _x = x;
        _y = y;
    }

    int x() const { return _x; }
    int y() const { return _y; }

private:
    int _x{};
    int _y{};
};

int main()
{
    point p_default;
    std::cout << "default: " << '(' << p_default.x() << ',' << p_default.y() << ')' << std::endl;

    point p_explicit(42, 666);
    std::cout << "explicit: " << '(' << p_explicit.x() << ',' << p_explicit.y() << ')' << std::endl;
    
    return 0;
}
