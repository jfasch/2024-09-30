#include <base/file-sensor.h>
#include <base/CoutSink.h>

static dts::FileSensor _sensor("/sys/class/hwmon/hwmon2/temp1_input");
static dts::CoutSink _sink;

dts::ISensor& the_sensor = _sensor;
dts::IDataSink& the_sink = _sink;
