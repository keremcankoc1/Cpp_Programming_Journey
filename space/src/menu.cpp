#include <iostream>
#include <string>
#include <limits>
#include "headers/astronaut.hpp"
#include "headers/colony.hpp"
#include "headers/colonyManagement.hpp"
#include "headers/mission.hpp"
#include "headers/resource.hpp"
#include "headers/resourceManagement.hpp"
#include "headers/rover.hpp"

void menu(){
    ColonyManagement colonyManager;
    size_t choose;
    std::cout << "1) Add colony\n";
    std::cout << "2) Manage colony\n";
    std::cout << "3) Show colony's situation\n";
    std::cout << "Please make a selection: ";
    std::cin >> choose;

    if(std::cin.fail() || (choose != 1 && choose != 2 && choose != 3)){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
    }else if(choose == 1){  // Add colony
        colonyManager.addColonies(); 
    }else if(choose == 2){  // Manage colony
        size_t processNumber;
        std::cout << "1) Astronaut process\n";
        std::cout << "2) Rover Process\n";
        std::cout << "3) Source Process\n";
        std::cout << "4) Mission Process\n";

        std::cout << "Please make a selection: ";
        std::cin >> processNumber;

        if(std::cin.fail() || (processNumber != 1 && processNumber !=2 && processNumber != 3 && processNumber != 4)){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
        }else if(processNumber == 1){
            size_t astronautProcess;
            std::cout << "1) Add an astronaut\n";
            std::cout << "2) See an astronaut\n";
            std::cout << "3) Edit astronaut\n";

            std::cout << "Please make a selection: ";
            std::cin >> astronautProcess;

            if(std::cin.fail() || (astronautProcess != 1 && astronautProcess !=2 && astronautProcess != 3)){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
            }else if(astronautProcess == 1){
                
            }
        }
        
    }else if(choose == 3){  // Show colony
        int colonyId;
        std::cout << "Please enter colony's Id: ";
        std::cin >> colonyId;

        if(std::cin.fail()){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
        }

        colonyManager.showColonySituation(colonyId);
    }
}