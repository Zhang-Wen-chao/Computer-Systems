// 239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/

#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::deque<int> dq;

    for (int i = 0; i < nums.size(); i++) {
        // 如果队列中的元素已经超出窗口的范围，需要移除队首元素
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // 移除队列尾部小于当前下标的元素，以保持队列单调递减
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // 将当前元素的索引加入队列尾部
        dq.push_back(i);

        // 如果已经形成一个完整的窗口，将队首元素（当前窗口的最大值）加入结果数组
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    std::vector<int> result = maxSlidingWindow(nums, k);

    std::cout << "Max sliding window: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
