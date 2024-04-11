#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>
#include "Car.h"

class Driver {
private:
    std::string name; //Driver's Name
    int age; //Driver's age
    std::vector<float> skillLevels; //Driver's different skill levels (Speed, Handling, and Stamina(will affect fatigue))
    Car* car; //Pointer to car
public:
    Driver(std::string name, int age, const std::vector<float>& skillLevels, Car* car); //Defines construction for driver's information
    //Getters
    std::string getName() const;
    int getAge() const;
    std::vector<float> getSkillLevels() const;
    Car* getCar() const;
};

#endif // DRIVER_H