#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <numeric>
#include "../headers/colony.hpp"
#include "../headers/astronaut.hpp"
#include "../headers/rover.hpp"
#include "../headers/resourceManagement.hpp"

Colony::Colony(const std::string& colonyName, int colonyId)
    : colonyName(colonyName),
      colonyId(colonyId)
{}

int Colony::getColonyId() const{
    return colonyId;
}

std::string Colony::getColonyName() const{
    return colonyName;
}
    
void Colony::addAstronaut(int id, std::string &name, int age, int experience){
    std::cout << "Adding an astronaut...\n";

    Astronaut newAstronaut(id, name, age, experience);
    astronauts.push_back(newAstronaut);

    std::cout << "An astronaut has been added.\n";
}

void Colony::editAstronaut(int amount, Astronaut *astronaut){
    std::cout << "Editing an astronaut...\n";

    astronaut->setAstronautExperience(amount);

    std::cout << "Astronaut has been edited. New experience: " << astronaut->getAstronautExperience() << '\n';

}

void Colony::addRover(int carId, std::string &model, float energyLevel, bool isActive){
    std::cout << "Adding a rover...\n";

    Rover newRover(carId, model, energyLevel, isActive);
    rovers.push_back(newRover);

    std::cout << "A rover has been added.\n";
}

void Colony::editRover(int amount, Rover *rover){
    std::cout << "Editing a rover...\n";

    rover->setEnergyLevel(amount);

    std::cout << "Rover has been edited. New energy level: " << rover->getRoverEnergyLevel() << '\n';
}

void Colony::addSource(){
    int sourceId, sourceAmount;
    std::string sourceName;

    std::cout << "Please enter source Id: ";
    std::cin >> sourceId;

    std::cin.ignore();

    std::cout << "Please enter source's name: ";
    std::getline(std::cin, sourceName);

    std::cout << "Please enter source's amount: ";
    std::cin >> sourceAmount;

    std::cout << "Source is adding...\n";
    resourceManager.addSource(sourceName, sourceAmount, sourceId);
    std::cout << "Source adding is successful.\n";
}

void Colony::seeSource(){
    int choose;
    std::cout << "What action would you like to take: ";
    std::cin >> choose;

    switch(choose){
        case 1: resourceManager.showSourceData();
            break;    
    case 2:
    {
        int sourceId;
        std::cout << "Please enter source Id: ";
        std::cin >> sourceId;

        resourceManager.showOneSource(sourceId);
    } 
        break;
    default: std::cout << "Please enter a valid process.\n";
        break;
    }
}

void Colony::updateSource(){
    int choose;
    std::cout << "What action would you like to take: ";
    std::cin >> choose;

    switch(choose){
        case 1:
        {
            int increaseAmount, sourceId;

            std::cout << "Please enter source Id: ";
            std::cin >> sourceId;

            std::cout << "Please enter a increase amount: ";
            std::cin >> increaseAmount;

            resourceManager.sourceIncrease(sourceId, increaseAmount);
        } 
            break;
        case 2:
        {
            int reduceAmount, sourceId;

            std::cout << "Please enter source Id: ";
            std::cin >> sourceId;

            std::cout << "Please enter a increase amount: ";
            std::cin >> reduceAmount;

            resourceManager.sourceReduce(sourceId, reduceAmount);
        } 
            break;
        default: std::cout << "Please enter a valid process.\n";
    }
}

void Colony::addMission(std::string &missionName, int missionType, int diffLevel, int missionId){
    std::cout << "Please wait. Mission is adding...\n";
    Mission newMission(missionName, missionType, diffLevel, missionId);
    missions.push_back(newMission);
    std::cout << "Mission adding process is successfull.\n";
    
}

Astronaut *Colony::findAstronaut(int astronautId) {
    for(auto &astronaut : astronauts){
        if(astronaut.getAstronautId() == astronautId){
            return &astronaut;
        }
    }
    return nullptr;
}

Rover *Colony::findRover(int roverId){
    for (auto &rover : rovers){
        if(rover.getRoverId() == roverId){
            return &rover;
        }
    }
    return nullptr;
}

Resource *Colony::findSource(int sourceId){
    for (auto &source : resourceManager.getSources()){
        if(source.getSourceId() == sourceId){
            return &source;
        }
    }
    return nullptr;
}

Mission *Colony::findMission(int missionId){
    for(auto &mission : missions){
        if(mission.getMissionId() == missionId){
            return &mission;
        }
    }
    return nullptr;
}
