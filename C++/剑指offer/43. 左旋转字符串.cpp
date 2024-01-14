#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty() || n < 0 || n > str.size()) {
            return str;
        }
        // Move the first n characters to the end of the string
        string left = str.substr(0, n);
        string right = str.substr(n);
        return right + left;
    }
};

int main() {
    Solution solution;
    string str = "abcdefg";
    int n = 2;
    string rotatedStr = solution.LeftRotateString(str, n);
    cout << "The rotated string is: " << rotatedStr << endl;
    return 0;
}
