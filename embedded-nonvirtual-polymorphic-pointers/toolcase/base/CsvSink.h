#pragma once

#include "IDataSink.h"
#include <fstream>


namespace dts {

class CsvSink : public IDataSink
{
    public:
        CsvSink(const std::filesystem::path& path)
        : CsvSink(path, !std::filesystem::exists(path))
        {

        }
        void write(double value) override
        {
            _file << value << std::endl;
        }

    private:
        CsvSink(const std::filesystem::path& path, bool create)
        : _file(path, create ? std::ios_base::trunc : std::ios_base::app)
        {
            if(create)
            {
                _file << "temperature" << ";" << std::endl;
            }
        }

        std::ofstream _file;
};

}
