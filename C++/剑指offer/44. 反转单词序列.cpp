#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty()) return str;

        // Reverse the entire string
        reverse(str.begin(), str.end());

        // Reverse each word in the string
        size_t start = 0, end = 0;
        size_t len = str.length();
        while (start < len) {
            // Find the start of a word
            while (start < end || (start < len && str[start] == ' ')) start++;
            // Find the end of the word
            while (end < start || (end < len && str[end] != ' ')) end++;
            // Reverse the word
            reverse(str.begin() + start, str.begin() + end);
        }

        return str;
    }
};

int main() {
    Solution solution;
    string str = "I am a student.";
    string reversedStr = solution.ReverseSentence(str);
    cout << "The reversed sentence is: " << reversedStr << endl;
    return 0;
}
