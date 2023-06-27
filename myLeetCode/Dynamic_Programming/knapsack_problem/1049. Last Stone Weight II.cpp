// 1049. Last Stone Weight II
//  https://leetcode.com/problems/last-stone-weight-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        int n = stones.size();
        vector<bool> dp(sum / 2 + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = sum / 2; j >= stones[i]; j--) {
                dp[j] = dp[j] || dp[j - stones[i]];
            }
        }
        for (int i = sum / 2; i >= 0; i--) {
            if (dp[i]) {
                return sum - 2 * i;
            }
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> testCases = {{2, 7, 4, 1, 8, 1}, {31, 26, 33, 21, 40}, {1, 2}};
    Solution obj;
    for (auto& testCase: testCases) {
        cout << "For the array: [";
        for (int i = 0; i < testCase.size(); i++) {
            cout << testCase[i];
            if (i != testCase.size() - 1) {
                cout << ", ";
            }
        }
        cout << "], the smallest possible difference between the sum of two subsets of the array is " << obj.lastStoneWeightII(testCase) << "." << endl;
    }
    return 0;
}