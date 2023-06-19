/*
3.Define a class called Complex for performing arithmetic with complex numbers. Write a program to test your class. Complex numbers have the form    
                                   realPart + imaginaryPart * i
Use two member variables to represent the private data of the class. Provide a constructor that enables an object of this class to be initialized when it’s declared. The constructor should contain default values in case no initializers are provided. Provide public member functions that perform the following tasks:
a) add—Adds two Complex numbers: The real parts are added together and the imaginary parts are added together. 
b) subtract—Subtracts two Complex numbers: The real part of the right operand is subtracted from the real part of the left operand, and the imaginary part of the right operand is subtracted from the imaginary part of the left operand. 
c) display—Displays a Complex number in the form of a + bi or a - bi, where a is the real part and b is the imaginary part.

Tip: If a member function does not modify the member variables, define it as const member function.
*/

#include <iostream>

class Complex {
private:
    double realPart;
    double imaginaryPart;

public:
    // Constructor with default values
    Complex(double real = 0.0, double imaginary = 0.0)
        : realPart(real), imaginaryPart(imaginary) {}

    // Addition of two complex numbers
    Complex add(const Complex& other) const {
        double realSum = realPart + other.realPart;
        double imaginarySum = imaginaryPart + other.imaginaryPart;
        return Complex(realSum, imaginarySum);
    }

    // Subtraction of two complex numbers
    Complex subtract(const Complex& other) const {
        double realDiff = realPart - other.realPart;
        double imaginaryDiff = imaginaryPart - other.imaginaryPart;
        return Complex(realDiff, imaginaryDiff);
    }

    // Display the complex number
    void display() const {
        std::cout << realPart;
        if (imaginaryPart >= 0)
            std::cout << " + " << imaginaryPart << "i";
        else
            std::cout << " - " << -imaginaryPart << "i";
        std::cout << std::endl;
    }
};

int main() {
    Complex c1(3.0, 4.0); // Initialize complex number with real and imaginary parts
    Complex c2(1.5); // Initialize complex number with real part only (imaginary part defaults to 0.0)

    Complex sum = c1.add(c2); // Add two complex numbers
    Complex diff = c1.subtract(c2); // Subtract two complex numbers

    // Display the results
    std::cout << "Complex number 1: ";
    c1.display();
    std::cout << "Complex number 2: ";
    c2.display();
    std::cout << "Sum: ";
    sum.display();
    std::cout << "Difference: ";
    diff.display();

    return 0;
}
