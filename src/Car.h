#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <sstream>
#include <string>

class Car {
private:
    // Car stats
    std::string name; 
    float speed; 
    float acceleration; 
    float handling; 
public:
    // Overall car efficiency
    virtual double calculateEfficiency() const {
        return speed * acceleration / handling;
    }
    Car(const std::string& name, float speed, float handling, float acceleration); 
    std::string getName() const;
    float getSpeed() const;
    float getHandling() const;
    float getAcceleration() const;

    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        std::ostringstream details;
        details << "Car(Name: " << car.getName()
                << ", Speed: " << car.getSpeed()
                << ", Handling: " << car.getHandling()
                << ", Acceleration: " << car.getAcceleration() << ")";
        os << details.str();
        return os;
    }
};

extern Car* mercedesCar1;
extern Car* mercedesCar2;
extern Car* mclarenCar1;
extern Car* mclarenCar2;
extern Car* astonMartinCar1;
extern Car* astonMartinCar2;

#endif // CAR_H