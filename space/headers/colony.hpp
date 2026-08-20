#pragma once
#include <string>
#include <vector>
#include "astronaut.hpp"
#include "rover.hpp"
#include "resourceManagement.hpp"

using astronautVector = std::vector<Astronaut>;
using roverVector = std::vector<Rover>;

class Colony{
    private:
        std::string colonyName;
        int colonyId;
        astronautVector astronauts;
        roverVector rovers;
        ResourceManagement resourceManager;
    public:
        Colony(const std::string& colonyName, int colonyId);
        void addAstronaut(int id, std::string &name, int age, int experience);
        void addRover(int carId, std::string &model, float energyLevel, bool isActive);
        void updateSource();
        int getColonyId() const;
        std::string getColonyName()const;

        Astronaut *findAstronaut(int astronautId);
        Rover *findRover(int roverId);
        Resource *findSource(int sourceId);
};