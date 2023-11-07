#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isNumeric(char* str) {
    if (str == nullptr) return false;

    // Check if there's a sign
    if (*str == '+' || *str == '-') ++str;

    bool numeric = true;
    bool hasDot = false;
    bool hasE = false;

    while (*str != '\0') {
        if (*str == '.') {
            if (hasDot || hasE) {
                numeric = false;
                break;
            }
            hasDot = true;
        } else if (*str == 'e' || *str == 'E') {
            if (hasE || *str == '\0') {
                numeric = false;
                break;
            }
            hasE = true;
            if (*(str + 1) == '+' || *(str + 1) == '-') ++str;
        } else if (!isdigit(*str)) {
            numeric = false;
            break;
        }
        ++str;
    }

    return numeric && *str == '\0';
}

int main() {
    char input[100];
    cout << "Enter a string to check if it's numeric: ";
    cin.getline(input, 100);

    if (isNumeric(input)) {
        cout << "The string \"" << input << "\" is numeric." << endl;
    } else {
        cout << "The string \"" << input << "\" is not numeric." << endl;
    }

    return 0;
}
