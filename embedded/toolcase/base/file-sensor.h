#pragma once

#include "ISensor.h"

#include <filesystem>

namespace dts {

class FileSensor : public ISensor
{
public:
    FileSensor(const std::filesystem::path& filename)
    : _filename(filename) {}

    double get_temperature() override;

private:    
    std::filesystem::path _filename;
};

}
