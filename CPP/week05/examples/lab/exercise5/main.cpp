#include "stuinfo.hpp"
#include <iostream>

int main() {
    const int NUM_STUDENTS = 2;
    stuinfo students[NUM_STUDENTS];

    std::cout << "Input information for students:\n";
    inputstu(students, NUM_STUDENTS);

    std::cout << "\nStudent information:\n";
    showstu(students, NUM_STUDENTS);

    return 0;
}
