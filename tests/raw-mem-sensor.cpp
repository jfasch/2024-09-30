#include <base/raw-mem-sensor.h>
#include <gtest/gtest.h>


TEST(raw_mem_sensor, basic)
{
    char sensor_addrmap[48];
    memset(sensor_addrmap, 0, sizeof(sensor_addrmap));
    *((unsigned*)(sensor_addrmap + RAW_MEM_SENSOR_CONF_OFFSET)) = 666; // unused
    *((unsigned*)(sensor_addrmap + RAW_MEM_SENSOR_TEMP_OFFSET)) = 27500; // initial temperature

    RawMemorySensor sensor(sensor_addrmap);

    double temperature = sensor.get_temperature();
    ASSERT_NEAR(temperature, 27.5, 0.001);

    *((unsigned*)(sensor_addrmap + RAW_MEM_SENSOR_TEMP_OFFSET)) = 42500; // temperature changed

    temperature = sensor.get_temperature();
    ASSERT_NEAR(temperature, 42.5, 0.001);
}

TEST(raw_mem_sensor, negative_temperature)
{
    char sensor_addrmap[48];
    memset(sensor_addrmap, 0, sizeof(sensor_addrmap));
    *((unsigned*)(sensor_addrmap + RAW_MEM_SENSOR_TEMP_OFFSET)) = -273150; // temperature changed

    RawMemorySensor sensor(sensor_addrmap);

    double temperature = sensor.get_temperature();
    ASSERT_NEAR(temperature, -273.15, 0.001);
}
