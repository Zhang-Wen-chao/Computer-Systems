/*
What is the output of the code as follows? What is the meaning of auto when defines a variable in C++?
You need to explain the reason to a SA to pass the test.

The output of the given code is 30.

Explanation:
In the code, the variable a is declared using the auto keyword. In C++, auto is used for automatic type deduction. It allows the compiler to automatically deduce the type of a variable based on its initializer.

In this case, the initializer for a is 10, which is an integer literal. Therefore, the compiler deduces that a should have an integer type.

Next, the code assigns the value 20.5 to a. Since a was deduced as an integer, the fractional part 0.5 is truncated, and a becomes 20.

The line a += 10.5 adds 10.5 to a. Since a is an integer, the fractional part 0.5 is again truncated, and a becomes 30.

Finally, the value of a is printed to the console using std::cout, resulting in the output 30.
*/

#include <iostream>

int main()
{
    auto a = 10;
    a = 20.5;
    a += 10.5;

    std::cout << a << std::endl;

    return 0;
    
}

// output is 30