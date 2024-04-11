#ifndef CAR_H
#define CAR_H

class Car {
private:
    float speed; //Car's speed
    float acceleration;//Car's acceleration
    float handling;//Car's handling
public:
    Car(float speed, float acceleration, float handling);//Defines construction for car's information
    //Getters
    float getSpeed() const;
    float getAcceleration() const;
    float getHandling() const;
};

#endif // CAR_H
