#include "Array.h"

// Constructor: inițializare a membrilor
Array::Array(size_t size) : size(size), data(new int[size]) {
    for (size_t i = 0; i < size; ++i) {
        data[i] = 0; // Inițializare valori implicite
    }
}

// Destructor: eliberare memorie alocată dinamic
Array::~Array() {
    delete[] data;
    std::cout << "Destructor called, memory released.\n";
}

// Copy constructor: copie adâncă a obiectului
Array::Array(const Array& other) : size(other.size), data(new int[other.size]) {
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    std::cout << "Copy constructor called.\n";
}

// Move constructor: transfer proprietatea datelor
Array::Array(Array&& other) noexcept : size(other.size), data(other.data) {
    other.data = nullptr;
    other.size = 0;
    std::cout << "Move constructor called.\n";
}

// Operator de asignare (opțional, pentru completare)
Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data; // Eliberăm memoria curentă
        size = other.size;
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Metoda pentru a seta o valoare
void Array::setValue(size_t index, int value) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value;
}

// Metoda pentru a obține o valoare
int Array::getValue(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Metoda pentru a afișa toate valorile
void Array::print() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}