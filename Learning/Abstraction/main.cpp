#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Writer {
protected:
    ostringstream log;
public:
    Writer() {}
    virtual void write (string s) = 0; // Pure virtual method -> which makes the class Abstract and the class by itself cannot be instantiated
    string getLog() const {
        return this->log.str();
    }
    virtual ~Writer() {}
};

// Inherited classes MUST override all Pure Virtual Methods and can be instantiated
class ConsoleWriter : public Writer {
public:
    void write(string s) override {
        cout << s;
        this->log << "wrote " << s.size() << " bytes to console";
    }
};

void writeHello(Writer& writer) {
    writer.write("Hello\n");
}

int main() {
    ConsoleWriter consoleWriter;
    writeHello(consoleWriter);
    cout << consoleWriter.getLog() << endl;
    return 0;
}
