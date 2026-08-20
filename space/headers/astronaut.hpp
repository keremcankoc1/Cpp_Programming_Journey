#pragma once
#include <iostream>
#include <string>

class Astronaut{
    private:
        int id;
        std::string name;
        int age;
        int experience;
    public:
        Astronaut(int id, const std::string &name, int age, int experience);
        void showAstronautInfo() const;
        int setAstronautExperience(int amount);

        int getAstronautId();
        int getAstronautAge();
        int getAstronautName();
        int getAstronautExperience();
};