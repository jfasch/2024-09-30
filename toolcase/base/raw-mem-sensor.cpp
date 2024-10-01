#include "raw-mem-sensor.h"


double RawMemorySensor::get_temperature()
{
    return *((int32_t*)(_mem + RAW_MEM_SENSOR_TEMP_OFFSET)) / 1000.0d;
}
