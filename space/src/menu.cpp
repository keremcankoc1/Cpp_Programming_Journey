#include <iostream>
#include <string>
#include <limits>
#include "../headers/astronaut.hpp"
#include "../headers/colony.hpp"
#include "../headers/colonyManagement.hpp"
#include "../headers/mission.hpp"
#include "../headers/resource.hpp"
#include "../headers/resourceManagement.hpp"
#include "../headers/rover.hpp"

void menu(){
    ColonyManagement colonyManager;
    while(true){
        size_t choose;
        std::cout << "\n\n1) Add colony\n";
        std::cout << "2) Manage colony\n";
        std::cout << "3) Show colony's situation\n";
        std::cout << "4) Exit\n";
        std::cout << "Please make a selection: ";
        std::cin >> choose;

        if(std::cin.fail() || (choose != 1 && choose != 2 && choose != 3 && choose !=4)){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
        }else if(choose == 1){  
            // Add colony

            colonyManager.addColonies(); 
        }else if(choose == 2){  
            // Manage colony

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
                    // Add an astronaut

                    int colonyId;
                    std::cout << "Enter the ID of the colony to which the astronaut will be assigned: ";
                    std::cin >> colonyId;
                    Colony *colony = colonyManager.findColony(colonyId);

                    if(colony != nullptr){
                        int id, age, experience;
                        std::string name;

                        std::cout << "========================================================================\n";
                        std::cout << "Please enter astronaut's id: ";
                        std::cin >> id;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "========================================================================\n";
                        std::cout << "Please enter astronaut's name: ";
                        std::getline(std::cin, name);
                        std::cout << "========================================================================\n";
                        std::cout << "Please enter astronaut's age: ";
                        std::cin >> age;
                        std::cout << "========================================================================\n";
                        std::cout << "Please enter astronaut's experience level: ";
                        std::cin >> experience;
                        std::cout << "========================================================================\n";

                        colony->addAstronaut(id, name, age, experience);
                    }else{
                        std::cout << "Colony isn't found.\n";
                    }

                }else if(astronautProcess == 2){
                    // See an astronaut

                    int colonyId;
                    std::cout << "Enter the ID of the colony to which the astronaut will be assigned: ";
                    std::cin >> colonyId;
                    Colony *colony = colonyManager.findColony(colonyId);

                    if(colony != nullptr){
                        int astronautId;
                        std::cout << "Please enter astronaut's id: ";
                        std::cin >> astronautId;

                        Astronaut *astronaut = colony->findAstronaut(astronautId);

                        if(astronaut != nullptr){
                            astronaut->showAstronautInfo();
                        }
                    }
                }else if(astronautProcess == 3){
                    // Edit an astronaut
                }
            }else if(processNumber == 2){
                // Rover process

                size_t roverProcess;
                std::cout << "1) Add a rover\n";
                std::cout << "2) See a rover\n";
                std::cout << "3) Edit rover\n";

                std::cout << "Please make a selection: ";
                std::cin >> roverProcess;

                if(std::cin.fail() || (roverProcess != 1 && roverProcess !=2 && roverProcess != 3)){
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.clear();
                }else if(roverProcess == 1){
                    int colonyId;
                    std::cout << "Enter the ID of the colony to which the astronaut will be assigned: ";
                    std::cin >> colonyId;

                    Colony *colony = colonyManager.findColony(colonyId);

                    if(colony != nullptr){
                        int carId;
                        std::string model;
                        float energyLevel;
                        bool isActive;

                        std::cout << "========================================================================\n";
                        std::cout << "Please enter rover's id: ";
                        std::cin >> carId;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "========================================================================\n";
                        std::cout << "Please enter rover's model: ";
                        std::getline(std::cin, model);
                        std::cout << "========================================================================\n";
                        std::cout << "Please enter rover's energy level: ";
                        std::cin >> energyLevel;
                        std::cout << "========================================================================\n";
                        std::cout << "Please enter rover's situation (Active or not): ";
                        std::cin >> isActive;
                        std::cout << "========================================================================\n";

                        colony->addRover(carId, model, energyLevel, isActive);
                    }
                    
                }else if(roverProcess == 2){
                    // See a rover
                }else if(roverProcess == 3){
                    // Edit rover
                }

            }else if(processNumber == 3){
                // Source Process

                size_t sourceProcess;
                std::cout << "1) Add a source\n";
                std::cout << "2) See a source\n";
                std::cout << "3) Edit source\n";

                std::cout << "Please make a selection: ";
                std::cin >> sourceProcess;

                if(std::cin.fail() || (sourceProcess != 1 && sourceProcess !=2 && sourceProcess != 3)){
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.clear();
                }else if(sourceProcess == 1){
                    // Add a source
                }else if(sourceProcess == 2){
                    // See a source
                }else if(sourceProcess == 3){
                    // Edit source
                }
            }else if(processNumber == 4){
                // Mission process

                size_t missionProcess;
                std::cout << "1) Add a mission\n";
                std::cout << "2) See a mission\n";
                std::cout << "3) Edit mission\n";

                std::cout << "Please make a selection: ";
                std::cin >> missionProcess;

                if(std::cin.fail() || (missionProcess != 1 && missionProcess !=2 && missionProcess != 3)){
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.clear();
                }else if(missionProcess == 1){
                    // Add a mission
                }else if(missionProcess == 2){
                    // See a mission
                }else if(missionProcess == 3){
                    // Edit mission
                }
            }
            
        }else if(choose == 3){  
            // Show colony

            int colonyId;
            std::cout << "Please enter colony's Id: ";
            std::cin >> colonyId;

            if(std::cin.fail()){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
            }

            colonyManager.showColonySituation(colonyId);
        }else if(choose == 4){
            break;
        }
    }
}