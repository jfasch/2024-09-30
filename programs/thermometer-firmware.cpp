#include <base/file-sensor.h>
#include <base/CoutSink.h>

#include <cstring>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;


void loop(Sensor& sensor, IDataSink& sink)
{
    for (;;) {
        double temperature = sensor.get_temperature();
        sink.write(temperature);
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
    CoutSink my_sink;

    loop(my_sensor, my_sink);

    return 0;
}
