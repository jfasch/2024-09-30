#include <iostream>

class point
{
public:
    point()
    {
        _x = _y = 0;
    }

    point(int x, int y)
    {
        _x = x;
        _y = y;
    }

    int x() const { return _x; }
    int y() const { return _y; }

    bool operator==(const point& rhs) const
    {
        return _x == rhs._x && _y == rhs._y;
    }

    bool operator!=(const point& rhs) const
    {
        return ! operator==(rhs);
    }

    void move(int x, int y)
    {
        _x += x;
        _y += y;
    }

    void move(const point& vec)
    {
        _x += vec._x;
        _y += vec._y;
    }

    point& operator+=(const point& vec)
    {
        move(vec);
        return *this;
    }

private:
    int _x;
    int _y;
};

std::ostream& operator<<(std::ostream& o, point p)
{
    o << '(' << p.x() << ',' << p.y() << ')';
    return o;
}

int main()
{
    const point p1;
    std::cout << p1 << std::endl;

    const point p2(1, 2);
    std::cout << p2 << std::endl;

    const point p3(1, 2);

    point p4(5, 6);

    if (p2 == p3)
        std::cout << "p2 und p3 sind gleich" << std::endl;
    if (p2 != p3)
        std::cout << "p2 und p3 sind ungleich" << std::endl;
    if (p2 == p4)
        std::cout << "p2 und p4 sind gleich" << std::endl;
    if (p2 != p4)
        std::cout << "p2 und p4 sind ungleich" << std::endl;

    p4.move(2, 3);
    std::cout << p4 << std::endl;

    const point vec(2, 1);
    p4.move(vec);
    std::cout << p4 << std::endl;

    point p5;

    point vec1(10, 20);
    p5 = p4 += vec1;
    std::cout << p4 << std::endl;
    std::cout << p5 << std::endl;

    return 0;
}
