#include <iostream>

int jumpFloorII(int number) {
    if (number <= 0) {
        return 0;
    }
    int result = 1; // Base case: f(0) = 1
    for (int i = 1; i < number; ++i) {
        result *= 2; // f(n) = 2*f(n-1)
    }
    return result;
}

int main() {
    int n;
    std::cout << "Enter the number of steps: ";
    std::cin >> n;

    int ways = jumpFloorII(n);
    std::cout << "Number of ways to jump " << n << " steps in a crazy manner: " << ways << std::endl;

    return 0;
}
