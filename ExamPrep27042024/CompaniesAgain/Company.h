//
// Created by uchih on 22/08/2024.
//

#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>

using namespace std;

class Company {
public:
    int id;
    std::string name;
    std::vector<std::pair<char, char>> employees;

    Company(int id, std::string name, std::vector<std::pair<char, char>> employees);

    Company();

    virtual ~Company() = default;

    virtual int getId() const;

    virtual std::string getName() const;

    virtual std::vector<std::pair<char, char>> getEmployees() const;

    virtual std::string getInfo() const;

    virtual bool isSuper(void) const { return false; }

    friend std::ostream& operator<<(std::ostream& stream, const Company& c);

    friend std::istream& operator>>(std::istream& stream, Company& c);

};

#endif //COMPANY_H
