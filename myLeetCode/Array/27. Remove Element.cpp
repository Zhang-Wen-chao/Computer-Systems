// 27. Remove Element
// https://leetcode.com/problems/remove-element/

#include <iostream>
#include <vector>

int removeElement(std::vector<int> &nums, int val) {
    int n = nums.size();
    int left = 0;
    for (int right = 0; right < n; right++) {
        if (nums[right] != val) {
            nums[left] = nums[right];
            left++;
        }
    }
    return left;
}

int main() {
    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int target = 2;
    int ans = removeElement(nums, target);

    std::cout << ans << std::endl;

    for (int i = 0; i < ans; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}