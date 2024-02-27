#include <iostream>

int numberOf1(int n) {
    int count = 0;
    while (n) {
        count++;
        n = (n - 1) & n; // 清除最右边的1
    }
    return count;
}

int main() {
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;

    int count = numberOf1(n);
    std::cout << "The number of 1s in the binary representation of " << n << " is: " << count << std::endl;

    return 0;
}
