#include "file-sensor.h"

#include <fstream>
#include <stdexcept>

namespace dts {

double FileSensor::get_temperature()
{
    int temperature = 666;
    std::ifstream f(_filename);
    if (!f.is_open())
        throw std::runtime_error("nix file open");
    f >> temperature;
    return temperature / 1000.0;
}

}
