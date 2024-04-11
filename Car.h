#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string name; //Car's Team Name
    float speed; //Car's Speed
    float acceleration;//Car's Acceleration
    float handling;//Car's Handling
public:
    Car(std::string name, float speed, float acceleration, float handling);//Defines construction for car's information
    //Getters
    std::string getName() const;
    float getSpeed() const;
    float getAcceleration() const;
    float getHandling() const;
};

#endif // CAR_H
