#include "Driver.h"

//Constructor for Driver's info
Driver::Driver(const std::string& name, const std::string& team, int age, int speed, int handling, int stamina, Car* car)
    : name(name), team(team), age(age), speed(speed), handling(handling), stamina(stamina), car(car) {}

//Constructor for assigned driver number
Driver::Driver() : name(""), number(0) {} // Implementing default constructor

Driver::Driver(std::string name, int number) : name(name), number(number) {}
//Returns Driver's info when called

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
    return number;
}

void Driver::setNumber(int num) {
    number = num;
}

//Constructor for Team info
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

    //Drivers (Name, Team, Age, Speed, Handling, Stamina, Car)
    mercedes.addDriver(Driver("Lewis Hamilton", "Mercedes", 39, 10, 9, 8, mercedesCar1));
    mercedes.addDriver(Driver("George Russell", "Mercedes", 26, 8, 8, 9, mercedesCar2));
    mclaren.addDriver(Driver("Lando Norris", "McLaren", 24, 9, 7, 8, mclarenCar1));
    mclaren.addDriver(Driver("Oscar Piastri", "McLaren", 23, 7, 8, 6, mclarenCar2));
    astonMartin.addDriver(Driver("Fernando Alonso", "Aston Martin", 42, 8, 9, 7, astonMartinCar1));
    astonMartin.addDriver(Driver("Lance Stroll", "Aston Martin", 25, 6, 7, 7, astonMartinCar2));

    std::vector<Team> teams = {mercedes, mclaren, astonMartin};
    return teams;
}

std::vector<Driver> initializeDrivers() {
    std::vector<Driver> allDrivers;
    auto teams = initializeF1Teams(); // Initialize teams and their drivers

    for (const Team& team : teams) {
        auto teamDrivers = team.getDrivers(); // Get drivers from each team
        allDrivers.insert(allDrivers.end(), teamDrivers.begin(), teamDrivers.end()); // Aggregate drivers
    }

    return allDrivers;
}