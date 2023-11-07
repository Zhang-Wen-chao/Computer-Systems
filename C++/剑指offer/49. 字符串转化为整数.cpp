#include <iostream>
#include <string>
#include <cstdlib>  // For std::strtol
#include <climits>  // For INT_MIN and INT_MAX

using namespace std;

int StringToInt(const string& str) {
    char* end;
    long result = std::strtol(str.c_str(), &end, 10);

    // Check for conversion errors
    if (end == str.c_str()) {
        throw invalid_argument("No conversion could be performed");
    } else if (*end != '\0') {
        throw invalid_argument("The input string contains extra characters");
    } else if (result < INT_MIN || result > INT_MAX) {
        throw out_of_range("The input number is out of the range of an int");
    }

    return static_cast<int>(result);
}

int main() {
    string input;
    cout << "Enter a string to convert to an integer: ";
    cin >> input;

    try {
        int number = StringToInt(input);
        cout << "The integer is: " << number << endl;
    } catch (const invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cerr << "Out of range: " << e.what() << endl;
    }

    return 0;
}
