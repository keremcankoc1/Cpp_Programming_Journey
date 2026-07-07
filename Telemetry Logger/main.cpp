#include "headers/includes.h"
#include "headers/classes/telemetryLogger.h"
int lapIndex = 0;

int main(void){
    telemetryLogger raceTelemetry("race.txt");
    srand(time(NULL));
    int data = 1;
    
    for(lapIndex = 0; lapIndex < 40; lapIndex++){
        switch(data){
            case 1: data = (rand() % 2) + 1;
            break;
            case 2: data = (rand() % 3) + 1;
            break;
            case 3: data = (rand() % 3) + 2;
            break;
            case 4: data = (rand() % 3) + 3;
            break;
            case 5: data = (rand() % 3) + 4;
            break;
            case 6: data = (rand() % 3) + 5;
            break;
            case 7: data = (rand() % 3) + 6;
            break;
            case 8: data = (rand() % 2) + 7;
            break;
        }
        std::string gearData = std::to_string(data);
        
        raceTelemetry.writeData(gearData);
    }
    return 0;
}