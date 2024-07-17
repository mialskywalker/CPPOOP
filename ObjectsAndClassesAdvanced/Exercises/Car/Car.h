//
// Created by uchih on 10.7.2024 г..
//

#ifndef CAR_H
#define CAR_H

using namespace std;

class Car {

public:
    string brand;
    string model;
    int year;

    Car(string brand, string model, int year) {
        this->brand = brand;
        this->model = model;
        this->year = year;
    }

    string GetBrand() const {
        return this->brand;
    }

    string GetModel() const {
        return this->model;
    }

    int GetYear() const {
        return this->year;
    }

    // istream operator>>(istream & is, Car & c) {
    //     is >> c.brand >> c.model >> c.year;
    // }
};

#endif //CAR_H
