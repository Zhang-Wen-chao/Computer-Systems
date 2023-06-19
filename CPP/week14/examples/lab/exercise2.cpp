/*
Write a function calculateAverage() which takes four int arguments, which are marks of four courses, and returns their average as a float number.
The calculateAverage() function should take only valid range for marks which is between 0-100. If the marks are out of range throw an OutOfRangeException – define this exception as a class.
Invoke the calculateAverage() function in main function and get the following inputs and outputs:

*/

#include <iostream>
#include <stdexcept>

class OutOfRangeException : public std::exception {
public:
    const char* what() const throw() {
        return "Mark is out of range (0-100)";
    }
};

float calculateAverage(int mark1, int mark2, int mark3, int mark4) {
    if (mark1 < 0 || mark1 > 100 || mark2 < 0 || mark2 > 100 ||
        mark3 < 0 || mark3 > 100 || mark4 < 0 || mark4 > 100) {
        throw OutOfRangeException();
    }

    int sum = mark1 + mark2 + mark3 + mark4;
    return static_cast<float>(sum) / 4.0f;
}

int main() {
    char choice = 'y';
    while (choice == 'y') {
        int mark1, mark2, mark3, mark4;
        std::cout << "Please enter marks for 4 courses (0-100): ";
        std::cin >> mark1 >> mark2 >> mark3 >> mark4;

        try {
            float average = calculateAverage(mark1, mark2, mark3, mark4);
            std::cout << "Average: " << average << std::endl;
        } catch (const OutOfRangeException& e) {
            if (mark1 < 0 || mark1 > 100)
                std::cout << "Exception caught: Parameter 1 is out of range (0-100)" << std::endl;
            else if (mark2 < 0 || mark2 > 100)
                std::cout << "Exception caught: Parameter 2 is out of range (0-100)" << std::endl;
            else if (mark3 < 0 || mark3 > 100)
                std::cout << "Exception caught: Parameter 3 is out of range (0-100)" << std::endl;
            else if (mark4 < 0 || mark4 > 100)
                std::cout << "Exception caught: Parameter 4 is out of range (0-100)" << std::endl;
        }

        std::cout << "Would you like to enter another set of marks for 4 courses (y/n)? ";
        std::cin >> choice;
    }

    std::cout << "Bye, see you next time." << std::endl;

    return 0;
}

