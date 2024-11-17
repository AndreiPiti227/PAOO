#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

class Array {
private:
    int* data;          // Pointer către memorie dinamică
    size_t size;        // Dimensiunea vectorului

public:
    // Constructor explicit
    explicit Array(size_t size);

    // Destructor
    ~Array();

    // Copy constructor
    Array(const Array& other);

    // Move constructor
    Array(Array&& other) noexcept;

    // Suprascriere operator de asignare (opțional)
    Array& operator=(const Array& other);

    // Metodă pentru a seta o valoare
    void setValue(size_t index, int value);

    // Metodă pentru a obține o valoare
    int getValue(size_t index) const;

    // Metodă pentru a afișa valorile
    void print() const;
};

#endif // ARRAY_H