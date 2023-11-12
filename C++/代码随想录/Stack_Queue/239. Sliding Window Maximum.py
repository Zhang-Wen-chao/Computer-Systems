from collections import deque

def maxSlidingWindow(nums, k):
    if not nums:
        return []

    window, result = deque(), []

    for i, num in enumerate(nums):
        # 移除窗口左边界之外的元素
        if i >= k and window[0] <= i - k:
            window.popleft()

        # 保持窗口内元素单调递减
        while window and nums[window[-1]] < num:
            window.pop()

        window.append(i)

        # 记录窗口的最大值
        if i >= k - 1:
            result.append(nums[window[0]])

    return result

# 测试用例
print(maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3))  # 输出: [3,3,5,5,6,7]
