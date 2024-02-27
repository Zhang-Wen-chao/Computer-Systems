#include <iostream>

using namespace std;

// Function to add two numbers
int Add(int num1, int num2) {
    return num1 + num2;
}

int main() {
    int a, b;

    // Input two numbers
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;

    // Call the Add function and display the result
    int sum = Add(a, b);
    cout << "The sum of " << a << " and " << b << " is: " << sum << endl;

    return 0;
}
