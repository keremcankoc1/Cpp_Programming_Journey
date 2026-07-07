#include "../../headers/includes.h"
#include "../../headers/classes/telemetryLogger.h"

telemetryLogger::telemetryLogger(const std::string &fileName){
    this->fileName = fileName;

    file.open(fileName, std::ios::app);
        if(file.is_open()){
            std::cout << "[SYSTEM] File open process is successfull.\n";
            std::cout << "[SYSTEM] File recording has started.\n";
        }else{
            std::cout << "[SYSTEM] File open process isn't successfull.\n";
        }
    
}
telemetryLogger::~telemetryLogger(){
    if(file.is_open()) file.close();
    std::cout << "[SYSTEM] File close process is successfull.\n";
}

void telemetryLogger::writeData(const std::string &data){
    file <<"Moment " << lapIndex + 1 << ": Gear " << data << std::endl;
}
