#include <base/file-sensor.h>

#include <cstring>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;


void can_loop(Sensor& sensor)
{
    for (;;) {
        double temperature = sensor.get_temperature();
        std::cout << temperature << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << argv[0] << " <SENSOR-FILE>\n";
        return 42;
    }

    FileSensor my_sensor(argv[1]);

    can_loop(my_sensor);

    return 0;
}
