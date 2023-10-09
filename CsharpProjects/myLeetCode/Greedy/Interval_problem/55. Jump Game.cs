// 55. Jump Game
// https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>

bool canJump(std::vector<int>& nums) {
    int cover = 0;
    if (nums.size() == 1) return true; // 只有一个元素，就是能达到
    for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
        cover = std::max(i + nums[i], cover);
        if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
    }
    return false;
}

int main() {
    std::vector<int> input1 = {2,3,1,1,4}; // Expected output:true
    std::cout << std::boolalpha << canJump(input1) << std::endl;

    std::vector<int> input2 = {3,2,1,0,4}; // Expected output:false
    std::cout << std::boolalpha << canJump(input2) << std::endl;

    return 0;
}