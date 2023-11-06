// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>

int trap(std::vector<int>& height) {
    int n = height.size();
    if (n <= 2) {
        return 0;
    }

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }

    return water;
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {0,1,0,2,1,0,1,3,2,1,2,1},
        {4,2,0,3,2,5}
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::vector<int> height = testCases[i];

        int result = trap(height);

        std::cout << "Amount of trapped water for test case " << (i + 1) << ": " << result << std::endl;
    }

    return 0;
}