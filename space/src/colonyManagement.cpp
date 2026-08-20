#include <iostream>
#include <vector>
#include "../headers/colonyManagement.hpp"
#include <string>

void ColonyManagement::addColonies(){
    std::string colonyName;
    int colonyId;
    std::cin.ignore();
    
    std::cout << "Please enter colony's name: ";
    std::getline(std::cin, colonyName);
    std::cout << "Please enter colony's Id:";
    std::cin >> colonyId;

    Colony newColony(colonyName, colonyId);
    colonies.push_back(newColony);
}

void ColonyManagement::showColonySituation(int colonyId) const{
    Colony myColony("Default", -1);
    for(auto& colony : colonies){
        if(colonyId == colony.getColonyId()){
            myColony = colony;
            break;
        }
    }

    std::cout << "Colony Name: " << myColony.getColonyName() << '\n';
    std::cout << "Colony ID: " << myColony.getColonyId() << '\n';
    
}

Colony *ColonyManagement::findColony(int colonyId){
    while(true){
        for(auto &colony : colonies){
            if(colony.getColonyId() == colonyId){
                return &colony;
            }
        }

        bool exit;
        std::cout << "Please enter a valid colony id.\n";
        std::cout << "Press enter 1 for exit or press 0 to try again: ";
        std::cin >> exit;
        if(exit){
            break;
        }else{
            std::cin >> colonyId;
        }
    }
    return nullptr;
}
