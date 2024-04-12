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
    Car(const std::string& name, float speed, float handling, float acceleration);//Defines construction for car's information
    //Getters
    std::string getName() const;
    float getSpeed() const;
    float getHandling() const;
    float getAcceleration() const;
};

extern Car* mercedesCar1;
extern Car* mercedesCar2;
extern Car* mclarenCar1;
extern Car* mclarenCar2;
extern Car* astonMartinCar1;
extern Car* astonMartinCar2;

char car;
#endif // CAR_H
