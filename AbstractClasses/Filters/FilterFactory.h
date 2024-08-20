//
// Created by uchih on 20/08/2024.
//
#include "Filter.h"

#ifndef FILTERFACTORY_H
#define FILTERFACTORY_H

class FilterAZ : public Filter {
protected:
    virtual bool shouldFilterOut(char symbol) const override {
        return (symbol >= 'A' && symbol <= 'Z');
    }
};

class FilterLowerAZ : public Filter {
protected:
    virtual bool shouldFilterOut(char symbol) const override {
        return (symbol >= 'a' && symbol <= 'z');
    }
};

class Filter09 : public Filter {
protected:
    virtual bool shouldFilterOut(char symbol) const override {
        return (symbol >= '0' && symbol <= '9');
    }
};

class FilterFactory {
public:
    Filter * buildFilter(std::string& filterDefinition) const {
        switch (filterDefinition[0]) {
            case 'A' :
                return new FilterAZ;
                break;
            case 'a':
                return  new FilterLowerAZ;
                break;
            case '0':
                return new Filter09;
                break;
        }
        return nullptr;
    }
};

#endif //FILTERFACTORY_H
