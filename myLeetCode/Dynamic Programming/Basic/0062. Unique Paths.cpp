// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

int main() {
    vector<pair<int, int>> testCases = {{3, 7}, {3, 2}, {7, 3}};
    Solution obj;
    for (auto& testCase: testCases) {
        cout << "For m = " << testCase.first << " and n = " << testCase.second << ", the number of unique paths is: " << obj.uniquePaths(testCase.first, testCase.second) << endl;
    }
    return 0;
}
