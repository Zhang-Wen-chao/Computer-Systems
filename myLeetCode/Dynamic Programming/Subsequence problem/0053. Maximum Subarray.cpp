// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

// **dp[i]：包括下标i（以nums[i]为结尾）的最大连续子序列和为dp[i]**。

// dp[i]只有两个方向可以推出来：
// * dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
// * nums[i]，即：从头开始计算当前连续子序列和

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n); // dp[i] means the maximum subarray ending with nums[i];
        dp[0] = nums[0];
        int result = dp[0];
        
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式
            if (dp[i] > result) result = dp[i]; // result 保存dp[i]的最大值
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}

// 这个解决方案使用了动态规划的思想，用一个一维数组dp来存储子问题的解。dp[i]表示以nums[i]结尾的最大子数组的和。状态转移方程是：

// - 如果dp[i-1]>0，那么dp[i]=nums[i]+dp[i-1]
// - 如果dp[i-1]<=0，那么dp[i]=nums[i]

// 最后返回dp数组中的最大值。
