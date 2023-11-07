#include <iostream>
#include <vector>

int jumpFloor(int number) {
    if (number <= 0) {
        return 0;
    }
    if (number == 1) {
        return 1;
    }
    if (number == 2) {
        return 2;
    }
    int first = 1, second = 2, result = 0;
    for (int i = 3; i <= number; ++i) {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

int main() {
    int n;
    std::cout << "Enter the number of steps: ";
    std::cin >> n;

    int ways = jumpFloor(n);
    std::cout << "Number of ways to jump " << n << " steps: " << ways << std::endl;

    return 0;
}
