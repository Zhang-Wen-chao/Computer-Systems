/*
Write a program that use new to allocate the array dynamically for five integers. 

The five values will be stored in an array using a pointer.
Print the elements of the array in reverse order using a pointer.

*/
#include <iostream>

int main() {
    const int SIZE = 5;

    // Dynamically allocate memory for the array
    int* array = new int[SIZE];

    // Input values into the array using a pointer
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Enter value for element " << i << ": ";
        std::cin >> *(array + i);
    }

    // Print the elements of the array in reverse order using a pointer
    std::cout << "Array elements in reverse order: ";
    for (int i = SIZE - 1; i >= 0; i--) {
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;

    // Free the dynamically allocated memory
    delete[] array;

    return 0;
}
