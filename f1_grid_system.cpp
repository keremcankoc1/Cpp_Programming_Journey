#include <iostream>
#include <string>
#include <vector>
#include <limits>

constexpr int MAX_DRIVER = 2;
constexpr int MAX_POINTS = 25;

enum class TyreType{
    Soft,
    Medium,
    Hard
};

enum class DriverStatus{
    racing,
    pit,
    finished,
    retired
};

std::string statustoString(DriverStatus status){
    switch(status){
        case DriverStatus::racing: return "racing"; 
        case DriverStatus::pit: return "pit";
        case DriverStatus::finished: return "finished";
        case DriverStatus::retired: return "retired";
        default: return "unknown"; 
    }
}

std::string tyreTypeToString(TyreType tyre){
    switch(tyre){
        case TyreType::Soft: return "Soft";
        case TyreType::Medium: return "Medium";
        case TyreType::Hard: return "Hard";
        default: return "unknown";
    }
}

class Driver{
    private:
        std::string driverName;
        std::string teamName;
        int driverPoints;
        TyreType tyreType;
        DriverStatus raceSituation;
    public:
        Driver(const std::string &driverName, const std::string &teamName, int driverPoints, TyreType tyreType, DriverStatus raceSituation){
            this->driverName = driverName;
            this->teamName = teamName;
            this->driverPoints = driverPoints;
            this->tyreType = tyreType;
            this->raceSituation = raceSituation;
        }

        // getter değer döndürür
        std::string getName()const{
            return driverName;
        }

        std::string getTeamName()const{
            return teamName;
        }

        int getDriverPoints()const{
            return driverPoints;
        }

        TyreType getTyreType()const{
            return tyreType;
        }

        DriverStatus getRaceSituation()const{
            return raceSituation;
        }

        void printDriver()const{
            std::cout << "============================================================================" << '\n';
            std::cout << "Driver name: " << driverName << '\n';
            std::cout << "Team name: " << teamName << '\n';
            std::cout << "Driver points: " << driverPoints << '\n';
            std::cout << "Tyre type: " << tyreTypeToString(getTyreType()) << '\n';
            std::cout << "Race situation: " << statustoString(getRaceSituation()) << '\n';
            std::cout << "============================================================================" << '\n';
        }

        int addPoint(int point){
            driverPoints += point;
            return driverPoints;
        }

};

using driverVector = std::vector<Driver>;

int main(void){
    driverVector drivers;
    size_t firstChoose;
    std::cout << "------------------------------ WELCOME ----------------------------------" << '\n';
    while(true){
        std::cout << "Add Driver (0) | Select Driver (1) | Show all drivers (2) | Exit (3):";
        std::cin >> firstChoose;
        std::cout << "-------------------------------------------------------------------------" << '\n';

        if(firstChoose == 0){
            if(drivers.size() >= MAX_DRIVER) std::cout << "You have reached the maximum number." << '\n';
            else{
                std::string driverName;
                std::string teamName;
                int driverPoints;
                size_t tyreChoose;
                size_t raceSituationChoose;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter driver name: ";
                std::getline(std::cin, driverName);
                std::cout << "-------------------------------------------------------------------------" << '\n';

                std::cout << "Enter team name: ";
                std::getline(std::cin, teamName);
                std::cout << "-------------------------------------------------------------------------" << '\n';

                std::cout << "Enter driver points: ";
                std::cin >> driverPoints;
                std::cout << "-------------------------------------------------------------------------" << '\n';

                std::cout << "Soft (0) | Medium (1) | Hard (2)" << '\n';
                std::cout << "Enter tyre type: ";
                std::cin >> tyreChoose;
                std::cout << "-------------------------------------------------------------------------" << '\n';

                std::cout << "Racing (0) | Pit (1) | Finished (2) | Retired (3)" << '\n';
                std::cout << "Enter race situation: ";
                std::cin >> raceSituationChoose;
                std::cout << "-------------------------------------------------------------------------" << '\n';
                
                TyreType tyre = static_cast<TyreType> (tyreChoose);
                DriverStatus raceSituation = static_cast<DriverStatus> (raceSituationChoose);

                Driver newDriver(driverName, teamName, driverPoints, tyre, raceSituation);
                drivers.push_back(newDriver);
            }
        }else if(firstChoose == 1){
            for(size_t i = 0; i < drivers.size(); i++){
                std::cout << i + 1 << ") " << drivers[i].getName() << '\n';
            }
            size_t selectDriver;
            std::cout << "Select Driver number: "; 
            std::cin >> selectDriver;
            selectDriver--;
            std::cout << "-------------------------------------------------------------------------" << '\n';
            if(selectDriver >= drivers.size()) std::cout << "Please enter valid number." << '\n';

            else{
                int driverProcess;
                std::cout << "0) Get Info | 1) Add Point" << '\n';
                std::cout << "What do you do: ";
                std::cin >> driverProcess;
                std::cout << "-------------------------------------------------------------------------" << '\n';
                if(!driverProcess)
                    drivers[selectDriver].printDriver();
                else{
                    int addPoint;
                    std::cout << "How many point add: ";
                    std::cin >> addPoint;
                    std::cout << "-------------------------------------------------------------------------" << '\n';
                    drivers[selectDriver].addPoint(addPoint);
                    std::cout << "Add process is successfull. Driver Point: " << drivers[selectDriver].getDriverPoints() << '\n';
                    std::cout << "-------------------------------------------------------------------------" << '\n';
                }
            }

        }else if(firstChoose == 2){
            for(const auto& driver : drivers){
                driver.printDriver();
            }
        }else if(firstChoose == 3){
            std::cout << "Exiting..." << '\n';
            return 0;
        }
    }
    return 0;
}