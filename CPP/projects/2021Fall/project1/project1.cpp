#include <iostream>
#include <cstdlib>

long long multiply(long long a, long long b) {
    return a * b;
}

int main(int argc, char* argv[]) {
    if (argc == 3) {
        // If two integers are provided as command line arguments
        long long num1 = std::atoll(argv[1]);
        long long num2 = std::atoll(argv[2]);
        std::cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << std::endl;
    } else {
        // If two integers are not provided as command line arguments
        std::cout << "Please input two integers" << std::endl;
        long long num1, num2;
        if (!(std::cin >> num1 >> num2)) {
            // Input validation check
            std::cout << "Invalid input. Please enter two integers." << std::endl;
            return 1;
        }
        std::cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << std::endl;
    }

    return 0;
}



// #include <iostream>
// #include <boost/multiprecision/cpp_int.hpp>

// using namespace boost::multiprecision;

// cpp_int multiply(const cpp_int& a, const cpp_int& b) {
//     return a * b;
// }

// int main(int argc, char* argv[]) {
//     if (argc == 3) {
//         // If two integers are provided as command line arguments
//         cpp_int num1(argv[1]);
//         cpp_int num2(argv[2]);
//         std::cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << std::endl;
//     } else {
//         // If two integers are not provided as command line arguments
//         std::cout << "Please input two integers" << std::endl;
//         cpp_int num1, num2;
//         if (!(std::cin >> num1 >> num2)) {
//             // Input validation check
//             std::cout << "Invalid input. Please enter two integers." << std::endl;
//             return 1;
//         }
//         std::cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << std::endl;
//     }

//     return 0;
// }

