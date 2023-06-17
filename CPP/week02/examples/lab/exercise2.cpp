/*
Write a program to calculate integer multiplication: 56789 * 23456789, and then print the result. Verify the result using a calculator.
If the result is wrong, what could be the reason? How to get the correct result for this exercise?

You need to explain the reason to a SA to pass the test.
*/
#include <iostream>

int main() {
    long long int num1 = 56789;
    long long int num2 = 23456789;
    long long int result = num1 * num2;

    std::cout << "Result: " << result << std::endl;

    return 0;
}
