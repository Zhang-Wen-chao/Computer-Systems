// 704. Binary Search
// https://leetcode.com/problems/binary-search/

#include <iostream>
#include <vector>

class Solution {
  public:
    int search(std::vector<int> &nums, int target) {
        int left = 0, right = int(nums.size()) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    std::cout << sol.search(nums, target) << std::endl;
    return 0;
}