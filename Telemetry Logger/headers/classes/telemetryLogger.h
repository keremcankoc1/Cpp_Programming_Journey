#pragma once
#include "../includes.h"

class telemetryLogger{
    private:
        std::fstream file;
        std::string fileName;
    public:
        telemetryLogger(const std::string &fileName);
        ~telemetryLogger();

        void writeData(const std::string &data);
};