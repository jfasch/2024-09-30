#include <base/test-sensor.h>

#include <map>
#include <iostream>
#include <cstring>
#include <memory>

using namespace dts;

int main()
{
    // <setup phase>
    std::shared_ptr<TestSensor> s1(new TestSensor(42));
    std::shared_ptr<ISensor> s2(new TestSensor(666));
    
    std::map<std::string, std::shared_ptr<ISensor>> sensors;
    sensors["links-oben"] = s1;
    sensors["rechts-unten"] = s2;
    // </setup phase>

    // <runtime phase>
    for (auto [name, sensor]: sensors)
        std::cout << name << ": " << sensor->get_temperature() << std::endl;

    s1->set_temperature(666.42);

    for (auto [name, sensor]: sensors)
        std::cout << name << ": " << sensor->get_temperature() << std::endl;
    // </runtime phase>

    return 0;
}
