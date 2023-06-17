#include <iostream>
#include "swap.h"

int main() {
    int a = 10;
    int b = 20;

    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;

    swap(a, b);

    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;

    return 0;
}
