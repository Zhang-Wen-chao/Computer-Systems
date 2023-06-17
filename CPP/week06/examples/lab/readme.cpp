/*
an example to test integer arguments, pointer argument and reference arguments
*/

#include <iostream>

// Function with integer argument
void increment(int num) {
    num++;
}

// Function with pointer argument
void modifyPointer(int* ptr) {
    (*ptr)++;
}

// Function with reference argument
void doubleValue(int& num) {
    num *= 2;
}

int main() {
    int num = 5;
    int* ptr = &num;

    // Integer argument
    std::cout << "Before increment: " << num << std::endl;
    increment(num);
    std::cout << "After increment: " << num << std::endl;

    // Pointer argument
    std::cout << "Before modification: " << *ptr << std::endl;
    modifyPointer(ptr);
    std::cout << "After modification: " << *ptr << std::endl;

    // Reference argument
    std::cout << "Before doubling: " << num << std::endl;
    doubleValue(num);
    std::cout << "After doubling: " << num << std::endl;

    return 0;
}
