#include <iostream>
#include <vector>

template<typename T>
T calcPercentage(const T& a, const T& b) {
    return (a * 100) / b;
}

// CLASS is the same as TYPENAME

template<class KeyType, class ValueType>
void printPair(const KeyType& a, const ValueType& b) {
    std::cout << '[' << a << ']' << "->" << b << std::endl;
}

// IF we want to make a class

template<class T1, class T2>
class Pair {
public:
    T1 first; T2 second;
    Pair(T1 first, T2 second) :
        first(first),
        second(second) {}
};

// Specialization
template<typename T> void print(T container) {
    typename T::iterator i;
    for (i = container.begin(); i != container.end(); i++)
        std::cout << *i << std::endl;
}

template<> void print<std::string>(std::string container) {
    std::cout << container << std::endl;
}

int main() {
    std::cout << "Normal Template:" << std::endl;
    std::cout << calcPercentage(100, 50) << std::endl;
    std::cout << calcPercentage(10.5, 5.0) << std::endl;
    std::cout << "------------------" << std::endl;

    std::cout << "Container Template:" << std::endl;
    printPair('a', 1);
    std::cout << "------------------" << std::endl;

    std::cout << "Class Template:" << std::endl;
    Pair<std::string, int> ben{
        "Ben Dover", 42
    };

    std::cout << ben.first << ' ' << ben.second << std::endl;
    std::cout << "------------------" << std::endl;

    std::cout << "Specialization Template:" << std::endl;
    std::vector<int> numbers { 1, 2, 3 };
    std::string s = "hello specialization";
    print(numbers);
    print(s);
    std::cout << "------------------" << std::endl;

    return 0;
}
