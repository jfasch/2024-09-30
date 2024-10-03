#include "tmpdir-fixture.h"

#include <base/file-sensor.h>

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>

struct file_sensor_suite : public tmpdir_fixture  {};

using namespace dts;

TEST_F(file_sensor_suite, basic)
{
    std::ofstream(dirname / "temperature") << "27500" << std::endl;

    FileSensor sensor(dirname / "temperature");
    double temperature = sensor.get_temperature();

    ASSERT_NEAR(temperature, 27.5, 0.001);
}
