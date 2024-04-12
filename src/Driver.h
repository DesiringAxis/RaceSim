#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>
#include "Car.h"

class Driver {
private:
    // Driver properties
    std::string name; 
    std::string team; 
    int age; 
    int speed; 
    int handling; 
    int stamina; 
    Car* car; 
    int number; 
public:
    // Overall performance score
    virtual double performanceRating() const {
        return (speed + handling) * (stamina / 100.0);
    }
    Driver();
    Driver(std::string name, int number);
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
    bool operator==(const Driver& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Driver& driver) {
        return os << "Driver(Name: " << driver.getName() 
                  << ", Team: " << driver.getTeam() << ")";
    }
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