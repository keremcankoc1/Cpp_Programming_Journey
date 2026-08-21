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
                    int colonyId;
                    std::cout << "Enter the ID of the colony to which the astronaut will be assigned: ";
                    std::cin >> colonyId;
                    Colony *colony = colonyManager.findColony(colonyId);

                    if(colony != nullptr){
                        int id, amount;

                        std::cout << "========================================================================\n";
                        std::cout << "Please enter astronaut's id: ";
                        std::cin >> id;

                        Astronaut *astronaut = colony->findAstronaut(id);

                        if(astronaut != nullptr){
                            std::cout << "========================================================================\n";
                            std::cout << "Enter the amount of experience to be added:: ";
                            std::cin >> amount;
                            std::cout << "========================================================================\n";

                            colony->editAstronaut(amount, astronaut);
                        }else{
                            std::cout << "Astronaut isn't found.\n";
                        }
                    }else{
                        std::cout << "Colony isn't found.\n";
                    }

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
                    std::cout << "Enter the ID of the colony to which the rover will be assigned: ";
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

                    int colonyId;
                    std::cout << "Enter the ID of the colony to which the rover will be assigned: ";
                    std::cin >> colonyId;
                    Colony *colony = colonyManager.findColony(colonyId);

                    if(colony != nullptr){
                        int roverId;
                        std::cout << "Please enter rover's id: ";
                        std::cin >> roverId;

                        Rover *rover = colony->findRover(roverId);

                        if(rover != nullptr){
                            rover->infoSituation();
                        }
                    }

                }else if(roverProcess == 3){
                    // Edit rover

                    int colonyId;
                    std::cout << "Enter the ID of the colony to which the rover will be assigned: ";
                    std::cin >> colonyId;
                    Colony *colony = colonyManager.findColony(colonyId);

                    if(colony != nullptr){
                        int id, amount;

                        std::cout << "========================================================================\n";
                        std::cout << "Please enter rover's id: ";
                        std::cin >> id;

                        Rover *rover = colony->findRover(id);

                        if(rover != nullptr){
                            std::cout << "========================================================================\n";
                            std::cout << "Enter the amount of energy to be added: ";
                            std::cin >> amount;
                            std::cout << "========================================================================\n";

                            colony->editRover(amount, rover);
                        }else{
                            std::cout << "Rover isn't found.\n";
                        }
                    }else{
                        std::cout << "Colony isn't found.\n";
                    }

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

                    int colonyId;
                    std::cout << "Enter the ID of the colony to which the astronaut will be assigned: ";
                    std::cin >> colonyId;
                    Colony *colony = colonyManager.findColony(colonyId);

                    if(colony != nullptr){
                        // Sections for receiving input from “addSource” to “menu” will be added
                        colony->addSource();
                    }else{
                        std::cout << "Colony isn't found.\n";
                    }

                }else if(sourceProcess == 2){
                    // See a source

                    int colonyId;
                    std::cout << "Enter the ID of the colony to which the astronaut will be assigned: ";
                    std::cin >> colonyId;
                    Colony *colony = colonyManager.findColony(colonyId);

                    if(colony != nullptr){
                        // Sections for receiving input from "seeSource" to “menu” will be added
                        colony->seeSource();
                    }else{
                        std::cout << "Colony isn't found.\n";
                    }

                }else if(sourceProcess == 3){
                    // Edit source

                    int colonyId;
                    std::cout << "Enter the ID of the colony to which the astronaut will be assigned: ";
                    std::cin >> colonyId;
                    Colony *colony = colonyManager.findColony(colonyId);

                    if(colony != nullptr){
                        // Sections for receiving input from "updateSource" to “menu” will be added
                        colony->updateSource();
                    }else{
                        std::cout << "Colony isn't found.\n";
                    }

                }
            }else if(processNumber == 4){
                // Mission process

                size_t missionProcess;
                std::cout << "1) Add a mission\n";
                std::cout << "2) See a mission\n";
                //std::cout << "3) Edit mission\n";

                std::cout << "Please make a selection: ";
                std::cin >> missionProcess;

                if(std::cin.fail() || (missionProcess != 1 && missionProcess !=2 && missionProcess != 3)){
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.clear();
                }else if(missionProcess == 1){
                    // Add a mission

                    int colonyId;
                    std::cout << "Enter the ID of the colony to which the mission will be assigned: ";
                    std::cin >> colonyId;
                    Colony *colony = colonyManager.findColony(colonyId);

                    if(colony != nullptr){
                        int diffLevel, missionType, missionId;
                        std::string missionName;

                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Please enter mission's name: ";
                        std::getline(std::cin, missionName);

                        std::cout << "Please enter a mission's id: ";
                        std::cin >> missionId; 

                        std::cout << "Please enter mission's difficulty level (a number): ";
                        std::cin >> diffLevel;

                        std::cout << "0) Exploration | 1) Mining | 2) Research | 3) Default\n";
                        std::cout << "Please enter mission's type: ";
                        std::cin >> missionType;

                        colony->addMission(missionName, missionType, diffLevel, missionId);
                    }else{
                        std::cout << "Colony isn't found.\n";
                    }

                }else if(missionProcess == 2){
                    // See a mission

                    int colonyId;
                    std::cout << "Enter the ID of the colony to which the astronaut will be assigned: ";
                    std::cin >> colonyId;
                    Colony *colony = colonyManager.findColony(colonyId);

                    if(colony != nullptr){
                        int missionId;
                        std::cout << "Please enter mission's id: ";
                        std::cin >> missionId;

                        Mission *mission = colony->findMission(missionId);

                        if(mission != nullptr){
                            mission->showMissionData();
                        }
                    }else{
                        std::cout << "Colony isn't found.\n";
                    }
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