#include <base/test-sensor.h>

#include <iostream>
#include <memory>

using namespace dts;

// class HatNochEineReferenz
// {
// public:
//     HatNochEineReferenz(const std::unique_ptr<TestSensor>& ref) : _ref(ref) {}
// private:
//     std::unique_ptr<TestSensor> _ref;
// };

int main()
{
    std::unique_ptr<TestSensor> p(new TestSensor(42666));
    std::cout << p->get_temperature() << std::endl;

    auto copy = std::move(p);
    // std::cout << p->get_temperature() << std::endl;
    std::cout << p.get() << std::endl;
    std::cout << copy.get() << std::endl;
    
    return 0;
}
