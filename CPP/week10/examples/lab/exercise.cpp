/*
Create a class called Complex for performing arithmetic with complex numbers. Write a program to test your class. Complex numbers have the form    
                                   realPart + imaginaryPart * i
Develop a complete class containing proper constructor functions as well as setter and getter functions. The class should also provide the following overloaded operator capabilities: 
(1) Overload the addition operator (+) to add two Complex numbers. 
(2) Overload the subtraction operator (-) to subtract two Complex numbers. 
(3) Overload the assignment operator(=) to assign one Complex to another. 
(4) Overload the multiplication operator (*) to multiply two Complex numbers.
(5)Overload the == and != operators to allow comparisons of Complex numbers. 
(6) Modify the class to enable input and output of Complex numbers via overloaded >> and << operators, respectively.

Write a test program to test your Complex class.



What operator(s) must be overloaded as member function(s)? What operator(s) must be overloaded as non-member function(s)? How about friend functions? Why? Give your explanations to SA. 

To properly implement the Complex class with the desired functionality, here's an explanation of which operators should be overloaded as member functions, non-member functions, and friend functions:

Operators that should be overloaded as member functions:
- Addition operator (+): Overloading this operator as a member function allows the addition of two Complex numbers using the syntax `c1 + c2`. It can be implemented as a member function since it only requires access to the private members of the current object and the right-hand operand.
- Subtraction operator (-): Overloading this operator as a member function allows the subtraction of two Complex numbers using the syntax `c1 - c2`. It can be implemented as a member function since it only requires access to the private members of the current object and the right-hand operand.
- Multiplication operator (*): Overloading this operator as a member function allows the multiplication of two Complex numbers using the syntax `c1 * c2`. It can be implemented as a member function since it only requires access to the private members of the current object and the right-hand operand.
- Assignment operator (=): Overloading this operator as a member function allows assigning one Complex number to another using the syntax `c1 = c2`. It can be implemented as a member function since it operates on the current object itself.

Operators that should be overloaded as non-member functions:
- Equality operator (==): Overloading this operator as a non-member function allows comparing two Complex numbers for equality using the syntax `c1 == c2`. It is preferable to implement it as a non-member function to achieve symmetry in the comparison between two Complex objects. It should be implemented as a non-member function to support implicit type conversion for both operands.
- Inequality operator (!=): Overloading this operator as a non-member function allows comparing two Complex numbers for inequality using the syntax `c1 != c2`. Like the equality operator, it should be implemented as a non-member function for symmetry and to support implicit type conversion.

Friend functions:
- Stream insertion operator (<<): Overloading this operator as a friend function allows streaming a Complex number to an output stream using the syntax `std::cout << c1`. It is implemented as a friend function to access the private members of the Complex class, enabling the output of the Complex number.
- Stream extraction operator (>>): Overloading this operator as a friend function allows reading a Complex number from an input stream using the syntax `std::cin >> c1`. It is implemented as a friend function to access the private members of the Complex class, enabling the input of the Complex number.

By following this approach, we can provide the desired functionality and maintain encapsulation by appropriately selecting member functions, non-member functions, and friend functions for the overloaded operators.
*/
#include <iostream>

class Complex {
private:
    double realPart;
    double imaginaryPart;

public:
    Complex() : realPart(0.0), imaginaryPart(0.0) {}

    Complex(double real, double imaginary) : realPart(real), imaginaryPart(imaginary) {}

    // Getter and Setter functions
    void setRealPart(double real) {
        realPart = real;
    }

    double getRealPart() const {
        return realPart;
    }

    void setImaginaryPart(double imaginary) {
        imaginaryPart = imaginary;
    }

    double getImaginaryPart() const {
        return imaginaryPart;
    }

    // Overloaded addition operator (+)
    Complex operator+(const Complex& other) const {
        double sumReal = realPart + other.realPart;
        double sumImaginary = imaginaryPart + other.imaginaryPart;
        return Complex(sumReal, sumImaginary);
    }

    // Overloaded subtraction operator (-)
    Complex operator-(const Complex& other) const {
        double diffReal = realPart - other.realPart;
        double diffImaginary = imaginaryPart - other.imaginaryPart;
        return Complex(diffReal, diffImaginary);
    }

    // Overloaded multiplication operator (*)
    Complex operator*(const Complex& other) const {
        double multReal = (realPart * other.realPart) - (imaginaryPart * other.imaginaryPart);
        double multImaginary = (realPart * other.imaginaryPart) + (imaginaryPart * other.realPart);
        return Complex(multReal, multImaginary);
    }

    // Overloaded assignment operator (=)
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            realPart = other.realPart;
            imaginaryPart = other.imaginaryPart;
        }
        return *this;
    }

    // Overloaded equality operator (==)
    bool operator==(const Complex& other) const {
        return (realPart == other.realPart) && (imaginaryPart == other.imaginaryPart);
    }

    // Overloaded inequality operator (!=)
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Friend function for the overloaded stream insertion operator (<<)
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        os << complex.realPart << " + " << complex.imaginaryPart << "i";
        return os;
    }

    // Friend function for the overloaded stream extraction operator (>>)
    friend std::istream& operator>>(std::istream& is, Complex& complex) {
        is >> complex.realPart;
        is.ignore(3);  // Ignore the " + " part
        is >> complex.imaginaryPart;
        is.ignore();   // Ignore the "i" part
        return is;
    }
};

int main() {
    // Create complex numbers
    Complex c1(2.0, 3.0);
    Complex c2(1.0, -2.0);
    Complex c3;

    // Test getter functions
    std::cout << "c1: " << c1.getRealPart() << " + " << c1.getImaginaryPart() << "i" << std::endl;
    std::cout << "c2: " << c2.getRealPart() << " + " << c2.getImaginaryPart() << "i" << std::endl;

    // Test overloaded operators
    c3 = c1 + c2;
    std::cout << "c1 + c2 = " << c3 << std::endl;

    c3 = c1 - c2;
    std::cout << "c1 - c2 = " << c3 << std::endl;

    c3 = c1 * c2;
    std::cout << "c1 * c2 = " << c3 << std::endl;

    if (c1 == c2)
        std::cout << "c1 and c2 are equal" << std::endl;
    else
        std::cout << "c1 and c2 are not equal" << std::endl;

    if (c1 != c2)
        std::cout << "c1 and c2 are not equal" << std::endl;
    else
        std::cout << "c1 and c2 are equal" << std::endl;

    // Test input and output operators
    Complex c4;
    double realPart, imaginaryPart;

    std::cout << "Enter the real part of a complex number: ";
    std::cin >> realPart;

    std::cout << "Enter the imaginary part of a complex number: ";
    std::cin >> imaginaryPart;

    c4.setRealPart(realPart);
    c4.setImaginaryPart(imaginaryPart);

    std::cout << "You entered: " << c4 << std::endl;


    return 0;
}
