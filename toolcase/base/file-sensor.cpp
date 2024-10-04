#include "file-sensor.h"

#include <fstream>
#include <cassert>

namespace dts {

double FileSensor::get_temperature()
{
    int temperature = 666;
    std::ifstream f(_filename);
    if (!f.is_open())
        assert(false);
    f >> temperature;
    return temperature / 1000.0;
}

}
