#include <base/sensor-reader.h>


extern Sensor& the_sensor;
extern IDataSink& the_sink;

int main(int argc, char** argv)
{
    SensorReader reader(the_sensor, the_sink);
    reader.loop(1000, 10);

    return 0;
}
