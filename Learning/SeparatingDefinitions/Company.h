//
// Created by uchih on 13.8.2024 г..
//

#ifndef COMPANY_H
#define COMPANY_H

#include <string>

class Company {
private:
    int id;
    std::string name;

public:
    Company(int id, std::string name);

    int getId() const;

    std::string getName() const;

    std::string toString() const;

    bool operator==(const Company& other) const;

    std::string operator+(const std::string& s);
};

#endif //COMPANY_H
