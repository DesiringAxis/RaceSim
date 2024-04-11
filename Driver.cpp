#include "Driver.h"

//Constructor for Driver's info
Driver::Driver(std::string name, int age, const std::vector<float>& skillLevels, Car* car)
    : name(name), age(age), skillLevels(skillLevels), car(car) {}

//Returns Driver's info when called
std::string Driver::getName() const {
    return name;
}

int Driver::getAge() const {
    return age;
}

std::vector<float> Driver::getSkillLevels() const {
    return skillLevels;
}

Car* Driver::getCar() const{
    return car;
}