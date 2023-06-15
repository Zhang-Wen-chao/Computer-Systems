// 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/
#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<string>& res, string& path, string s, int start, int level) {
    if (level == 4) {
        if (start == s.size()) {
            res.push_back(path);
        }
        return;
    }
    for (int i = start; i < s.size() && i < start+3; i++) {
        if (i > start && s[start] == '0') {
            break;
        }
        string sub = s.substr(start, i-start+1);
        if (stoi(sub) > 255) {
            break;
        }
        if (level < 3) {
            path += sub + ".";
            backtrack(res, path, s, i+1, level+1);
            path.erase(path.size()-sub.size()-1);
        } else {
            path += sub;
            backtrack(res, path, s, i+1, level+1);
            path.erase(path.size()-sub.size());
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string path = "";
    backtrack(res, path, s, 0, 0);
    return res;
}

int main() {
    string s = "101023";
    vector<string> res = restoreIpAddresses(s);
    cout << "Input: \"" << s << "\"" << endl;
    cout << "Output: [";
    for (int i = 0; i < res.size()-1; i++) {
        cout << "\"" << res[i] << "\", ";
    }
    cout << "\"" << res[res.size()-1] << "\"]" << endl;
    return 0;
}
