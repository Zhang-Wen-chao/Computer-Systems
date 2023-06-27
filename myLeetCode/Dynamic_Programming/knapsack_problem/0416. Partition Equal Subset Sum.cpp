// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};

int main() {
    vector<vector<int>> testCases = {{1, 5, 11, 5}, {1, 2, 3, 5}, {1, 2, 3, 4, 5, 6, 7}};
    Solution obj;
    for (auto& testCase: testCases) {
        cout << "For the array: [";
        for (int i = 0; i < testCase.size(); i++) {
            cout << testCase[i];
            if (i != testCase.size() - 1) {
                cout << ", ";
            }
        }
        cout << "], it is " << (obj.canPartition(testCase) ? "possible" : "not possible") << " to partition the array into two subsets such that the sum of elements in both subsets is equal." << endl;
    }
    return 0;
}