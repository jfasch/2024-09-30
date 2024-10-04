#include <base/sensor-reader.h>
#include <base/test-sensor.h>
#include <base/DataSinkAlternative.h>
#include <gtest/gtest.h>

using namespace dts;

struct MyTestSink
{
    MyTestSink(double* v) : value(v) {}
    void write(double v) 
    { 
        *value = v;
    }
    double* value;
};

TEST(sensor_reader_suite, basic)
{
    double value = -273.15;
    TestSensor sensor(42666);
    MyTestSink test_sink(&value);
    DataSinkAlternative<MyTestSink> sink(test_sink);

    SensorReader rdr(sensor, sink);
    rdr.loop(1, 1);

    ASSERT_NEAR(value, 42.666, 0.001);
}
