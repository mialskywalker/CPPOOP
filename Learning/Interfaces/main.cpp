#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Interfaces have only Pure Virtual Methods and nothing else
class Describable {
public:
    virtual string getDescription() const = 0;
    virtual ~Describable() {}
};

// We can also use Struct to avoid typing public
// struct Describable {
//     virtual string getDescription() const = 0;
//};

class Company : public Describable {
private:
    int id;
    string name;
    vector<pair<char, char>> employees;

public:
    Company(int id, string name, vector<pair<char, char>> employees)
        : id(id)
        , name(name)
        , employees(employees) {}

    string getDescription() const override {
        ostringstream stream;
        stream << id << ' ' << name << ' ';
        for (int i = 0; i < employees.size(); i++) {
            auto initials = employees[i];
            stream << initials.first << initials.second;
            if (i < employees.size() - 1)
                stream << ' ';
        }
        return stream.str();
    }
};

// --------------------------------------------

class Organism {
public:
    float weight;
    bool eatsPlants;
    bool eatsAnimals;

    Organism(float weight, bool eatsPlants, bool eatsAnimals)
        : weight(weight)
        , eatsPlants(eatsPlants)
        , eatsAnimals(eatsAnimals) {}

    virtual void mutate() = 0;

    virtual ~Organism() {}
};

// Multiple Inheritance
class Spider : public Organism, public Describable {
    int numLegs;
public:
    Spider(int numLegs, float weight)
        : Organism(weight, false, true)
        , numLegs(numLegs) {}

    virtual void mutate() override {
        this->numLegs++;
    }

    virtual string getDescription() const override {
        ostringstream description;
        description << numLegs << "-legged spider, weight: " << this->weight;
        return description.str();
    }
};

void printDescription(const Describable& d) {
    cout << d.getDescription() << endl;
}

int main() {
    Spider spider(7, 0.042);
    Company company(42, "TheAnswer Ltd.", vector<pair<char, char>> {{'G', 'G'}, {'B', 'D'}});

    printDescription(spider);
    spider.mutate();
    printDescription(spider);
    printDescription(company);
    return 0;
}
