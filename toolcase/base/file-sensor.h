#pragma once

#include <filesystem>


class FileSensor
{
public:
    FileSensor(std::filesystem::path filename)
    : _filename(filename) {}

    double get_temperature();

private:    
    std::filesystem::path _filename;
};
