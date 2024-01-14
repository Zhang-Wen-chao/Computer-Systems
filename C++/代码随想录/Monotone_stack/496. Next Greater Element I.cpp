// 496. Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_map<int, int> nextGreater;
    std::stack<int> stk;

    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!stk.empty() && nums2[i] > stk.top()) {
            stk.pop();
        }

        if (stk.empty()) {
            nextGreater[nums2[i]] = -1;
        } else {
            nextGreater[nums2[i]] = stk.top();
        }

        stk.push(nums2[i]);
    }

    std::vector<int> result;

    for (int i = 0; i < nums1.size(); i++) {
        result.push_back(nextGreater[nums1[i]]);
    }

    return result;
}

int main() {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> testCases = {
        {{4, 1, 2}, {1, 3, 4, 2}},
        {{2, 4}, {1, 2, 3, 4}}
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::vector<int> nums1 = testCases[i].first;
        std::vector<int> nums2 = testCases[i].second;

        std::vector<int> result = nextGreaterElement(nums1, nums2);

        std::cout << "Next greater elements for test case " << (i + 1) << ": ";
        for (int j = 0; j < result.size(); j++) {
            std::cout << result[j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}