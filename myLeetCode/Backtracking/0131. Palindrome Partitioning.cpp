// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/
#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void backtrack(vector<vector<string>>& res, vector<string>& path, string s, int start) {
    if (start == s.size()) {
        res.push_back(path);
        return;
    }
    for (int i = start; i < s.size(); i++) {
        if (isPalindrome(s, start, i)) {
            path.push_back(s.substr(start, i-start+1));
            backtrack(res, path, s, i+1);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    backtrack(res, path, s, 0);
    return res;
}

int main() {
    string s = "aaba";
    vector<vector<string>> res = partition(s);
    cout << "Input: \"" << s << "\"" << endl;
    cout << "Output: " << endl;
    for (vector<string> path : res) {
        cout << "[";
        for (int i = 0; i < path.size()-1; i++) {
            cout << path[i] << ", ";
        }
        cout << path[path.size()-1] << "]" << endl;
    }
    return 0;
}
