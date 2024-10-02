#pragma once

#include "sensor.h"

#include <filesystem>


class FileSensor : public Sensor
{
public:
    FileSensor(const std::filesystem::path& filename)
    : _filename(filename) {}

    double get_temperature() override;

private:    
    std::filesystem::path _filename;
};
