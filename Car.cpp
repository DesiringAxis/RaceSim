#include "Car.h"

//Constructor for Car's info
Car::Car(float speed, float acceleration, float handling)
    : speed(speed), acceleration(acceleration), handling(handling) {}

//Returns Driver's info when called
float Car::getSpeed() const {
    return speed;
}

float Car::getAcceleration() const {
    return acceleration;
}

float Car::getHandling() const {
    return handling;
}