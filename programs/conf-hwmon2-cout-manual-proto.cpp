#include <base/file-sensor.h>
#include <base/CoutSink.h>

static FileSensor _sensor("/sys/class/hwmon/hwmon2/temp1_input");
static CoutSink _sink;

ISensor& the_sensor = _sensor;
IDataSink& the_sink = _sink;
