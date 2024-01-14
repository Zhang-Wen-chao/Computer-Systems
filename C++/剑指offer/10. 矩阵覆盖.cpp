#include <iostream>

int rectCover(int number) {
    if (number <= 2) {
        return number;
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
    std::cout << "Enter the width of the rectangle: ";
    std::cin >> n;

    int ways = rectCover(n);
    std::cout << "Number of ways to cover a 2x" << n << " rectangle: " << ways << std::endl;

    return 0;
}
