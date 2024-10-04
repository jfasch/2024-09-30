#include <vector>

class point
{
public:
    point(int x, int y) : _x(x), _y(y) {}
private:
    int _x, _y;
};

int main()
{
    std::vector<point> points;
    int x = 1;
    int y = 2;
    points.emplace_back(1, 2);

    point p(2,3);
    points.push_back(p);
    point& pref = p;
    points.push_back(pref);

    points.push_back(point(3,4));
    
    return 0;
}
