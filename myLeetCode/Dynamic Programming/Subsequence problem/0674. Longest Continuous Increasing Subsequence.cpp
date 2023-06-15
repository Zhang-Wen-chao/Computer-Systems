// 674. Longest Continuous Increasing Subsequence
// https://leetcode.com/problems/longest-continuous-increasing-subsequence/
// dp[i]：以下标i为结尾的连续递增的子序列长度为dp[i]**。


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int result = 1;
        vector<int> dp(nums.size() ,1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) { // 连续记录
                dp[i] = dp[i - 1] + 1;
            }
            if (dp[i] > result) result = dp[i];
        }
        return result;
    }
};

// Driver program to test above function
int main(){
    vector<int> arr{1,3,5,4,7};
    Solution s;
    cout << "Length of LCIS is " << s.findLengthOfLCIS(arr) << endl;
    return 0;
}