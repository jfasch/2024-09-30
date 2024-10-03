#include <base/file-sensor.h>
#include <base/CsvSink.h>

static FileSensor _sensor("/sys/class/hwmon/hwmon2/temp1_input");
static CsvSink _sink("out3.csv");

ISensor& the_sensor = _sensor;
IDataSink& the_sink = _sink;