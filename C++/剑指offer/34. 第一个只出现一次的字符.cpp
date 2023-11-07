#include <iostream>
#include <unordered_map>

using namespace std;

// 函数声明
char FirstNotRepeatingChar(string str);

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    char firstChar = FirstNotRepeatingChar(input);
    if (firstChar != '\0') {
        cout << "The first non-repeating character is: " << firstChar << endl;
    } else {
        cout << "There is no non-repeating character." << endl;
    }
    return 0;
}

// 函数定义
char FirstNotRepeatingChar(string str) {
    unordered_map<char, int> charCounts;
    for (char c : str) {
        charCounts[c]++;
    }

    for (char c : str) {
        if (charCounts[c] == 1) {
            return c;
        }
    }

    return '\0'; // 返回空字符表示没有找到
}
