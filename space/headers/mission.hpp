#pragma once
#include <string>

enum class MissionType{
    Exploration,
    Mining,
    Research,
    Default
};

class Mission{
    private:
        std::string missionName;
        MissionType missionType;
        int diffLevel;
    public:
        Mission(const std::string &missionName, int missionType, int diffLevel);
        void showMissionData() const;
        MissionType intToMissionType(int missionType);
        std::string MissionTypeToString(MissionType missionType) const;
};