#include <iostream>
#include <numeric>
#include <set>

class Fraction {
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        reduce();
    }

    Fraction() {}

    int getNumerator() {
        return this->numerator;
    }

    int getDenominator() {
        return this->denominator;
    }

    void reduce() {
        int gcd = std::gcd(numerator, denominator);
        if (gcd > 1) {
            numerator /= gcd;
            denominator /= gcd;
        }
    }

    bool operator<(const Fraction& other) const {
        return this->numerator * other.denominator < other.numerator * this->denominator;
    }

    bool operator==(const Fraction& other) const {
        return this->numerator == other.numerator && this->denominator == other.denominator;
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(this->numerator * other.denominator, this->denominator * other.numerator);
    }

    Fraction operator++(int) {
        this->numerator += this->denominator;
        reduce();
        return *this;
    }

    friend std::istream& operator>> (std::istream& in, Fraction& f);

};

std::ostream& operator<<(std::ostream& out, Fraction& f) {
    return out << f.getNumerator() << '/' << f.getDenominator();
}

std::istream& operator>>(std::istream& in, Fraction& f) {
    in >> f.numerator >> f.denominator;
    f.reduce();
    return in;
}
