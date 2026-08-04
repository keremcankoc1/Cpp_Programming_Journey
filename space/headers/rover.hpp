#pragma once
#include <iostream>
#include <string>

class Rover{
    private:
        int carId;
        std::string model;
        float energyLevel;
        bool isActive;
    public:
        Rover(int carId, const std::string &model, float energyLevel, bool isActive);
        float setEnergyLevel(float amount);
        void infoSituation();
        void doMission();
};