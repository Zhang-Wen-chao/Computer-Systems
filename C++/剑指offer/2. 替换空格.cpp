#include <iostream>
#include <string>

// Function to replace spaces with "%20"
void replaceSpaces(std::string &str) {
    // Calculate the new length with replaced spaces
    int spaceCount = 0, len = str.length();
    for (char c : str) {
        if (c == ' ') spaceCount++;
    }
    int newLength = len + spaceCount * 2;

    // Resize the string to the final length and fill with placeholder characters
    str.resize(newLength, ' ');

    // Replace spaces from the end of the string
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[newLength - 1] = '0';
            str[newLength - 2] = '2';
            str[newLength - 3] = '%';
            newLength -= 3;
        } else {
            str[newLength - 1] = str[i];
            newLength -= 1;
        }
    }
}

int main() {
    std::string str = "We Are Happy";
    replaceSpaces(str);
    std::cout << str << std::endl;
    return 0;
}
