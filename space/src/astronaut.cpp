#include <iostream>
#include <string>
#include "../headers/astronaut.hpp"

Astronaut::Astronaut(int id, const std::string &name, int age, int experience)
    :id(id),
    name(name),
    age(age),
    experience(experience)
{}

void Astronaut::showAstronautInfo() const{
    std::cout << "Name: " << name << " | ";
    std::cout << "Id: " << id << " | ";
    std::cout << "Age: " << age << " | ";
    std::cout << "Experience: " << experience << '\n';
}

int Astronaut::getAstronautId(){
    return id;
}

int Astronaut::getAstronautAge(){
    return age;
}

std::string Astronaut::getAstronautName(){
    return name;
}

int Astronaut::getAstronautExperience(){
    return experience;
}

int Astronaut::setAstronautExperience(int &amount){
    experience += amount;
    return experience;
}