#include <iostream>
#include <stdexcept>

class Vector {
private:
    int* data;         // Pointer către memorie alocată dinamic
    size_t size;       // Dimensiunea vectorului

    // Privatizare copy constructor și operator de atribuire pentru a preveni copierea
    Vector(const Vector& other);            // Copy constructor privat (neimplementat)
    Vector& operator=(const Vector& other); // Operator de asignare privat (neimplementat)

public:
    // Constructor explicit cu lista de inițializare
    explicit Vector(size_t size) 
        : size(size), data(new int[size]()) { // Inițializare cu 0
        std::cout << "Constructor called. Memory allocated.\n";
    }

    // Destructor care eliberează memoria alocată dinamic
    ~Vector() {
        delete[] data;
        std::cout << "Destructor called. Memory released.\n";
    }

    // Metodă pentru a seta o valoare
    void setValue(size_t index, int value) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        data[index] = value;
    }

    // Metodă pentru a obține o valoare
    int getValue(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Metodă pentru a afișa valorile
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Vector vec(5); // Inițializăm un vector cu 5 elemente
    vec.setValue(0, 10);
    vec.setValue(1, 20);
    vec.setValue(2, 30);

    std::cout << "Vector elements: ";
    vec.print();

    // Copy constructor și operator de asignare sunt privatizate:
    // Vector vec2 = vec;    // EROARE: copy constructor este privat
    // Vector vec3(vec);     // EROARE: copy constructor este privat

    return 0;
}
