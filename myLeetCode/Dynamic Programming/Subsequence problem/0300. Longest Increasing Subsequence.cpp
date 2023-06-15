// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

// **dp[i]表示i之前包括i的以nums[i]结尾的最长递增子序列的长度** 
// A C++ program to find length of the longest increasing subsequence
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > result) result = dp[i]; // 取长的子序列
        }
        return result;
    }
};

// Driver program to test above function
int main(){
    // Input sequence
    vector<int> arr{10, 22, 9, 33, 21, 50, 41, 60};
    Solution s;
    // Output length of LIS
    cout << "Length of LIS is " << s.lengthOfLIS(arr) << endl;
    
    return 0;
}