#include "../headers/mission.hpp"
#include <string>
#include <iostream>

MissionType Mission::intToMissionType(int missionType){
    switch(missionType){
        case 0: return MissionType::Exploration;
        case 1: return MissionType::Mining;
        case 2: return MissionType::Research;
        default: return MissionType::Default;
    }
}

Mission::Mission(const std::string &missionName, int missionType, int diffLevel, int missionId)
    : missionName(missionName),
      missionType(intToMissionType(missionType)),
      diffLevel(diffLevel),
      missionId(missionId)
{}

std::string Mission::MissionTypeToString(MissionType missionType) const{
    switch(missionType){
        case MissionType::Exploration : return "Exploration";
        case MissionType::Mining : return "Mining";
        case MissionType::Research : return "Research";
        case MissionType::Default : return "Default";
        default: return "Unknown";
    }
}

void Mission::showMissionData() const{
    std::cout << "Mission name: " << missionName << '\n';
    std::cout << "Mission id: " << missionId << '\n';
    std::cout << "Mission type: " << MissionTypeToString(missionType) << '\n';
    std::cout << "Difficulty level: " << diffLevel << '\n';
}

int Mission::getMissionId(){
    return missionId;
}