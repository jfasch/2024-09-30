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
    if (argc == 1) {
        std::cerr << argv[0] << " <sensor-type> [filename|baseaddr]\n";
        return 42;

    }

    Sensor* sensor;
    
    // <setup>
    if (...) {
        FileSensor ...
    }
    else if (...) {
        RawMemorySensor ...


            // </setup>

            // // <setup>
            // char sensormem[128];
            // memset(sensormem, 0, sizeof(sensormem));
            // *((unsigned*)(sensormem + RAW_MEM_SENSOR_TEMP_OFFSET)) = 27500; // initial temperature

            // RawMemorySensor sensor(sensormem);
            // // </setup>

    }
    else if (...) {
        ...
    }
    else if (...) {
        ...
    }
    else if (...) {
        ...
    }
    else if (...) {
        ...
    }
    else {
        assert(false);
    }

    can_loop(sensor);

    return 0;
}
