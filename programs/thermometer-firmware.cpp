#include <base/file-sensor.h>
#include "base/IDataSink.h"
#include "base/CanDataSink.h"
#include "base/CanCoutPeriph.h"
#include <base/CoutSink.h>
#include "base/CsvSink.h"

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
        sink.write(temperature);
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
    CanCout         canCout;
    CanDataSink     canDataSink(canCout, DEFINED_CAN_ID);
    CoutSink        my_sink;
    CsvSink         my_csv_sink("out.csv");

    loop(my_sensor, my_csv_sink);

    return 0;
}
