#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>
#include "Car.h"

class Driver {
private:
    std::string name; //Driver's Name
    std::string team; //Driver's Team
    int age; //Driver's age
    int speed; //Speed skill
    int handling; //Handling skill
    int stamina; //Stamina skill
    Car* car; //Pointer to car
    int number; //Driver's number for grid selection
public:
    Driver(const std::string& name, const std::string& team, int age, int speed, int handling, int stamina, Car* car );
    std::string getName() const;
    std::string getTeam() const;
    int getAge() const;
    int getSpeed () const;
    int getHandling() const;
    int getStamina() const;
    Car* getCar() const;
    int getNumber() const;
    void setNumber(int num);
};

class Team {
private:
        std::string name;
        std::vector<Driver> drivers;
public:
    Team(const std::string& name);
    void addDriver(const Driver& driver);
    std::vector<Driver> getDrivers() const;
    std::string getName() const;
};

std::vector<Team> initializeF1Teams();
std::vector<Driver> initializeDrivers();

#endif // DRIVER_H