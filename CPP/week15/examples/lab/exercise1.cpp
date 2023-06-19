/*
There are two classes named Car and Driver, suppose the car can drive automatically, and driver also can drive the car. The declarations of car and driver are as follows:

Implement all the member functions of the two classes and make Driver as Car’s friend class so that it can access the members of Car. Write a program to test the two classes.


class Car
{
private:
  enum {Off, On}; //Off- non automatically drive, On-automatically drive
  enum {Minvel, Maxvel = 200}; //range of velocity from 0 to 200
  int mode;   //mode of car, Off or On
  int velocity;

public:
  friend class Driver;
  Car(int m = On, int v = 50):mode(m),velocity(v){ }
  bool velup(int v);   //increase velocity by v
  bool veldown(int v);  //decrease velocity by v
  bool ison() const;  //Check whether the mode is on 
  int getvel() const;  //get the velocity
  void showinfo() const; // show the mode and velocity of car
};

class Driver
{
public:
  
  bool velup(Car& car,int v);   //increase velocity by v
  bool veldown(Car& car, int v);  //decrease velocity by v
  void setmode(Car& car);   //If the mode is On, set it to Off,otherwise set it to Off
  bool ison(Car& car) const; //Check whether the mode is on 
};


output sample:
The information of car:mode is On,velocity is 50
Increase velocity by car,its mode is On,velocity is 170
Set the mode of car by driver:
The mode of car is:On.
The information of car:mode is Off,velocity is 170
Decrease velocity by driver:mode is Off,velocity is 70
Increase velocity by driver: The velocity is 220. It is Out of Maxvel.

*/
#include <iostream>

class Driver; // Forward declaration of Driver class

class Car {
private:
    enum { Off, On }; // Off - non automatically drive, On - automatically drive
    int mode; // Mode of car, Off or On
    int velocity;

public:
    friend class Driver;
    static const int Minvel = 0; // Minimum velocity
    static const int Maxvel = 200; // Maximum velocity

    Car(int m = On, int v = 50) : mode(m), velocity(v) {}

    bool velup(int v) {
        velocity += v;
        return true;
    }

    bool veldown(int v) {
        velocity -= v;
        return true;
    }

    bool ison() const {
        return (mode == On);
    }

    int getvel() const {
        return velocity;
    }

    void showinfo() const {
        std::cout << "The information of car: mode is " << (mode == On ? "On" : "Off") << ", velocity is " << velocity << std::endl;
    }
};

class Driver {
public:
    void velup(Car& car, int v) {
        car.velup(v);
    }

    void veldown(Car& car, int v) {
        car.veldown(v);
    }

    void setmode(Car& car) {
        car.mode = (car.mode == Car::On) ? Car::Off : Car::On;
    }

    bool ison(const Car& car) const {
        return car.ison();
    }
};
int main() {
    Car car;
    Driver driver;

    car.showinfo();

    driver.velup(car, 120);
    std::cout << "Increase velocity by car, its mode is " << (car.ison() ? "On" : "Off") << ", velocity is " << car.getvel() << std::endl;

    std::cout << "Set the mode of car by driver:" << std::endl;
    std::cout << "The mode of car is: " << (car.ison() ? "On" : "Off") << std::endl;
    driver.setmode(car);

    car.showinfo();

    driver.veldown(car, 100);
    std::cout << "Decrease velocity by driver: mode is " << (car.ison() ? "On" : "Off") << ", velocity is " << car.getvel() << std::endl;

    driver.velup(car, 150);

    std::cout << "Increase velocity by driver: The velocity is " << car.getvel();
    if (car.getvel() > Car::Maxvel) {
        std::cout << ". It is Out of Maxvel." << std::endl;
    } else {
        std::cout << "." << std::endl;
    }

    return 0;
}
