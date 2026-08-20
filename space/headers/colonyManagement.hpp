#include <iostream>
#include <vector>
#include "../headers/colony.hpp"
#include <string>

using colonyVector = std::vector<Colony>;

class ColonyManagement{
    private:
        colonyVector colonies;
    public:
        
        ~ColonyManagement(){
            std::cout << "The colonies are being deleted..." << '\n';
            std::cout << "The colonies have been deleted." << '\n';
        }
        void addColonies();
        void showColonySituation(int colonyId) const;

        Colony *findColony(int colonyId);
};