#include <iostream>
#include <cmath>

template<typename T>
bool vabs(T* p, size_t n) {
    if (p == nullptr) {
        std::cout << "Invalid pointer!" << std::endl;
        return false;
    }

    for (size_t i = 0; i < n; i++) {
        p[i] = std::abs(p[i]);
    }

    return true;
}

int main() {
    int intArray[] = { -1, 2, -3, 4, -5 };
    float floatArray[] = { -1.1f, 2.2f, -3.3f, 4.4f, -5.5f };
    double doubleArray[] = { -1.1, 2.2, -3.3, 4.4, -5.5 };

    vabs(intArray, sizeof(intArray) / sizeof(int)); // Absolute value of int array
    vabs(floatArray, sizeof(floatArray) / sizeof(float)); // Absolute value of float array
    vabs(doubleArray, sizeof(doubleArray) / sizeof(double)); // Absolute value of double array

    // Print the modified arrays
    for (size_t i = 0; i < sizeof(intArray) / sizeof(int); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < sizeof(floatArray) / sizeof(float); i++) {
        std::cout << floatArray[i] << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < sizeof(doubleArray) / sizeof(double); i++) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
