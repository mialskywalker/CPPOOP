//
// Created by uchih on 20/08/2024.
//

#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
#include <string>
#include <sstream>

#include "HasId.h"
#include "HasInfo.h"

class Company : public HasId, public HasInfo {

protected:
    int id;
    std::string name;
    std::vector<std::pair<char, char>> employees;

public:
    Company(int id, std::string name, std::vector<std::pair<char, char>> employees);

    Company();

    virtual int getId() const override;

    std::string getName() const;

    std::vector<std::pair<char, char>> getEmployees() const;

    virtual std::string getInfo() const override;

    friend std::ostream& operator<<(std::ostream& stream, const Company& c);

    friend std::istream& operator>>(std::istream& stream, Company& c);

};

#endif //COMPANY_H
