// 377. Combination Sum IV
// https://leetcode.com/problems/combination-sum-iv/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; i++) {
            for(int j=0; j<nums.size(); j++) {
                if(i >= nums[j]) {
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};



int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    int target = 4;
    cout << s.combinationSum4(nums, target) << endl;
    return 0;
}
