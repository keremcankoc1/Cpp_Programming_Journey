#pragma once
#include <string>
#include <vector>
#include "astronaut.hpp"
#include "rover.hpp"
#include "mission.hpp"
#include "resourceManagement.hpp"

using astronautVector = std::vector<Astronaut>;
using roverVector = std::vector<Rover>;
using missionVector = std::vector<Mission>;

class Colony{
    private:
        std::string colonyName;
        int colonyId;
        astronautVector astronauts;
        roverVector rovers;
        ResourceManagement resourceManager;
        missionVector missions;
    public:
        Colony(const std::string& colonyName, int colonyId);
        void addAstronaut(int id, std::string &name, int age, int experience);
        void editAstronaut(int amount, Astronaut *astronaut);
        void addRover(int carId, std::string &model, float energyLevel, bool isActive);
        void editRover(int amount, Rover *rover);
        void updateSource();
        void addSource();
        void seeSource();
        void addMission(std::string &missionName, int missionType, int diffLevel, int missionId);
        int getColonyId() const;
        std::string getColonyName()const;

        Astronaut *findAstronaut(int astronautId);
        Rover *findRover(int roverId);
        Resource *findSource(int sourceId);
        Mission *findMission(int missionId);
};