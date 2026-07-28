#include <iostream>
#include <string>
#include <vector>
#include <limits>

class Driver;
class Car;

using carVector = std::vector<Car>;
using driverVector = std::vector<Driver>;

class Garage{
    public:
        static driverVector drivers;
        static carVector cars;
};

driverVector Garage::drivers;
carVector Garage::cars;

class Driver{
    private:
        int id;
        std::string name;
        std::string team; 
        int age;
    public:
        Driver(const std::string &name, const std::string &team, int age, int id){
            this->age = age;
            this->name = name;
            this->team = team;
            this->id = id;
        }
        
        void getDriverInfo() const{
            std::cout << "Id: " << id << " | ";
            std::cout << "Name: " << name << " | ";
            std::cout << "Team: " << team << " | ";
            std::cout << "Age: " << age << '\n';
        }

        std::string getTeam() const{
            return team;
        }

        std::string getName() const{
            return name;
        }

        int getAge() const{
            return age;
        }

        int getId() const{
            return id;
        }

};

class Car{
    private:
        int ownerId;
        std::string plate;
        std::string model;
        int year;
    public:
        Car(const std::string &model, const std::string &plate, int year, int ownerId){
            this->model = model;
            this->plate = plate;
            this->year = year;
            this->ownerId = ownerId;
        }

        void getCarInfo() const{
            std::cout << "Plate: " << plate << " | ";
            std::cout << "Model: " << model << " | ";
            std::cout << "Year: " << year << " | ";
            std::cout << "Owner Id: " << ownerId << '\n';
        }
        
        std::string getPlate() const{
            return plate;
        }

        std::string getModel() const{
            return model;
        }

        int getYear() const{
            return year;
        }

        int getOwnerId() const{
            return ownerId;
        }
};

void addDrivers();
void addCars();
void listDrivers();
void listCars();
void getOneInfo(int& driverId);

int main(void){
    while(true){
        std::cout << "=============================================\n";
        std::cout << "1.\t Add Driver\n";
        std::cout << "2.\t Add Car\n";
        std::cout << "3.\t List All Drivers\n";
        std::cout << "4.\t List All Cars\n";
        std::cout << "5.\t List One Driver's Cars\n";
        std::cout << "6.\t Exit\n";
        std::cout << "Enter Your Process:\t";
        int choose, driverId;
        std::cin >> choose;
        std::cout << "=============================================\n";

        switch(choose){
            case 1: addDrivers();
                break;
            case 2: addCars();
                break;
            case 3: listDrivers();
                break;
            case 4: listCars();
                break;
            case 5: std::cout << "Enter driver ID:"; std::cin >> driverId;
                    getOneInfo(driverId);
                break;
            case 6: std::cout << "Exiting"; return 0;
                break;
            default: std::cout << "Please enter value process.\n";
        }
    }

    return 0;
}

void addDrivers(){
    std::string name;
    int age;
    int id;
    std::string team;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Name: ";
    getline(std::cin, name);
    std::cout << "=============================================\n";

    std::cout << "Team: ";
    getline(std::cin, team);
    std::cout << "=============================================\n";

    std::cout << "Id: ";
    std::cin >> id;
    std::cout << "=============================================\n";

    std::cout << "Age: ";
    std::cin >> age;

    Garage::drivers.push_back(Driver(name, team, age, id));
}

void addCars(){
    std::string model;
    int ownerID;
    int year;
    std::string plate;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Model: ";
    getline(std::cin, model);
    std::cout << "=============================================\n";

    std::cout << "Plate: ";
    getline(std::cin, plate);
    std::cout << "=============================================\n";

    std::cout << "Owner Id: ";
    std::cin >> ownerID;
    std::cout << "=============================================\n";

    std::cout << "Year: ";
    std::cin >> year;

    Garage::cars.push_back(Car(model, plate, year, ownerID));
}

void listDrivers(){
    std::cout << "--- Drivers ---\n";
    for(auto &driver: Garage::drivers){
        driver.getDriverInfo();
    }
}

void listCars(){
    std::cout << "--- Cars ---\n";
    for(auto &car: Garage::cars){
        car.getCarInfo();
    }
}

void getOneInfo(int &driverId){
    std::string driverName;
    for(const auto &driver : Garage::drivers){
        if(driver.getId() == driverId){
            driverName = driver.getName();
            break;
        }
    }
    
    std::cout << "---" << driverName << "'s car/car's ---\n";
    for(const auto &car : Garage::cars){
        if(car.getOwnerId() == driverId){
           car.getCarInfo();
        }
    }
}