
#pragma once

#include "base/IDataSink.h"
#include <fstream>


class CsvSink : public IDataSink
{
    public:
        CsvSink(const std::filesystem::path& path)
        :_file(path)
        {}
        void write(double value) override
        {
            _file << value << std::endl;
        }
    private:

        std::ofstream _file;
};
