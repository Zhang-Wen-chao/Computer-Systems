// 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <iostream>
#include <vector>
#include <stack>

int largestRectangleArea(std::vector<int>& heights) {
    int n = heights.size();
    if (n == 0) {
        return 0;
    }

    std::stack<int> stk;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];

        if (stk.empty() || h >= heights[stk.top()]) {
            stk.push(i);
        } else {
            int top = stk.top();
            stk.pop();
            maxArea = std::max(maxArea, heights[top] * (stk.empty() ? i : (i - stk.top() - 1)));
            i--;
        }
    }

    return maxArea;
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {2,1,5,6,2,3},
        {2,4},
        {0}
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::vector<int> heights = testCases[i];

        int result = largestRectangleArea(heights);

        std::cout << "Largest rectangle area for test case " << (i + 1) << ": " << result << std::endl;
    }

    return 0;
}