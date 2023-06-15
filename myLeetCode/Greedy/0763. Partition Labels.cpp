// 763. Partition Labels
// https://leetcode.com/problems/partition-labels/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> result;
    unordered_map<char, int> last;
    for (int i = 0; i < s.size(); i++) last[s[i]] = i;
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        end = max(end, last[s[i]]);
        if (i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return result;
}

// 测试
int main() {
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = partitionLabels(s);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
