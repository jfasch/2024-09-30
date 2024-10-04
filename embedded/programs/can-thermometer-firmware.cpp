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

    RandomSensor rand_sensor(35.3, 42.3);
    TestSensor test_sensor(42666);
    ISensor* sensor = &rand_sensor;


    CoutSink cout_sink;

    CanDataSink<SocketCAN> cds(
        SocketCAN("mein-test-can"), 
        42);

    DataSinkAlternative<CanDataSink<SocketCAN>, CoutSink> sink(std::move(cds));

    std::string how = argv[1];
    if (how == "test") {
        sink = std::move(cout_sink);
        sensor = &test_sensor;
    }
    else if (how == "real");
    else {
        std::cerr << argv[0] << " {test|real}\n";
        return 1;
    }

    SensorReader<DataSinkAlternative<CanDataSink<SocketCAN>, CoutSink>> reader(*sensor, sink);
    reader.loop(1000);

    return 0;
}
