#include <base/file-sensor.h>
#include "base/IDataSink.h"
#include "base/CoutDataSink.h"
#include "base/CanDataSink.h"
#include "base/CanCoutPeriph.h"

#include <cstring>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;
const uint8_t   DEFINED_CAN_ID = 88;


void loop(Sensor& sensor, IDataSink& sink)
{
    for (;;) {
        double temperature = sensor.get_temperature();
        // std::cout << temperature << std::endl;
        CanDataSink::Frame compareFrame1 = {1,{0}}, compareFrame2 = {2,{0}};
        sink.write(temperature);
        std::cout << "frames are ident: " << (compareFrame1 == compareFrame2) << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << argv[0] << " <SENSOR-FILE>\n";
        return 42;
    }

    FileSensor my_sensor(argv[1]);
    CoutDataSink    coutSink;
    CanCout         canCout;
    CanDataSink     canDataSink(canCout, DEFINED_CAN_ID);

    loop(my_sensor, canDataSink);
    return 0;
}
