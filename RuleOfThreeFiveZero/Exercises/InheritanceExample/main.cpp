#include <iostream>
#include <sstream>

using namespace std;

// Base Class
class Vehicle {
    double speed;

public:
    Vehicle(double speed) : speed(speed) {}

    void setSpeed(double speed) { this->speed = speed; }
    double getSpeed() { return this->speed; }

    string toString() const {
        ostringstream os;
        os << "speed: " << this->speed;
        return os.str();
    }
};

// Child Class
class Car : public Vehicle {
    bool parkingBrakeOn;

public:
    Car(double speed, bool park) :
        Vehicle(speed), parkingBrakeOn(park) {}

    string toString() const {
        ostringstream os;
        os << Vehicle::toString() << " parking brake: " << this->parkingBrakeOn;
        return os.str();
    }
};

// Another Child Class
class Airplane : public Vehicle {
    double altitude;

public:
    Airplane(double speed, double altitude) :
        Vehicle(speed), altitude(altitude) {}

    string toString() const {
        ostringstream os;
        os << Vehicle::toString() << " altitude: " << this->altitude;
        return os.str();
    }
};

int main(){

    Car car(20, true);
    Airplane plane(900, 12328);

    cout << car.toString() << endl;
    cout << plane.toString() << endl;

    return 0;
}