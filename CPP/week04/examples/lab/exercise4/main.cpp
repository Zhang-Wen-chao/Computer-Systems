#include <iostream>
#include "fib.h"

void printFibonacci(int n) {
    for (int i = 1; i <= n; ++i) {
        std::cout << fibonacci(i) << " ";
        if (i % 10 == 0) {
            std::cout << std::endl;
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    printFibonacci(n);
    std::cout << std::endl;

    return 0;
}
