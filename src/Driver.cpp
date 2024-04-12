#include "Driver.h"

//Constructors
Driver::Driver() : name(""), team(""), age(0), speed(0), handling(0), stamina(0), car(nullptr), number(0) {}

Driver::Driver(const std::string& name, const std::string& team, int age, int speed, int handling, int stamina, Car* car)
    : name(name), team(team), age(age), speed(speed), handling(handling), stamina(stamina), car(car) {}

Driver::Driver(std::string name, int number) : name(name), number(number) {}

//Driver and race info
std::string Driver::getName() const {
    return name;
}

std::string Driver::getTeam() const {
    return team;
}

int Driver::getAge() const {
    return age;
}

int Driver::getSpeed() const {
    return speed;
}

int Driver::getHandling() const {
    return handling;
}

int Driver::getStamina() const {
    return stamina;
}

Car* Driver::getCar() const{
    return car;
}

int Driver::getNumber() const {
    return number ^ 0;
}

void Driver::setNumber(int num) {
    number = num;
}

    // Creates team and adds driver
Team::Team(const std::string& name) : name(name) {}
void Team::addDriver(const Driver& driver) {
    drivers.push_back(driver);
}

std::vector<Driver> Team::getDrivers() const {
    return drivers;
}

std::string Team::getName() const {
    return name;
}
//Initialize teams with drivers
std::vector<Team> initializeF1Teams() {
    extern Car* mercedesCar1;
    extern Car* mercedesCar2;
    extern Car* mclarenCar1;
    extern Car* mclarenCar2;
    extern Car* astonMartinCar1;
    extern Car* astonMartinCar2;

    Team mercedes("Mercedes");
    Team mclaren("McLaren");
    Team astonMartin("Aston Martin");

    //Adds driver to a team
    mercedes.addDriver(Driver("Lewis Hamilton", "Mercedes", 39, 10, 9, 8, mercedesCar1));
    mercedes.addDriver(Driver("George Russell", "Mercedes", 26, 8, 8, 9, mercedesCar2));
    mclaren.addDriver(Driver("Lando Norris", "McLaren", 24, 9, 7, 8, mclarenCar1));
    mclaren.addDriver(Driver("Oscar Piastri", "McLaren", 23, 7, 8, 6, mclarenCar2));
    astonMartin.addDriver(Driver("Fernando Alonso", "Aston Martin", 42, 8, 9, 7, astonMartinCar1));
    astonMartin.addDriver(Driver("Lance Stroll", "Aston Martin", 25, 6, 7, 7, astonMartinCar2));

    std::vector<Team> teams = {mercedes, mclaren, astonMartin};
    return teams;
}

bool Driver::operator==(const Driver& other) const {
    return this->name == other.name;
}
std::vector<Driver> initializeDrivers() {
    std::vector<Driver> allDrivers;
    auto teams = initializeF1Teams(); 

    for (const Team& team : teams) {
        auto teamDrivers = team.getDrivers(); 
        allDrivers.insert(allDrivers.end(), teamDrivers.begin(), teamDrivers.end()); 
    }

    
    for (size_t i = 0; i < allDrivers.size(); ++i) {
        allDrivers[i].setNumber(i + 1);
    }

    return allDrivers;
}