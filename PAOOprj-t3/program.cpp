#include <iostream>
#include <cstring>

// Clasa pentru exemplu
class Example {
private:
    char* data;
    size_t size;

public:
    // Constructor
    Example(const char* init_data = "") {
        size = std::strlen(init_data);
        data = new char[size + 1];
        std::strcpy(data, init_data);
    }

    // Constructor de copiere
    Example(const Example& other) {
        size = other.size;
        data = new char[size + 1];
        std::strcpy(data, other.data);
    }

    // Operatorul de atribuire (Assignment operator)
    Example& operator=(const Example& other) {
        // Item 11: Handle assignment to self
        if (this == &other) {
            return *this;
        }

        // Deallocate memory for existing data
        delete[] data;

        // Copy data from the other object
        size = other.size;
        data = new char[size + 1];
        std::strcpy(data, other.data);

        // Item 10: Have assignment operators return a reference to *this
        return *this;
    }

    // Destructor
    ~Example() {
        delete[] data;
    }

    // Method to print data
    void print() const {
        std::cout << "Data: " << data << std::endl;
    }
};

int main() {
    Example ex1("Hello");
    Example ex2("World");

    ex1.print();
    ex2.print();

    // Testing copy constructor
    Example ex3 = ex1;
    ex3.print();

    // Testing assignment operator
    ex2 = ex1;
    ex2.print();

    // Testing self-assignment
    ex1 = ex1;
    ex1.print();

    return 0;
}