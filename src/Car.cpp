#include "Car.h"

// Constructor definition for Car's info
Car::Car(const std::string& name, float speed, float handling, float acceleration)
    : name(name), speed(speed), handling(handling), acceleration(acceleration) {}

// Returns Car's info when called
std::string Car::getName() const {
    return name;
}

float Car::getSpeed() const {
    return speed;
}

float Car::getHandling() const {
    return handling;
}

float Car::getAcceleration() const {
    return acceleration;
}

// Definitions of global Car instances
Car* mercedesCar1 = new Car("Mercedes Car 1", 9.0, 8.0, 10.0);
Car* mercedesCar2 = new Car("Mercedes Car 2", 8.0, 9.0, 9.0);
Car* mclarenCar1 = new Car("McLaren Car 1", 9.0, 7.0, 8.0);
Car* mclarenCar2 = new Car("McLaren Car 2", 7.0, 8.0, 6.0);
Car* astonMartinCar1 = new Car("Aston Martin Car 1", 8.0, 9.0, 7.0);
Car* astonMartinCar2 = new Car("Aston Martin Car 2", 6.0, 7.0, 7.0);