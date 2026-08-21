#pragma once
#include <iostream>
#include <string>

class Rover{
    private:
        int carId;
        std::string model;
        int energyLevel;
        bool isActive;
    public:
        Rover(int carId, const std::string &model, int energyLevel, bool isActive);
        int setEnergyLevel(int &amount);
        void infoSituation();
        void doMission();

        int getRoverId();
        std::string getRoverModel();
        bool getRoverActivate();
        int getRoverEnergyLevel();
};