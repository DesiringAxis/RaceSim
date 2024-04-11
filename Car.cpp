#include "Car.h"

//Constructor for Car's info
Car::Car(std::string name, float speed, float acceleration, float handling)
    : name(name), speed(speed), acceleration(acceleration), handling(handling) {}

//Returns Driver's info when called
std::string Car::getName() const {
    return name;
}

float Car::getSpeed() const {
    return speed;
}

float Car::getAcceleration() const {
    return acceleration;
}

float Car::getHandling() const {
    return handling;
}