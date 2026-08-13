#include <iostream>
#include <string>
#include <vector>
#include <limits>
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

    std::cout << "Adding an astronaut...\n";

    Astronaut newAstronaut(id, name, age, experience);
    astronauts.push_back(newAstronaut);

    std::cout << "An astronaut has been added.\n";
}

void Colony::addRover(int carId, std::string &model, float energyLevel, bool isActive){
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

    std::cout << "Adding a rover...\n";

    Rover newRover(carId, model, energyLevel, isActive);
    rovers.push_back(newRover);

    std::cout << "A rover has been added.\n";
}
void Colony::updateSource(){
    int choose;
    std::cout << "1) Source Increase | 2) Source Reduce | 3) Add Source | 4) View all resources | 5) View one source\n";
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
        case 3:
        {
            int sourceId, sourceAmount;
            std::string sourceName;

            std::cout << "Please enter source Id: ";
            std::cin >> sourceId;

            std::cin.ignore();

            std::cout << "Please enter source's name: ";
            std::getline(std::cin, sourceName);

            std::cout << "Please enter source's amount: ";
            std::cin >> sourceAmount;

            resourceManager.addSource(sourceName, sourceAmount, sourceId);
        }
            break;
        case 4: resourceManager.showSourceData();
            break;    
        case 5:
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

