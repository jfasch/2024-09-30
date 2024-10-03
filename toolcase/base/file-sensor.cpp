#include "file-sensor.h"

#include <fstream>

namespace dts {

double FileSensor::get_temperature()
{
    int temperature = 666;
    std::ifstream(_filename) >> temperature;
    return temperature / 1000.0;
}

}
