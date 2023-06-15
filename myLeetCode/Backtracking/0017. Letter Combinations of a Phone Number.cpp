// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<string> phone = {
    "",    // 0
    "",    // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs",// 7
    "tuv", // 8
    "wxyz" // 9
};

void dfs(string digits, int pos, string curr, vector<string>& ans) {
    if (pos == digits.length()) {
        ans.push_back(curr);
        return;
    }
    int d = digits[pos] - '0';
    for (int i = 0; i < phone[d].length(); i++) {
        dfs(digits, pos+1, curr+phone[d][i], ans);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.length() == 0) return ans;
    dfs(digits, 0, "", ans);
    return ans;
}

int main() {
    string digits = "26";
    vector<string> ans = letterCombinations(digits);
    cout << "Input: " << digits << endl;
    cout << "Output: ";
    for (string s : ans) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
