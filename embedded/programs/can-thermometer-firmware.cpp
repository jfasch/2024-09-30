#include <base/sensor-reader.h>
#include <base/random-sensor.h>
#include <base/test-sensor.h>
#include <base/CoutSink.h>
#include <can/SocketCANPeriph.h>
#include <can/CanDataSink.h>

using namespace dts;


int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << argv[0] << " {test|real}\n";
        return 1;
    }

    SocketCAN can_iface("mein-test-can");
    CanDataSink<SocketCAN> can_sink(can_iface, 42);
    CoutSink cout_sink;

    RandomSensor rand_sensor(35.3, 42.3);
    TestSensor test_sensor(42666);

    IDataSink* sink = &can_sink;
    ISensor* sensor = &rand_sensor;

    std::string how = argv[1];
    if (how == "test") {
        sink = &cout_sink;
        sensor = &test_sensor;
    }
    else if (how == "real");
    else {
        std::cerr << argv[0] << " {test|real}\n";
        return 1;
    }

    SensorReader reader(*sensor, *sink);
    reader.loop(1000);

    return 0;
}
