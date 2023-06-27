// 494. Target Sum
// https://leetcode.com/problems/target-sum/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum < target || (sum + target) % 2 == 1) return 0;
        int s = (sum + target) / 2;
        vector<int> dp(s + 1);
        dp[0] = 1;
        for (int num : nums) {
            for (int i = s; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        return dp[s];
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, x, target;
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    cout << sol.findTargetSumWays(nums, target) << endl;
    return 0;
}


// 这个解决方案使用了动态规划的思想，用一个一维数组dp来存储子问题的解。dp[i]表示用nums中的元素组成和为i的方案数。状态转移方程是：

// - 如果sum<target或者(sum+target)%2==一，那么返回零
// - 如果i==零，那么dp[零]=一
// - 如果i>=num，那么dp[i]+=dp[i-num]

// 最后返回dp[s]，其中s=(sum+target)/2。