// 349. Intersection of Two Arrays
// https://leetcode.cn/problems/intersection-of-two-arrays/

#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> resultSet;

    for (int num : nums2) {
        if (set1.count(num)) {
            resultSet.insert(num);
        }
    }

    return std::vector<int>(resultSet.begin(), resultSet.end());
}


int main() {
    // std::vector<int> nums1 = {1, 2, 2, 1};
    // std::vector<int> nums2 = {2, 2};
    std::vector<int> nums1 = {4,9,5};
    std::vector<int> nums2 = {9,4,9,8,4};
    std::vector<int> res = intersection(nums1, nums2);
    for (int i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}