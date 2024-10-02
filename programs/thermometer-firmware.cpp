#include <base/file-sensor.h>
#include "base/IDataSink.h"
#include "base/CanDataSink.h"
#include "base/CanCoutPeriph.h"
#include <base/sensor-reader.h>
#include <base/CoutSink.h>
#include "base/CsvSink.h"
#include <base/CompositeSink.h>

#include <cstring>
#include <vector>
#include <iostream>

const uint8_t   DEFINED_CAN_ID = 88;


int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << argv[0] << " <SENSOR-FILE>\n";
        return 42;
    }

    FileSensor my_sensor(argv[1]);
    CanCout canCout;
    CanDataSink my_can_sink(canCout, DEFINED_CAN_ID);  // <-- sink
    CoutSink my_cout_sink;                             // <-- sink
    CsvSink my_csv_sink("out.csv");                    // <-- sink

    CompositeSink my_all_sink;                         // <-- sink
    my_all_sink.add_sink(&my_can_sink);
    my_all_sink.add_sink(&my_cout_sink);
    my_all_sink.add_sink(&my_csv_sink);

    SensorReader reader(my_sensor, my_all_sink);

    reader.loop(1000, 10);

    return 0;
}
