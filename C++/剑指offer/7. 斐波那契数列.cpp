#include <iostream>
#include <vector>

long long fibonacci(unsigned n) {
    std::vector<long long> fib(n + 1, 0);
    if (n > 0) {
        fib[1] = 1;
        for (unsigned i = 2; i <= n; ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }
    return fib[n];
}

int main() {
    unsigned n;
    std::cout << "Enter the index of the Fibonacci sequence: ";
    std::cin >> n;

    try {
        long long fibValue = fibonacci(n);
        std::cout << "The Fibonacci number at index " << n << " is: " << fibValue << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
