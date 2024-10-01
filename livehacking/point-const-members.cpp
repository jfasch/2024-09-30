#include <iostream>

class point
{
public:
    point() = default;
    point(int x, int y)
    : _x{x}, _y{y}
    {}

    int x() const { return _x; }
    int y() const { return _y; }

    point move(const point& vec) const
    {
        return point(_x + vec._x, _y + vec._y);
    }

private:
    const int _x{};
    const int _y{};
};

int main()
{
    const point p_orig(42, 666);
    std::cout << '(' << p_orig.x() << ',' << p_orig.y() << ')' << std::endl;

    const point p_moved = p_orig.move(point(1,2));

    std::cout << '(' << p_orig.x() << ',' << p_orig.y() << ')' << std::endl;
    std::cout << '(' << p_moved.x() << ',' << p_moved.y() << ')' << std::endl;
    
    return 0;
}
