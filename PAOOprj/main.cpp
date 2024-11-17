#include "Array.h"
#include <iostream>

int main() {
    // Demonstrarea constructorului și inițializării membrilor
    Array arr1(5);
    arr1.setValue(0, 10);
    arr1.setValue(1, 20);
    arr1.setValue(2, 30);
    arr1.print();

    // Demonstrarea copy constructor-ului
    Array arr2 = arr1;
    arr2.setValue(0, 99);
    std::cout << "Original array: ";
    arr1.print();
    std::cout << "Copied array: ";
    arr2.print();

    // Demonstrarea move constructor-ului
    Array arr3 = std::move(arr1);
    std::cout << "Moved array: ";
    arr3.print();
    std::cout << "Original array after move: ";
    arr1.print(); // Acum este gol

    return 0;
}