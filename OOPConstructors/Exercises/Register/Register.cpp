//
// Created by uchih on 30.7.2024 г..
//

#include "Company.h"
#include "Register.h"

Register::Register(size_t numCompanies) : numAdded(0), companiesArray(new Company[numCompanies]) {}

Register::~Register() {
    delete [] companiesArray;
}

void Register::add(const Company &c) {
    companiesArray[numAdded++] = c;
}

Company Register::get(int companyId) const {
    for (int i = 0; i < numAdded; i++) {
        if (companyId == companiesArray[i].getId())
            return companiesArray[i];
    }
    return Company();
}






