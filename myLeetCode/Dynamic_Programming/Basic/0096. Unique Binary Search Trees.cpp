// 96. Unique Binary Search Trees
// https://leetcode.com/problems/unique-binary-search-trees/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.numTrees(n) << endl;
    return 0;
}

// 这个解决方案使用了动态规划的思想，用一个一维数组dp来存储子问题的解。dp[i]表示用i个节点可以构造的不同BST的个数。状态转移方程是：

// - 如果n==零或者n==一，那么dp[n]=一
// - 如果n>一，那么dp[n]=求和(dp[j-一]*dp[n-j])，其中j从一到n

// 最后返回dp[n].
