#include <iostream>
#include <string>
#include "../headers/rover.hpp"

enum class Situation{
    Passive,
    Active
};

Situation translateSituation(bool isActive){
    return (isActive) ? Situation::Active : Situation::Passive;
}

std::string SituationToString(Situation sit){
    return (sit == Situation::Active) ? "Active" : "Passive";
}

Rover::Rover(int carId, const std::string &model, float energyLevel, bool isActive)
    :carId(carId),
    model(model),
    energyLevel(energyLevel),
    isActive(isActive)
{}

void Rover::infoSituation(){
    std::cout << "Model: " << model << " | ";
    std::cout << "Car Id: " << carId << " | ";
    std::cout << "Energy Level: " << energyLevel << " | ";
    std::cout << "Situation: " << SituationToString(translateSituation(isActive)) << '\n';
}

int Rover::getRoverId(){
    return carId;
}

float Rover::getRoverEnergyLevel(){
    return energyLevel;
}

bool Rover::getRoverActivate(){
    return isActive;
}

std::string Rover::getRoverModel(){
    return model;
}

