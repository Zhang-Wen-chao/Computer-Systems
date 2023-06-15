// 45. Jump Game II
// https://leetcode.com/problems/jump-game-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size(), jumps = 0, cur_end = 0, cur_farthest = 0;
    for (int i = 0; i < n - 1; i++) {
        cur_farthest = max(cur_farthest, i + nums[i]);
        if (i == cur_end) {
            jumps++;
            cur_end = cur_farthest;
        }
    }
    return jumps;
}

int main() {
    vector<int> nums1 = {2,3,1,1,4};
    vector<int> nums2 = {2,3,0,1,4};
    cout << "Example 1: " << jump(nums1) << endl;
    cout << "Example 2: " << jump(nums2) << endl;
}
