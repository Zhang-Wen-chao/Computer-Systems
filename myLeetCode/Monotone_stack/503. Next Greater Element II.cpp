// 503. Next Greater Element II
// https://leetcode.com/problems/next-greater-element-ii/

#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreaterElements(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, -1);
    std::stack<int> stk;

    for (int i = 0; i < 2 * n; i++) {
        int num = nums[i % n];
        while (!stk.empty() && num > nums[stk.top()]) {
            int index = stk.top();
            stk.pop();
            result[index] = num;
        }
        if (i < n) {
            stk.push(i);
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {1, 2, 1},
        {1, 2, 3, 4, 3},
        {5, 4, 3, 2, 1}
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::vector<int> nums = testCases[i];

        std::vector<int> result = nextGreaterElements(nums);

        std::cout << "Next greater elements: ";
        for (int j = 0; j < result.size(); j++) {
            std::cout << result[j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}