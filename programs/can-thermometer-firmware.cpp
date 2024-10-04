#include <base/sensor-reader.h>
#include <base/random-sensor.h>
#include <can/SocketCANPeriph.h>
#include <can/CanDataSink.h>

using namespace dts;


int main()
{
    SocketCAN can_iface("mein-test-can");
    CanDataSink sink(can_iface, 42);

    RandomSensor sensor(35.3, 42.3);

    SensorReader reader(sensor, sink);
    reader.loop(1000);
    return 0;
}
