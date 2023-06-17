/*
Write a program that uses a function template called Compare to compare the relationship between the values of the two arguments and return 1 when the first argument is greater than the second one; return -1 when the first argument is smaller than the second one, return 0 when the both values are equal. Test the program using integer, character and floating-point number arguments and print the result of the comparation.
If there is a structure as follows, how to define an explicit specialization of the template function Compare and print the result of the comparation?

*/

#include <iostream>
#include <string>

struct stuinfo {
    std::string name;
    int age;
};

template<typename T>
int Compare(const T& a, const T& b) {
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

// Explicit specialization for stuinfo structure
template<>
int Compare(const stuinfo& a, const stuinfo& b) {
    if (a.age > b.age)
        return 1;
    else if (a.age < b.age)
        return -1;
    else
        return 0;
}

int main() {
    // Comparing integers
    int intResult = Compare(5, 10);
    std::cout << "Integer comparison: " << intResult << std::endl;

    // Comparing characters
    char charResult = Compare('a', 'b');
    std::cout << "Character comparison: " << static_cast<int>(charResult) << std::endl;

    // Comparing floating-point numbers
    float floatResult = Compare(3.14f, 2.71f);
    std::cout << "Floating-point comparison: " << floatResult << std::endl;

    // Comparing stuinfo structures
    stuinfo student1{"John", 20};
    stuinfo student2{"Alice", 22};
    int stuResult = Compare(student1, student2);
    std::cout << "stuinfo structure comparison: " << stuResult << std::endl;

    return 0;
}
