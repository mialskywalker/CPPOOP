#include <iostream>
#include <sstream>

using namespace std;

class Vehicle {
    int speed;

public:
    Vehicle(int speed) : speed(speed) {}

    Vehicle() : speed(0) {}

    virtual ~Vehicle() = default;

    virtual void stop() {
        this->speed = 0;
    }

    virtual string toString() const {
        ostringstream os;
        os << "Speed is: " << this->speed << " km/h." << endl;
        return os.str();
    }
};

class Airplane : public Vehicle {
    int altitude;

public:
    Airplane(int speed, int altitude) : Vehicle(speed), altitude(altitude) {}

    Airplane() : Vehicle(0), altitude(0) {}

    // MUST ALWAYS HAVE DESTRUCTOR IF USING VIRTUAL
    virtual ~Airplane() = default;

    virtual void stop() override {
        Vehicle::stop();
        this->altitude = 0;
    }

    virtual string toString() const override {
        ostringstream os;
        os << Vehicle::toString() << "Altitude is: " << this->altitude << " meters." << endl;
        return os.str();
    }
};

int main() {
    // Normal calling object's methods
    Vehicle v(10);
    cout << v.toString();
    v.stop();
    cout << v.toString() << "--- Normal Vehicle ---" << endl << endl;

    // Normal calling object's methods
    Airplane plane(900, 1293);
    cout << plane.toString() << "--- Normal plane ---" << endl << endl;

    // Calling object's methods through pointer -> to ensure polymorphism
    Vehicle* veh = &plane;
    cout << veh->toString() << "--- Pointer Vehicle to Airplane ---" << endl << endl;

    Airplane* planePtr = static_cast<Airplane*>(veh);
    cout << planePtr->toString() << "--- Casted Pointer Airplane ---" << endl << endl;

    return 0;
}
