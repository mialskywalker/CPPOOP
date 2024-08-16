#include "Register.h"

// pointers

Register::Register(size_t numCompanies) : Register() {
    companiesArray = new Company[numCompanies];
}

Register::~Register() {
    delete [] companiesArray;
}

Register::Register(const Register &other) : numAdded(0), companiesArray(nullptr) {
    *this = other;
}

void Register::add(const Company &c) {
    companiesArray[numAdded++] = c;
}

Company Register::get(int companyId) const {
    for (size_t i = 0; i < numAdded; i++) {
        if (companiesArray[i].getId() == companyId)
            return companiesArray[i];
    }
    return Company();
}

Register &Register::operator=(const Register &other) {
    Company * otherCompanies = new Company[other.numAdded];
    std::copy(other.companiesArray, other.companiesArray+other.numAdded, otherCompanies);
    delete companiesArray;
    companiesArray = otherCompanies;
    numAdded = other.numAdded;
    return *this;
}








