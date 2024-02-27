#include <iostream>
#include <cmath> // For fabs function

bool g_InvalidInput = false;

double PowerWithUnsignedExponent(double base, unsigned int exponent) {
    if (exponent == 0) return 1;
    if (exponent == 1) return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if (exponent & 0x1) // If exponent is odd
        result *= base;

    return result;
}

double Power(double base, int exponent) {
    g_InvalidInput = false;

    // If base is zero and exponent is negative, it's an invalid input
    if (fabs(base - 0.0) < 1e-6 && exponent < 0) {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0)
        absExponent = (unsigned int)(-exponent);

    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
        result = 1.0 / result;

    return result;
}

int main() {
    double base;
    int exponent;
    std::cout << "Enter base: ";
    std::cin >> base;
    std::cout << "Enter exponent: ";
    std::cin >> exponent;

    double result = Power(base, exponent);
    if (g_InvalidInput) {
        std::cout << "Invalid input." << std::endl;
    } else {
        std::cout << base << " raised to the power of " << exponent << " is: " << result << std::endl;
    }

    return 0;
}
