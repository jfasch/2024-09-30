#include "file-sensor.h"

#include <fstream>


double FileSensor::get_temperature()
{
    int temperature;
    std::ifstream(_filename) >> temperature;
    return temperature / 1000.0;
}
