// 1005. Maximize Sum Of Array After k Negations
// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

// * 第一步：将数组按照绝对值大小从大到小排序，**注意要按照绝对值的大小**
// * 第二步：从前向后遍历，遇到负数将其变为正数，同时k--
// * 第三步：如果k还大于0，那么反复转变数值最小的元素，将k用完
// * 第四步：求和
#include <iostream>
#include <vector>
#include <algorithm>

static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}

int largestSumAfterKNegations(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end(), cmp);       // 第一步
    for (int i = 0; i < nums.size(); i++) {      // 第二步
        if (nums[i] < 0 && k > 0) {
            nums[i] *= -1;
            k--;
        }
    }
    if (k % 2 == 1)
        nums[nums.size() - 1] *= -1;                // 第三步

    int result = 0;
    for (int num : nums)
        result += num;                          // 第四步

    return result;
}

int main() {
    std::vector<int> nums1 = {4, 2, 3};
    int k1 = 1;
    std::cout << largestSumAfterKNegations(nums1, k1) << std::endl;

    std::vector<int> nums2 = {3, -1, 0, 2};
    int k2 = 3;
    std::cout << largestSumAfterKNegations(nums2, k2) << std::endl;

    std::vector<int> nums3 = {2, -3, -1, 5, -4};
    int k3 = 2;
    std::cout << largestSumAfterKNegations(nums3, k3) << std::endl;

    return 0;
}
