// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/

// - 使用两个函数分别计算从第一个房屋到倒数第二个房屋，和从第二个房屋到最后一个房屋的最大抢劫金额。
// - 这两个函数都使用动态规划的思想，用一个数组dp存储每个位置的最大抢劫金额，状态转移方程为dp[i] = max(dp[i-1], dp[i-2] + nums[i])。
// - 最后返回这两个函数中较大的值作为答案。


// 引入头文件
#include <iostream>
#include <vector>
using namespace std;

// 计算从start到end范围内的最大抢劫金额
int robRange(vector<int>& nums, int start, int end) {
    // 如果范围为空，返回0
    if (start > end) return 0;
    // 如果范围只有一个元素，返回该元素
    if (start == end) return nums[start];
    // 初始化动态规划数组
    vector<int> dp(end - start + 1);
    // 边界条件
    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start+1]);
    // 状态转移方程
    for (int i = 2; i < dp.size(); i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[start+i]);
    }
    // 返回最后一个位置的值
    return dp.back();
}

// 计算环形街道上的最大抢劫金额
int rob(vector<int>& nums) {
    // 如果数组为空，返回0
    if (nums.empty()) return 0;
    // 如果数组只有一个元素，返回该元素
    if (nums.size() == 1) return nums[0];
    
   // 分别计算从第一个到倒数第二个，和从第二个到最后一个范围内的最大抢劫金额，并取较大值作为答案 
   return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
}

// 主函数：输入输出测试用例
int main() {
   vector<int> test_case_1 = {2,3,2};
   cout << "Test case 1: " << rob(test_case_1) << endl; // 输出3
   
   vector<int> test_case_2 = {1,2,3,1};
   cout << "Test case 2: " << rob(test_case_2) << endl; // 输出4
   
   vector<int> test_case_3 = {0};
   cout << "Test case 3: " << rob(test_case_3) << endl; // 输出0
   
   return 0;
}