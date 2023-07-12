// 376. Wiggle Subsequence
// https://leetcode.com/problems/wiggle-subsequence/

#include <iostream>
#include <vector>

int wiggleMaxLength(std::vector<int>& nums) {
    int n = nums.size();
    if (n < 2) 
        return n;

    int up = 1; // 记录上升序列的长度
    int down = 1; // 记录下降序列的长度

    for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
            up = down + 1; // 如果当前数字比前一个数字大，更新上升序列的长度
        } else if (nums[i] < nums[i - 1]) {
            down = up + 1; // 如果当前数字比前一个数字小，更新下降序列的长度
        }
    }
    
    return std::max(up, down);
}

int main() {
    std::vector<int> nums = {1, 7, 4, 9, 2, 5};
    int maxLength = wiggleMaxLength(nums);
    std::cout << "Maximum wiggle subsequence length: " << maxLength << std::endl;

    std::vector<int> nums2 = {1,17,5,10,13,15,10,5,16,8};
    int maxLength2 = wiggleMaxLength(nums2);
    std::cout << "Maximum wiggle subsequence length: " << maxLength2 << std::endl;

    std::vector<int> nums3 = {1,2,3,4,5,6,7,8,9};
    int maxLength3 = wiggleMaxLength(nums3);
    std::cout << "Maximum wiggle subsequence length: " << maxLength3 << std::endl;

    return 0;
}